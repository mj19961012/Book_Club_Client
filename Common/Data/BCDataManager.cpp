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

const QString &BCDataManager::getUserHeadImgPath()
{
    QDir tempDir;
    tempDir.setPath(mUserHeadImgPath);
    if(!tempDir.exists(mUserHeadImgPath))
    {
        tempDir.mkpath(mUserHeadImgPath);
    }
    return mUserHeadImgPath;
}

BCDataManager::BCDataManager()
{
    mUserHeadImgPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
}
