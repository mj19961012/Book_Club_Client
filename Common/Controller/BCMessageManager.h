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
<<<<<<< HEAD
=======
public:
    
>>>>>>> ba94bfbf6f3f606fcc2d107fa4a472550d297917
private:
    static BCMessageManager* mMessageManager;

    user_info current_user;
};

#endif // BCMESSAGEMANAHER_H
