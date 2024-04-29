package com.terminus.planeta.file.ssl;

import android.util.Log;

import com.terminus.planeta.file.ConcurrentAsyncTask;
import com.terminus.planeta.file.account.Account;

import java.security.cert.X509Certificate;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * Save the ssl certificates the user has confirmed to trust
 */
public final class CertsManager {
    private static final String DEBUG_TAG = "CertsManager";

    private final CertsDBHelper db = CertsDBHelper.getDatabaseHelper();

    private final Map<Account, X509Certificate> cachedCerts = new ConcurrentHashMap<>();

    private static CertsManager instance;

    public static synchronized CertsManager instance() {
        if (instance == null) {
            instance = new CertsManager();
        }

        return instance;
    }

    public void saveCertForAccount(final Account account, boolean rememberChoice) {
        List<X509Certificate> certs = SSLTrustManager.instance().getCertsChainForAccount(account);
        if (certs == null || certs.size() == 0) {
            return;
        }

        final X509Certificate cert = certs.get(0);
        cachedCerts.put(account, cert);

        if (rememberChoice) {
            ConcurrentAsyncTask.submit(() -> db.saveCertificate(account.server, cert));
        }

        Log.d(DEBUG_TAG, "saved cert for account " + account);
    }

    public X509Certificate getCertificate(Account account) {
        X509Certificate cert = cachedCerts.get(account);
        if (cert != null) {
            return cert;
        }

        cert = db.getCertificate(account.server);
        if (cert != null) {
            cachedCerts.put(account, cert);
        }

        return cert;
    }
}