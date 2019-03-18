#include"BCMessageManager.h"

BCMessageManager::BCMessageManager()
{

}

BCMessageManager::~BCMessageManager()
{

}

BCMessageManager * BCMessageManager::getInstance()
{
    static BCMessageManager * instance = new BCMessageManager;
    if(instance != nullptr)
    {
        return instance;
    }
    else
    {
        instance = new BCMessageManager;
        return instance;
    }
}
