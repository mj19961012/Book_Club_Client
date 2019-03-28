#ifndef BCCOMMONAPIDEF_HPP
#define BCCOMMONAPIDEF_HPP

#define BC_API_URL "http://192.168.1.3:8123"
#define BC_API_INIT_CITY "/init/city_dictionary"
#define BC_API_REGIST "/client/user/regist"
#define BC_API_LOGIN "/client/user/login"

#define BC_CONTENTTYPE_HEADER "application/x-www-form-urlencoded"

#define GET_API(X) BC_API_URL X

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
