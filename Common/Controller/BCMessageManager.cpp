#include"BCMessageManager.h"

BCMessageManager* BCMessageManager::mMessageManager = nullptr;

BCMessageManager::BCMessageManager()
{

}

BCMessageManager::~BCMessageManager()
{

}

BCMessageManager * BCMessageManager::getInstance()
{
    if(mMessageManager == nullptr)
    {
        mMessageManager = new BCMessageManager;
        return mMessageManager;
    }
    return mMessageManager;
}

void BCMessageManager::BCLoginHandle(std::string username,std::string password)
{

}

