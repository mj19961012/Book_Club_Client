#ifndef BCCOMMONAPIDEF_HPP
#define BCCOMMONAPIDEF_HPP

#define BC_API_URL "http://192.168.1.3:8123"
#define BC_API_INIT_CITY "/init/city_dictionary"
#define BC_API_REGIST "/client/user/regist"
#define BC_API_LOGIN "/client/user/login"

#define BC_API_UPLOAD_SIMPLE_FILE "/clint/file/upload"
#define BC_API_GET_FILE_INFO "/clint/file/getinfo"
#define BC_API_DOWNLOAD_SIMPLE_FILE "/clint/file/download"

#define BC_API_GET_MESSAGE_LIST "/clint/message/get_list"
#define BC_API_SEND_MESSAGE "/clint/message/send_msg"

#define BC_API_GET_ARTICLES_LIST "/clint/article/get_list"
#define BC_API_RELEASE_ARTICLE "/clint/article/release"

#define BC_API_GET_ACTIVITIES_LIST "/clint/action/get_list"
#define BC_API_RELEASE_ACTION "/clint/action/release"

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
