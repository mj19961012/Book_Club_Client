#ifndef BCMESSAGEMANAHER_H
#define BCMESSAGEMANAHER_H
#include"BookClubEntity.hpp"
#include"BCCommonApiDef.hpp"
#include<QMap>
#include<QString>



class BCMessageManager
{
public :
    BCMessageManager();
    ~BCMessageManager();
    static BCMessageManager * getInstance();
    void BCLoginHandle(std::string username,std::string password);
    void BCSystemInit();
    QString BCHttpRequestHandle(QString requrl,QString parameter,QString contenttype = BC_CONTENTTYPE_HEADER);
public:
    QMap<QString,QMap<QString,QString>> mBCChildCityInfoMap;
    QMap<QString,QString> mBCParentCityInfoMap;
private:
    static BCMessageManager* mMessageManager;

    user_info current_user;
};

#endif // BCMESSAGEMANAHER_H
