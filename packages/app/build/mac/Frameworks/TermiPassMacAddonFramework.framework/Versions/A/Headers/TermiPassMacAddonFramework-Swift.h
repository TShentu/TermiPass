#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.10 (swiftlang-5.10.0.13 clang-1500.3.9.4)
#ifndef TERMIPASSMACADDONFRAMEWORK_SWIFT_H
#define TERMIPASSMACADDONFRAMEWORK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="TermiPassMacAddonFramework",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)

@class NETunnelProviderManager;
enum Status : NSInteger;
@class NSString;
enum LocalVpnSDKStatus : NSInteger;

SWIFT_CLASS("_TtC26TermiPassMacAddonFramework19TermiPassVpnManager")
@interface TermiPassVpnManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) TermiPassVpnManager * _Nonnull shared;)
+ (TermiPassVpnManager * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, strong) NETunnelProviderManager * _Nullable tunnel;
@property (nonatomic, copy) void (^ _Nullable statusDidChangeHandler)(enum Status);
@property (nonatomic, copy) NSString * _Nonnull connectNodeInfo;
@property (nonatomic, readonly) enum Status status;
@property (nonatomic) enum LocalVpnSDKStatus localVpnSdkStatus;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
- (void)openVpn:(NSString * _Nonnull)serverUrl :(NSString * _Nonnull)authKey :(NSString * _Nonnull)cookies;
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
@end


SWIFT_CLASS("_TtCC26TermiPassMacAddonFramework19TermiPassVpnManager6Config")
@interface Config : NSObject
- (nonnull instancetype)initWithHostname:(NSString * _Nonnull)hostname serverName:(NSString * _Nonnull)serverName localizedDescription:(NSString * _Nonnull)localizedDescription OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
@end

typedef SWIFT_ENUM(NSInteger, Status, closed) {
  StatusOff = 0,
  StatusOn = 1,
  StatusInvalid = 2,
/// The VPN is not configured
  StatusConnecting = 3,
  StatusDisconnecting = 4,
};


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
+ (NSString * _Nonnull)localVpnSDKToStringWithVpnStatus:(enum LocalVpnSDKStatus)vpnStatus SWIFT_WARN_UNUSED_RESULT;
@end

typedef SWIFT_ENUM(NSInteger, LocalVpnSDKStatus, closed) {
  LocalVpnSDKStatusNoState = 0,
  LocalVpnSDKStatusInUseOtherUser = 1,
  LocalVpnSDKStatusNeedsLogin = 2,
/// The VPN is not configured
  LocalVpnSDKStatusNeedsMachineAuth = 3,
  LocalVpnSDKStatusStopped = 4,
  LocalVpnSDKStatusStarting = 5,
  LocalVpnSDKStatusRunning = 6,
};

@class NSError;

@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
- (void)isVpnPreparedWithCompletion:(void (^ _Nonnull)(BOOL))completion;
- (void)startWith:(Config * _Nonnull)config completion:(void (^ _Nonnull)(NSError * _Nullable))completion;
- (void)start:(void (^ _Nonnull)(NSError * _Nullable))completion;
- (void)stop;
- (void)loadTunnelManager:(void (^ _Nonnull)(NETunnelProviderManager * _Nullable, NSError * _Nullable))complition;
- (NETunnelProviderManager * _Nonnull)makeTunnelManagerWith:(Config * _Nonnull)config SWIFT_WARN_UNUSED_RESULT;
- (void)saveToPreferencesWith:(Config * _Nullable)config completion:(void (^ _Nonnull)(NSError * _Nullable))completion;
- (void)notifyStatusDidChange;
- (void)updateStatus;
- (void)refreshWithCompletion:(void (^ _Nullable)(NSError * _Nullable))completion;
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didChangeStatusNotification;)
+ (NSString * _Nonnull)didChangeStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didReceiveOpenUrlNotification;)
+ (NSString * _Nonnull)didReceiveOpenUrlNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didUpdateLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)didUpdateLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didInitLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)didInitLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull closeLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)closeLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull openLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)openLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull getPeersStateSDKStatusNotification;)
+ (NSString * _Nonnull)getPeersStateSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
@end

@class NSData;

@interface NSUserDefaults (SWIFT_EXTENSION(TermiPassMacAddonFramework))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull vpnAppGroupId;)
+ (NSString * _Nonnull)vpnAppGroupId SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) NSUserDefaults * _Nullable vpnUserDefault;)
+ (NSUserDefaults * _Nullable)vpnUserDefault SWIFT_WARN_UNUSED_RESULT;
+ (void)writeTemporaryDataWithKey:(NSString * _Nonnull)key value:(id _Nonnull)value;
+ (id _Nullable)readTemporaryDataWithKey:(NSString * _Nonnull)key SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)getAppExtensionContainerURL SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)getNodeInfo SWIFT_WARN_UNUSED_RESULT;
+ (NSData * _Nullable)decodeUrlSafeBase64:(NSString * _Nonnull)value error:(NSError * _Nullable * _Nullable)error SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC26TermiPassMacAddonFramework15VPNTemporaryKey")
@interface VPNTemporaryKey : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_update_vpn_status;)
+ (NSString * _Nonnull)temporaryKey_update_vpn_status SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_update_vpn_status:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_open_url;)
+ (NSString * _Nonnull)temporaryKey_open_url SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_open_url:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_server_url;)
+ (NSString * _Nonnull)temporaryKey_server_url SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_server_url:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_server_authkey;)
+ (NSString * _Nonnull)temporaryKey_server_authkey SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_server_authkey:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_cookies;)
+ (NSString * _Nonnull)temporaryKey_cookies SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_cookies:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_sdk_status;)
+ (NSString * _Nonnull)temporaryKey_sdk_status SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_sdk_status:(NSString * _Nonnull)value;
/// other node info
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_sdk_nodes_status;)
+ (NSString * _Nonnull)temporaryKey_sdk_nodes_status SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_sdk_nodes_status:(NSString * _Nonnull)value;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#elif defined(__x86_64__) && __x86_64__
// Generated by Apple Swift version 5.10 (swiftlang-5.10.0.13 clang-1500.3.9.4)
#ifndef TERMIPASSMACADDONFRAMEWORK_SWIFT_H
#define TERMIPASSMACADDONFRAMEWORK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="TermiPassMacAddonFramework",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)

@class NETunnelProviderManager;
enum Status : NSInteger;
@class NSString;
enum LocalVpnSDKStatus : NSInteger;

SWIFT_CLASS("_TtC26TermiPassMacAddonFramework19TermiPassVpnManager")
@interface TermiPassVpnManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) TermiPassVpnManager * _Nonnull shared;)
+ (TermiPassVpnManager * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, strong) NETunnelProviderManager * _Nullable tunnel;
@property (nonatomic, copy) void (^ _Nullable statusDidChangeHandler)(enum Status);
@property (nonatomic, copy) NSString * _Nonnull connectNodeInfo;
@property (nonatomic, readonly) enum Status status;
@property (nonatomic) enum LocalVpnSDKStatus localVpnSdkStatus;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
- (void)openVpn:(NSString * _Nonnull)serverUrl :(NSString * _Nonnull)authKey :(NSString * _Nonnull)cookies;
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
@end


SWIFT_CLASS("_TtCC26TermiPassMacAddonFramework19TermiPassVpnManager6Config")
@interface Config : NSObject
- (nonnull instancetype)initWithHostname:(NSString * _Nonnull)hostname serverName:(NSString * _Nonnull)serverName localizedDescription:(NSString * _Nonnull)localizedDescription OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
@end

typedef SWIFT_ENUM(NSInteger, Status, closed) {
  StatusOff = 0,
  StatusOn = 1,
  StatusInvalid = 2,
/// The VPN is not configured
  StatusConnecting = 3,
  StatusDisconnecting = 4,
};


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
+ (NSString * _Nonnull)localVpnSDKToStringWithVpnStatus:(enum LocalVpnSDKStatus)vpnStatus SWIFT_WARN_UNUSED_RESULT;
@end

typedef SWIFT_ENUM(NSInteger, LocalVpnSDKStatus, closed) {
  LocalVpnSDKStatusNoState = 0,
  LocalVpnSDKStatusInUseOtherUser = 1,
  LocalVpnSDKStatusNeedsLogin = 2,
/// The VPN is not configured
  LocalVpnSDKStatusNeedsMachineAuth = 3,
  LocalVpnSDKStatusStopped = 4,
  LocalVpnSDKStatusStarting = 5,
  LocalVpnSDKStatusRunning = 6,
};

@class NSError;

@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
- (void)isVpnPreparedWithCompletion:(void (^ _Nonnull)(BOOL))completion;
- (void)startWith:(Config * _Nonnull)config completion:(void (^ _Nonnull)(NSError * _Nullable))completion;
- (void)start:(void (^ _Nonnull)(NSError * _Nullable))completion;
- (void)stop;
- (void)loadTunnelManager:(void (^ _Nonnull)(NETunnelProviderManager * _Nullable, NSError * _Nullable))complition;
- (NETunnelProviderManager * _Nonnull)makeTunnelManagerWith:(Config * _Nonnull)config SWIFT_WARN_UNUSED_RESULT;
- (void)saveToPreferencesWith:(Config * _Nullable)config completion:(void (^ _Nonnull)(NSError * _Nullable))completion;
- (void)notifyStatusDidChange;
- (void)updateStatus;
- (void)refreshWithCompletion:(void (^ _Nullable)(NSError * _Nullable))completion;
@end


@interface TermiPassVpnManager (SWIFT_EXTENSION(TermiPassMacAddonFramework))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didChangeStatusNotification;)
+ (NSString * _Nonnull)didChangeStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didReceiveOpenUrlNotification;)
+ (NSString * _Nonnull)didReceiveOpenUrlNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didUpdateLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)didUpdateLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull didInitLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)didInitLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull closeLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)closeLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull openLocalVpnSDKStatusNotification;)
+ (NSString * _Nonnull)openLocalVpnSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull getPeersStateSDKStatusNotification;)
+ (NSString * _Nonnull)getPeersStateSDKStatusNotification SWIFT_WARN_UNUSED_RESULT;
@end

@class NSData;

@interface NSUserDefaults (SWIFT_EXTENSION(TermiPassMacAddonFramework))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull vpnAppGroupId;)
+ (NSString * _Nonnull)vpnAppGroupId SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) NSUserDefaults * _Nullable vpnUserDefault;)
+ (NSUserDefaults * _Nullable)vpnUserDefault SWIFT_WARN_UNUSED_RESULT;
+ (void)writeTemporaryDataWithKey:(NSString * _Nonnull)key value:(id _Nonnull)value;
+ (id _Nullable)readTemporaryDataWithKey:(NSString * _Nonnull)key SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)getAppExtensionContainerURL SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)getNodeInfo SWIFT_WARN_UNUSED_RESULT;
+ (NSData * _Nullable)decodeUrlSafeBase64:(NSString * _Nonnull)value error:(NSError * _Nullable * _Nullable)error SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC26TermiPassMacAddonFramework15VPNTemporaryKey")
@interface VPNTemporaryKey : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_update_vpn_status;)
+ (NSString * _Nonnull)temporaryKey_update_vpn_status SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_update_vpn_status:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_open_url;)
+ (NSString * _Nonnull)temporaryKey_open_url SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_open_url:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_server_url;)
+ (NSString * _Nonnull)temporaryKey_server_url SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_server_url:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_server_authkey;)
+ (NSString * _Nonnull)temporaryKey_server_authkey SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_server_authkey:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_cookies;)
+ (NSString * _Nonnull)temporaryKey_cookies SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_cookies:(NSString * _Nonnull)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_sdk_status;)
+ (NSString * _Nonnull)temporaryKey_sdk_status SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_sdk_status:(NSString * _Nonnull)value;
/// other node info
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull temporaryKey_sdk_nodes_status;)
+ (NSString * _Nonnull)temporaryKey_sdk_nodes_status SWIFT_WARN_UNUSED_RESULT;
+ (void)setTemporaryKey_sdk_nodes_status:(NSString * _Nonnull)value;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif
