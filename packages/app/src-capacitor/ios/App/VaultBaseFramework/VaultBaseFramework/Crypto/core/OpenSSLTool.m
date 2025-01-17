//
//  OpenSSLTool.m
//  App
//
//  Created by gjm on 2023/2/15.
//

#import "OpenSSLTool.h"
#include "RSAFixed.h"
#include <openssl/pem.h>
#include <openssl/rsa.h>
#import <CommonCrypto/CommonCrypto.h>


#import <sys/socket.h>
#import <sys/sockio.h>
#import <sys/ioctl.h>
#import <net/if.h>
#import <arpa/inet.h>

#import <ifaddrs.h>
#import <arpa/inet.h>

@implementation OpenSSLTool

+ (RSA *)createRsaKeyWithPrivateKey:(NSString *) privateKey{
    
    NSRange spos = [privateKey rangeOfString:@"-----BEGIN RSA PRIVATE KEY-----"];
    NSRange epos = [privateKey rangeOfString:@"-----END RSA PRIVATE KEY-----"];
    if(spos.location != NSNotFound && epos.location != NSNotFound){
        NSUInteger s = spos.location + spos.length;
        NSUInteger e = epos.location;
        NSRange range = NSMakeRange(s, e-s);
        privateKey = [privateKey substringWithRange:range];
    }
    
    privateKey = [privateKey stringByReplacingOccurrencesOfString:@"\r" withString:@""];
    privateKey = [privateKey stringByReplacingOccurrencesOfString:@"\n" withString:@""];
    privateKey = [privateKey stringByReplacingOccurrencesOfString:@"\t" withString:@""];
    privateKey = [privateKey stringByReplacingOccurrencesOfString:@" "  withString:@""];
    
    NSMutableString * rsa_private_key = [[NSMutableString alloc]initWithString:privateKey];
    [rsa_private_key insertString:@"-----BEGIN RSA PRIVATE KEY-----\n" atIndex:0];
    [rsa_private_key appendString:@"\n-----END RSA PRIVATE KEY-----\n"];
    
    BIO *bio = NULL;
    const char * chPrivateKey =[rsa_private_key UTF8String];
    if ((bio = BIO_new_mem_buf(chPrivateKey, -1)) == NULL)
    {
        return nil;
    }
    
    RSA *rsa= PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
    
    return rsa;
    
}


+ (NSData *)decryptData:(NSData *)data withPrivateRSA:(RSA *)privateRSA {
    
    if (!privateRSA) {
        return nil;
    }
    
    int privateRSALenght = RSA_size(privateRSA);
    double totalLength = [data length];
    int blockSize = privateRSALenght;
    int blockCount = ceil(totalLength / blockSize);
    NSMutableData *decrypeData = [NSMutableData data];
    for (int i = 0; i < blockCount; i++) {
        NSUInteger loc = i * blockSize;
        long dataSegmentRealSize = MIN(blockSize, totalLength - loc);
        NSData *dataSegment = [data subdataWithRange:NSMakeRange(loc, dataSegmentRealSize)];
        const unsigned char *str = [dataSegment bytes];
        unsigned char *privateDecrypt = malloc(privateRSALenght);
        memset(privateDecrypt, 0, privateRSALenght);
        if(RSA_ossl_private_decrypt_sha256(privateRSALenght,str,privateDecrypt,privateRSA,RSA_PKCS1_OAEP_PADDING)>=0){
            NSInteger length =strlen((char *)privateDecrypt);
            NSData *data = [[NSData alloc] initWithBytes:privateDecrypt length:length];
            [decrypeData appendData:data];

        }
        free(privateDecrypt);
    }
    RSA_free(privateRSA);
    return decrypeData;
}


+ (NSData *) decryptString:(NSString *)encryptContent withPrivateKey:(NSString *)privateKey{
    //解密
    RSA *privateRSA=[self createRsaKeyWithPrivateKey:privateKey];
    NSData *encodeData = [[NSData alloc] initWithBase64EncodedString:encryptContent options:NSDataBase64DecodingIgnoreUnknownCharacters];
    
    NSData *data=[self decryptData:encodeData withPrivateRSA:privateRSA];
    return data;
}



+ (NSData *)pbkdf2WithPassword:(NSString *)Password salt:(NSData *)saltData iterations:(NSInteger)iterations keyLength:(NSInteger)keyLength {
    NSMutableData *key = [NSMutableData dataWithLength:keyLength];
    NSString *password = Password;
    
    int result = CCKeyDerivationPBKDF(kCCPBKDF2,         // algorithm
                                      password.UTF8String,                // password
                                      password.length,                    // passwordLength
                                      saltData.bytes,                         // salt
                                      saltData.length,                        // saltLen
                                      kCCPRFHmacAlgSHA256,                              // PRF
                                      (unsigned int)iterations,                 // rounds
                                      key.mutableBytes,            // derivedKey
                                      key.length);                 // derivedKeyLen

    
    return key;
}

+(NSString *)getIPAddress
{
    int sockfd = socket(AF_INET,SOCK_DGRAM, 0);
    NSMutableArray *ips = [NSMutableArray array];
    
    int BUFFERSIZE =4096;
    
    struct ifconf ifc;
    
    char buffer[BUFFERSIZE], *ptr, lastname[IFNAMSIZ], *cptr;
    
    struct ifreq *ifr, ifrcopy;
    
    ifc.ifc_len = BUFFERSIZE;
    
    ifc.ifc_buf = buffer;
    
    if (ioctl(sockfd,SIOCGIFCONF, &ifc) >= 0){
        
        for (ptr = buffer; ptr < buffer + ifc.ifc_len; ){
            
            ifr = (struct ifreq *)ptr;
            
            int len =sizeof(struct sockaddr);
            
            if (ifr->ifr_addr.sa_len > len) {
                len = ifr->ifr_addr.sa_len;
            }
            
            ptr += sizeof(ifr->ifr_name) + len;
            
            if (ifr->ifr_addr.sa_family !=AF_INET) continue;
            
            if ((cptr = (char *)strchr(ifr->ifr_name,':')) != NULL) *cptr =0;
            
            if (strncmp(lastname, ifr->ifr_name,IFNAMSIZ) == 0)continue;
            
            memcpy(lastname, ifr->ifr_name,IFNAMSIZ);
            
            ifrcopy = *ifr;
            
            ioctl(sockfd,SIOCGIFFLAGS, &ifrcopy);
            
            if ((ifrcopy.ifr_flags &IFF_UP) == 0)continue;
            
            NSString *ip = [NSString stringWithFormat:@"%s",inet_ntoa(((struct sockaddr_in *)&ifr->ifr_addr)->sin_addr)];
            [ips addObject:ip];
        }
    }
    close(sockfd);
    
    NSString *deviceIP =@"";
    
    for (int i=0; i < ips.count; i++){
        if (ips.count >0){
            deviceIP = [NSString stringWithFormat:@"%@",ips.lastObject];
        }
    }
    
    return deviceIP;
}

@end
