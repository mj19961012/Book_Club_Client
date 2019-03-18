#ifndef BCCOMMONAPIDEF_HPP
#define BCCOMMONAPIDEF_HPP

#define BC_API_URL "http://api.sdyilianyi.com"
#define BC_API_LOGIN "/client/user/login"
#define BC_API_REGIST "/client/user/regist"



#define GET_API(X) API_URL X

#define OVERTIME 10000


#define json_get(V,J,N)                                             \
    do                                                              \
    {                                                               \
        if(J.find(#N)!=J.end() && !J[#N].is_null())                 \
        {                                                           \
                V = J[#N].get<decltype(V)>();                       \
        }                                                           \
    }while(0);

#endif  //BCCOMMONAPIDEF_HPP
