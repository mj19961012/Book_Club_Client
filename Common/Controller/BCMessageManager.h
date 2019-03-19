#ifndef BCMESSAGEMANAHER_H
#define BCMESSAGEMANAHER_H
#include"BookClubEntity.hpp"

class BCMessageManager
{
public :
    BCMessageManager();
    ~BCMessageManager();
    static BCMessageManager * getInstance();
    void BCLoginHandle(std::string username,std::string password);
private:
    user_info current_user;
};

#endif // BCMESSAGEMANAHER_H
