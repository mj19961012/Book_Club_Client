//
// Created by Jey on 2019/3/16.
//

#include "BookClubEntity.hpp"

void to_json(nlohmann::json &j,const user_info & user)
{
    j = nlohmann::json{
            {"id",user.id},
            {"user_id",user.user_id},
            {"phone_number",user.phone_number},
            {"pass_word",user.pass_word},
            {"nick_name",user.nick_name},
            {"school",user.school},
            {"city",user.city},
            {"head_image",user.head_image},
            {"funs_number",user.funs_number},
            {"article_number",user.article_number},
            {"action_number",user.action_number}
    };
}

void from_json(const nlohmann::json &j,user_info & user)
{
    if(j.find("id") != j.end())
    {
        user.id = j["id"].get<int>();
    }
    if(j.find("phone_number") != j.end())
    {
        user.phone_number = j["phone_number"].get<std::string>();
    }
    if(j.find("user_id") != j.end())
    {
        user.user_id = j["user_id"].get<std::string>();
    }
    if(j.find("pass_word") != j.end())
    {
        user.pass_word = j["pass_word"].get<std::string>();
    }
    if(j.find("nick_name") != j.end())
    {
        user.nick_name = j["nick_name"].get<std::string>();
    }
    if(j.find("school") != j.end())
    {
        user.school = j["school"].get<std::string>();
    }
    if(j.find("city") != j.end())
    {
        user.city = j["city"].get<std::string>();
    }
    if(j.find("funs_number") != j.end())
    {
        user.funs_number = j["funs_number"].get<int>();
    }
    if(j.find("article_number") != j.end())
    {
        user.article_number = j["article_number"].get<int>();
    }
    if(j.find("action_number") != j.end())
    {
        user.action_number = j["action_number"].get<int>();
    }
}

void to_json(nlohmann::json &j,const article_info & article)
{
    j = nlohmann::json{
            {"id",article.id},
            {"article_id",article.article_id},
            {"article_title",article.article_title},
            {"article_content",article.article_content},
            {"author_id",article.author_id},
            {"article_type",article.article_type},
            {"release_time",article.release_time},
            {"supporting_number",article.supporting_number},
            {"page_view",article.page_view},
            {"comment_number",article.comment_number},
    };
}

void from_json(const nlohmann::json &j,article_info & article)
{
    if(j.find("id") != j.end())
    {
        article.id = j["id"].get<int>();
    }
    if(j.find("article_id") != j.end())
    {
        article.article_id = j["article_id"].get<std::string>();
    }
    if(j.find("article_title") != j.end())
    {
        article.article_title = j["article_title"].get<std::string>();
    }
    if(j.find("article_content") != j.end())
    {
        article.article_content = j["article_content"].get<std::string>();
    }
    if(j.find("article_type") != j.end())
    {
        article.article_type = j["article_type"].get<int>();
    }
    if(j.find("release_time") != j.end())
    {
        article.release_time = j["release_time"].get<std::string>();
    }
    if(j.find("supporting_number") != j.end())
    {
        article.supporting_number = j["supporting_number"].get<int>();
    }
    if(j.find("page_view") != j.end())
    {
        article.page_view = j["page_view"].get<int>();
    }
    if(j.find("comment_number") != j.end())
    {
        article.comment_number = j["comment_number"].get<int>();
    }
}

void to_json(nlohmann::json &j,const action_info & action)
{
    j = nlohmann::json{
            {"id",action.id},
            {"action_id",action.action_id},
            {"action_title",action.action_title},
            {"action_content",action.action_content},
            {"action_city",action.action_city},
            {"begin_time",action.begin_time},
            {"end_time",action.end_time},
            {"author_id",action.author_id},
            {"first_file",action.first_file},
            {"second_file",action.second_file},
            {"third_file",action.third_file},
            {"release_time",action.release_time},
            {"page_view",action.page_view}
    };
}

void from_json(const nlohmann::json &j,action_info & action)
{
    if(j.find("id") != j.end())
    {
        action.id = j["id"].get<int>();
    }
    if(j.find("article_id") != j.end())
    {
        action.action_id = j["action_id"].get<std::string>();
    }
    if(j.find("action_title") != j.end())
    {
        action.action_title = j["action_title"].get<std::string>();
    }
    if(j.find("action_content") != j.end())
    {
        action.action_content = j["action_content"].get<std::string>();
    }
    if(j.find("action_city") != j.end())
    {
        action.action_city = j["action_city"].get<std::string>();
    }
    if(j.find("begin_time") != j.end())
    {
        action.begin_time = j["begin_time"].get<std::string>();
    }
    if(j.find("end_time") != j.end())
    {
        action.end_time = j["end_time"].get<std::string>();
    }
    if(j.find("author_id") != j.end())
    {
        action.author_id = j["author_id"].get<std::string>();
    }
    if(j.find("first_file") != j.end())
    {
        action.first_file = j["first_file"].get<std::string>();
    }
    if(j.find("second_file") != j.end())
    {
        action.second_file = j["second_file"].get<std::string>();
    }
    if(j.find("third_file") != j.end())
    {
        action.third_file = j["third_file"].get<std::string>();
    }
    if(j.find("release_time") != j.end())
    {
        action.release_time = j["release_time"].get<std::string>();
    }
    if(j.find("page_view") != j.end())
    {
        action.page_view = j["page_view"].get<int>();
    }
}

void to_json(nlohmann::json &j,const message_info & message)
{
    j = nlohmann::json{
            {"id",message.id},
            {"message_id",message.message_id},
            {"messgae_body",message.messgae_body},
            {"sender_id",message.sender_id},
            {"accepter_id",message.accepter_id},
            {"session_id",message.session_id},
            {"send_time",message.send_time},
            {"message_state",message.message_state}
    };
}

void from_json(const nlohmann::json &j,message_info & message)
{
    if(j.find("id") != j.end())
    {
        message.id = j["id"].get<int>();
    }
    if(j.find("message_id") != j.end())
    {
        message.message_id = j["message_id"].get<std::string>();
    }
    if(j.find("messgae_body") != j.end())
    {
        message.messgae_body = j["messgae_body"].get<std::string>();
    }
    if(j.find("sender_id") != j.end())
    {
        message.sender_id = j["sender_id"].get<std::string>();
    }
    if(j.find("accepter_id") != j.end())
    {
        message.accepter_id = j["accepter_id"].get<std::string>();
    }
    if(j.find("session_id") != j.end())
    {
        message.session_id = j["session_id"].get<std::string>();
    }
    if(j.find("send_time") != j.end())
    {
        message.send_time = j["send_time"].get<std::string>();
    }
    if(j.find("message_state") != j.end())
    {
        message.message_state = j["message_state"].get<int>();
    }
	if (j.find("message_type") != j.end())
	{
		message.message_type = j["message_type"].get<int>();
	}
}

void to_json(nlohmann::json &j, const interest_list & interest)
{
	j = nlohmann::json{
		{ "id",interest.id },
		{ "interest_id",interest.interest_id },
		{ "user_id",interest.user_id },
		{ "follower_id",interest.follower_id },
		{ "date_subscribed",interest.date_subscribed }
	};
}

void from_json(const nlohmann::json &j, interest_list & interest)
{
	if (j.find("id") != j.end())
	{
		interest.id = j["id"].get<int>();
	}
	if (j.find("interest_id") != j.end())
	{
		interest.interest_id = j["interest_id"].get<std::string>();
	}
	if (j.find("user_id") != j.end())
	{
		interest.user_id = j["user_id"].get<std::string>();
	}
	if (j.find("follower_id") != j.end())
	{
		interest.follower_id = j["follower_id"].get<std::string>();
	}
	if (j.find("date_subscribed") != j.end())
	{
		interest.date_subscribed = j["date_subscribed"].get<std::string>();
	}
}

void to_json(nlohmann::json &j, const file_base_info & file)
{
	j = nlohmann::json{
		{ "id",file.id },
		{ "file_md5",file.file_md5 },
		{ "file_size",file.file_size },
		{ "file_type",file.file_type },
		{ "local_path",file.local_path }
	};
}
void from_json(const nlohmann::json &j, file_base_info & file)
{
	if (j.find("id") != j.end())
	{
		file.id = j["id"].get<int>();
	}
	if (j.find("file_md5") != j.end())
	{
		file.file_md5 = j["file_md5"].get<std::string>();
	}
	if (j.find("file_size") != j.end())
	{
		file.file_size = j["file_size"].get<int>();
	}
	if (j.find("file_type") != j.end())
	{
		file.file_type = j["file_type"].get<int>();
	}
	if (j.find("local_path") != j.end())
	{
		file.local_path = j["local_path"].get<std::string>();
	}
}
std::string user_info::getphoneNumber() const
{
    return phone_number;
}

void user_info::setphoneNumber(const std::string &value)
{
    phone_number = value;
}

std::string user_info::getnickName() const
{
    return nick_name;
}

void user_info::setnickName(const std::string &value)
{
    nick_name = value;
}

std::string user_info::getpassWord() const
{
    return pass_word;
}

void user_info::setpassWord(const std::string &value)
{
    pass_word = value;
}

std::string user_info::getSchool() const
{
    return school;
}

void user_info::setSchool(const std::string &value)
{
    school = value;
}

std::string user_info::getCity() const
{
    return city;
}

void user_info::setCity(const std::string &value)
{
    city = value;
}

std::string user_info::getheadImage() const
{
    return head_image;
}

void user_info::setheadImage(const std::string &value)
{
    head_image = value;
}

int user_info::getfunsNumber() const
{
    return funs_number;
}

void user_info::setfunsNumber(int value)
{
    funs_number = value;
}

int user_info::getarticleNumber() const
{
    return article_number;
}

void user_info::setarticleNumber(int value)
{
    article_number = value;
}

int user_info::getactionNumber() const
{
    return action_number;
}

void user_info::setactionNumber(int value)
{
    action_number = value;
}

std::string user_info::getuserId() const
{
    return user_id;
}

void user_info::setuserId(const std::string &value)
{
    user_id = value;
}

std::string article_info::getarticleTitle() const
{
    return article_title;
}

void article_info::setarticleTitle(const std::string &value)
{
    article_title = value;
}

std::string article_info::getarticleContent() const
{
    return article_content;
}

void article_info::setarticleContent(const std::string &value)
{
    article_content = value;
}

std::string article_info::getauthorId() const
{
    return author_id;
}

void article_info::setauthorId(const std::string &value)
{
    author_id = value;
}

int article_info::getarticleType() const
{
    return article_type;
}

void article_info::setarticleType(int value)
{
    article_type = value;
}

std::string article_info::getreleaseTime() const
{
    return release_time;
}

void article_info::setreleaseTime(const std::string &value)
{
    release_time = value;
}

int article_info::getsupportingNumber() const
{
    return supporting_number;
}

void article_info::setsupportingNumber(int value)
{
    supporting_number = value;
}

int article_info::getpageView() const
{
    return page_view;
}

void article_info::setpageView(int value)
{
    page_view = value;
}

int article_info::getcommentNumber() const
{
    return comment_number;
}

void article_info::setcommentNumber(int value)
{
    comment_number = value;
}

std::string article_info::getarticleId() const
{
    return article_id;
}

void article_info::setarticleId(const std::string &value)
{
    article_id = value;
}

std::string action_info::getactionTitle() const
{
    return action_title;
}

void action_info::setactionTitle(const std::string &value)
{
    action_title = value;
}

std::string action_info::getactionContent() const
{
    return action_content;
}

void action_info::setactionContent(const std::string &value)
{
    action_content = value;
}

std::string action_info::getactionCity() const
{
    return action_city;
}

void action_info::setactionCity(const std::string &value)
{
    action_city = value;
}

std::string action_info::getbeginTime() const
{
    return begin_time;
}

void action_info::setbeginTime(const std::string &value)
{
    begin_time = value;
}

std::string action_info::getendTime() const
{
    return end_time;
}

void action_info::setendTime(const std::string &value)
{
    end_time = value;
}

std::string action_info::getauthorId() const
{
    return author_id;
}

void action_info::setauthorId(const std::string &value)
{
    author_id = value;
}

std::string action_info::getfirstFile() const
{
    return first_file;
}

void action_info::setfirstFile(const std::string &value)
{
    first_file = value;
}

std::string action_info::getsecondFile() const
{
    return second_file;
}

void action_info::setsecondFile(const std::string &value)
{
    second_file = value;
}

std::string action_info::getthirdFile() const
{
    return third_file;
}

void action_info::setthirdFile(const std::string &value)
{
    third_file = value;
}

std::string action_info::getreleaseTime() const
{
    return release_time;
}

void action_info::setreleaseTime(const std::string &value)
{
    release_time = value;
}

int action_info::getpageView() const
{
    return page_view;
}

void action_info::setpageView(int value)
{
    page_view = value;
}

std::string action_info::getactionId() const
{
    return action_id;
}

void action_info::setactionId(const std::string &value)
{
    action_id = value;
}

std::string message_info::getmessgaeBody() const
{
    return messgae_body;
}

void message_info::setmessgaeBody(const std::string &value)
{
    messgae_body = value;
}

std::string message_info::getsenderId() const
{
    return sender_id;
}

void message_info::setsenderId(const std::string &value)
{
    sender_id = value;
}

std::string message_info::getaccepterId() const
{
    return accepter_id;
}

void message_info::setaccepterId(const std::string &value)
{
    accepter_id = value;
}

std::string message_info::getsessionId() const
{
    return session_id;
}

void message_info::setsessionId(const std::string &value)
{
    session_id = value;
}

std::string message_info::getsendTime() const
{
    return send_time;
}

void message_info::setsendTime(const std::string &value)
{
    send_time = value;
}

int message_info::getmessageState() const
{
    return message_state;
}

void message_info::setmessageState(int value)
{
    message_state = value;
}

int message_info::getmessageType() const
{
    return message_type;
}

void message_info::setmessageType(int value)
{
    message_type = value;
}

std::string message_info::getmessageId() const
{
    return message_id;
}

void message_info::setmessageId(const std::string &value)
{
    message_id = value;
}

std::string interest_list::getuserId() const
{
    return user_id;
}

void interest_list::setuserId(const std::string &value)
{
    user_id = value;
}

std::string interest_list::getfollowerId() const
{
    return follower_id;
}

void interest_list::setfollowerId(const std::string &value)
{
    follower_id = value;
}

std::string interest_list::getdateSubscribed() const
{
    return date_subscribed;
}

void interest_list::setdateSubscribed(const std::string &value)
{
    date_subscribed = value;
}

std::string interest_list::getinterestId() const
{
    return interest_id;
}

void interest_list::setinterestId(const std::string &value)
{
    interest_id = value;
}

int file_base_info::getfileSize() const
{
    return file_size;
}

void file_base_info::setfileSize(int value)
{
    file_size = value;
}

int file_base_info::getfileType() const
{
    return file_type;
}

void file_base_info::setfileType(int value)
{
    file_type = value;
}

std::string file_base_info::getlocalPath() const
{
    return local_path;
}

void file_base_info::setlocalPath(const std::string &value)
{
    local_path = value;
}

std::string file_base_info::getfileMd5() const
{
    return file_md5;
}

void file_base_info::setfileMd5(const std::string &value)
{
    file_md5 = value;
}
