//
// Created by Jey on 2019/2/26.
//

#ifndef BOOKCLUBENTITY_HPP
#define BOOKCLUBENTITY_HPP

#include "nlohmann_json.hpp"
#include <string>


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
    std::string first_file;
    std::string second_file;
    std::string third_file;

    friend void to_json(nlohmann::json &j,const article_info & article);
    friend void from_json(const nlohmann::json &j,article_info & article);
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

    friend void to_json(nlohmann::json &j,const message_info & message);
    friend void from_json(const nlohmann::json &j,message_info & message);
};
struct interest_list
{
    int id;
    std::string user_id;
    std::string follower_id;
    std::string date_subscribed;

    friend void to_json(nlohmann::json &j,const interest_list & interest);
    friend void from_json(const nlohmann::json &j,interest_list & interest);
};
#endif //BOOKCLUBENTITY_HPP
