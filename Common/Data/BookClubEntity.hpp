//
// Created by Jey on 2019/2/26.
//

#ifndef BOOKCLUBENTITY_HPP
#define BOOKCLUBENTITY_HPP

#include "nlohmann_json.hpp"
#include <string>
#include <QString>


struct user_info
{
    int id;
    std::string user_id;
    std::string phone_number;
    std::string nick_name;
    std::string pass_word;
    std::string school;
    std::string city;
    std::string head_image;
    int funs_number;
    int article_number;
    int action_number;
    friend void to_json(nlohmann::json &j,const user_info & user);
    friend void from_json(const nlohmann::json &j,user_info & user);

public:
    std::string getuserId() const;
    void setuserId(const std::string &value);
    std::string getphoneNumber() const;
    void setphoneNumber(const std::string &value);
    std::string getnickName() const;
    void setnickName(const std::string &value);
    std::string getpassWord() const;
    void setpassWord(const std::string &value);
    std::string getSchool() const;
    void setSchool(const std::string &value);
    std::string getCity() const;
    void setCity(const std::string &value);
    std::string getheadImage() const;
    void setheadImage(const std::string &value);
    int getfunsNumber() const;
    void setfunsNumber(int value);
    int getarticleNumber() const;
    void setarticleNumber(int value);
    int getactionNumber() const;
    void setactionNumber(int value);
};
struct article_info
{
    int id;
    std::string article_id;
    std::string article_title;
	std::string article_content;
	std::string author_id;
	int article_type;
	std::string release_time;
	int supporting_number;
	int page_view;
	int comment_number;

    friend void to_json(nlohmann::json &j,const article_info & article);
    friend void from_json(const nlohmann::json &j,article_info & article);

public:
    std::string getarticleId() const;
    void setarticleId(const std::string &value);
    std::string getarticleTitle() const;
    void setarticleTitle(const std::string &value);
    std::string getarticleContent() const;
    void setarticleContent(const std::string &value);
    std::string getauthorId() const;
    void setauthorId(const std::string &value);
    int getarticleType() const;
    void setarticleType(int value);
    std::string getreleaseTime() const;
    void setreleaseTime(const std::string &value);
    int getsupportingNumber() const;
    void setsupportingNumber(int value);
    int getpageView() const;
    void setpageView(int value);
    int getcommentNumber() const;
    void setcommentNumber(int value);
};

struct action_info
{
    int id;
    std::string action_id;
    std::string action_title;
    std::string action_content;
    std::string action_city;
    std::string begin_time;
    std::string end_time;
    std::string author_id;
    std::string first_file;
    std::string second_file;
    std::string third_file;
    std::string release_time;
    int page_view;

    friend void to_json(nlohmann::json &j,const action_info & action);
    friend void from_json(const nlohmann::json &j,action_info & action);

public:
    std::string getactionId() const;
    void setactionId(const std::string &value);
    std::string getactionTitle() const;
    void setactionTitle(const std::string &value);
    std::string getactionContent() const;
    void setactionContent(const std::string &value);
    std::string getactionCity() const;
    void setactionCity(const std::string &value);
    std::string getbeginTime() const;
    void setbeginTime(const std::string &value);
    std::string getendTime() const;
    void setendTime(const std::string &value);
    std::string getauthorId() const;
    void setauthorId(const std::string &value);
    std::string getfirstFile() const;
    void setfirstFile(const std::string &value);
    std::string getsecondFile() const;
    void setsecondFile(const std::string &value);
    std::string getthirdFile() const;
    void setthirdFile(const std::string &value);
    std::string getreleaseTime() const;
    void setreleaseTime(const std::string &value);
    int getpageView() const;
    void setpageView(int value);
};

struct message_info
{
    int id;
    std::string message_id;
    std::string messgae_body;
    std::string sender_id;
	std::string accepter_id;
	std::string session_id;
	std::string send_time;
	int message_state;
	int message_type;

	friend void to_json(nlohmann::json &j, const message_info & message);
	friend void from_json(const nlohmann::json &j, message_info & message);

public:
    std::string getmessageId() const;
    void setmessageId(const std::string &value);
    std::string getmessgaeBody() const;
    void setmessgaeBody(const std::string &value);
    std::string getsenderId() const;
    void setsenderId(const std::string &value);
    std::string getaccepterId() const;
    void setaccepterId(const std::string &value);
    std::string getsessionId() const;
    void setsessionId(const std::string &value);
    std::string getsendTime() const;
    void setsendTime(const std::string &value);
    int getmessageState() const;
    void setmessageState(int value);
    int getmessageType() const;
    void setmessageType(int value);
};
struct interest_list
{
    int id;
    std::string interest_id;
    std::string user_id;
    std::string follower_id;
	std::string date_subscribed;

    friend void to_json(nlohmann::json &j,const interest_list & interest);
    friend void from_json(const nlohmann::json &j,interest_list & interest);

public:
    std::string getinterestId() const;
    void setinterestId(const std::string &value);
    std::string getuserId() const;
    void setuserId(const std::string &value);
    std::string getfollowerId() const;
    void setfollowerId(const std::string &value);
    std::string getdateSubscribed() const;
    void setdateSubscribed(const std::string &value);
};

struct file_base_info
{
    int id;
    std::string file_md5;
    int file_size;
    int file_type;
    std::string local_path;

	friend void to_json(nlohmann::json &j, const file_base_info & file);
	friend void from_json(const nlohmann::json &j, file_base_info & file);

public:
    std::string getfileMd5() const;
    void setfileMd5(const std::string &value);
    int getfileSize() const;
    void setfileSize(int value);
    int getfileType() const;
    void setfileType(int value);
    std::string getlocalPath() const;
    void setlocalPath(const std::string &value);
};
#endif //BOOKCLUBENTITY_HPP
