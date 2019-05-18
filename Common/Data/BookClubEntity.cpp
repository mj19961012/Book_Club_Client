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