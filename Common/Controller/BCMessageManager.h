#ifndef BCMESSAGEMANAHER_H
#define BCMESSAGEMANAHER_H

class BCMessageManager
{
public :
    BCMessageManager();
    ~BCMessageManager();
    static BCMessageManager * getInstance();
    void BCLoginHandle();
private:

};

#endif // BCMESSAGEMANAHER_H
