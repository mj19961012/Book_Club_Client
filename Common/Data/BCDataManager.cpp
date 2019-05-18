#include "BCDataManager.h"
#include <QStandardPaths>
#include <QDir>

BCDataManager *BCDataManager::sDataManager = nullptr;

BCDataManager &BCDataManager::instance()
{
    if(!sDataManager)
    {
        sDataManager = new BCDataManager;
    }
    return *sDataManager;
}

void BCDataManager::release()
{
    if(sDataManager)
    {
        delete sDataManager;
        sDataManager = nullptr;
    }
}

const QString &BCDataManager::getAppDataPath()
{
    QDir tempDir;
    tempDir.setPath(mAppDataPath);
    if(!tempDir.exists(mAppDataPath))
    {
        tempDir.mkpath(mAppDataPath);
    }
    return mAppDataPath;
}

BCDataManager::BCDataManager(QObject *parent)
    :QObject (parent)
{
    mAppDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
}
