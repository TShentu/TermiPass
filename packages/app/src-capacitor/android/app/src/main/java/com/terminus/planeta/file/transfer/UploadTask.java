package com.terminus.planeta.file.transfer;

import android.util.Log;
import android.widget.Toast;

import com.terminus.planeta.R;
import com.terminus.planeta.VaultApp;
import com.terminus.planeta.file.SeafException;
import com.terminus.planeta.file.SettingsManager;
import com.terminus.planeta.file.Utils;
import com.terminus.planeta.file.account.Account;
import com.terminus.planeta.file.data.DataManager;
import com.terminus.planeta.file.data.ProgressMonitor;

import java.io.File;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;

/**
 * Upload task
 */
public class UploadTask extends TransferTask {
    public static final String DEBUG_TAG = "UploadTask";

    private String dir;   // parent dir
    private boolean isUpdate;  // true if update an existing file
    private boolean isCopyToLocal; // false to turn off copy operation
    private boolean byBlock;
    private UploadStateListener uploadStateListener;
    private String source;

    private DataManager dataManager;

    public UploadTask(String source, int taskID, Account account, String repoID, String repoName,
                      String dir, String filePath, boolean isUpdate, boolean isCopyToLocal, boolean byBlock,
                      UploadStateListener uploadStateListener) {
        super(source, taskID, account, repoName, repoID, filePath);
        this.dir = dir;
        this.isUpdate = isUpdate;
        this.isCopyToLocal = isCopyToLocal;
        this.byBlock = byBlock;
        this.uploadStateListener = uploadStateListener;
        this.totalSize = new File(filePath).length();
        this.finished = 0;
        this.dataManager = new DataManager(account);
        this.source = source;
    }

    public UploadTaskInfo getTaskInfo() {
        UploadTaskInfo info = new UploadTaskInfo(account, taskID, state, repoID,
                repoName, dir, path, isUpdate, isCopyToLocal,
                finished, totalSize, err);
        return info;
    }

    public void cancelUpload() {
        if (state != TaskState.INIT && state != TaskState.TRANSFERRING) {
            return;
        }
        state = TaskState.CANCELLED;
        super.cancel(true);
    }

    @Override
    protected void onPreExecute() {
        state = TaskState.TRANSFERRING;
    }

    @Override
    protected void onProgressUpdate(Long... values) {
        long uploaded = values[0];
        // Log.d(DEBUG_TAG, "Uploaded " + uploaded);
        this.finished = uploaded;
        uploadStateListener.onFileUploadProgress(taskID);
    }

    @Override
    protected File doInBackground(Void... params) {
        try {
            ProgressMonitor monitor = new ProgressMonitor() {
                @Override
                public void onProgressNotify(long uploaded, boolean updateTotal) {
                    publishProgress(uploaded);
                }

                @Override
                public boolean isCancelled() {
                    return UploadTask.this.isCancelled();
                }
            };

            if (byBlock) {
                dataManager.uploadByBlocks(repoName, repoID, dir, path, monitor, isUpdate, isCopyToLocal);
            } else {
                dataManager.uploadFile(repoName, repoID, dir, path, monitor, isUpdate, isCopyToLocal);
            }

        } catch (SeafException e) {
            Log.e(DEBUG_TAG, "Upload exception " + e.getCode() + " " + e.getMessage());
            e.printStackTrace();
            err = e;
        } catch (NoSuchAlgorithmException | IOException e) {
            Log.e(DEBUG_TAG, "Upload exception " + e.getMessage());
            err = SeafException.unknownException;
            e.printStackTrace();
        }

        return null;
    }

    @Override
    protected void onPostExecute(File file) {
        state = err == null ? TaskState.FINISHED : TaskState.FAILED;
        if (uploadStateListener != null) {
            if (err == null) {
                SettingsManager.instance().saveUploadCompletedTime(Utils.getSyncCompletedTime());
                uploadStateListener.onFileUploaded(taskID);
            } else {
                if (err.getCode() == SeafException.HTTP_ABOVE_QUOTA) {
                    Toast.makeText(VaultApp.Companion.getApplication(), R.string.above_quota, Toast.LENGTH_SHORT).show();
                }
                uploadStateListener.onFileUploadFailed(taskID);
            }
        }
    }

    @Override
    protected void onCancelled() {
        if (uploadStateListener != null) {
            uploadStateListener.onFileUploadCancelled(taskID);
        }
    }

    public String getDir() {
        return dir;
    }

    public boolean isCopyToLocal() {
        return isCopyToLocal;
    }

    public boolean isUpdate() {
        return isUpdate;
    }

}