#include "BCMessageManager.h"
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QApplication>
#include <QNetworkReply>
#include <QDebug>
#include <QUuid>
#include <QHttpMultiPart>
#include <QImage>
#include <QBuffer>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>
#include <thread>
#include "BCDataManager.h"
#include "nlohmann_json.hpp"
#include "BCDataManager.h"

BCMessageManager* BCMessageManager::mMessageManager = nullptr;

BCMessageManager::BCMessageManager(QObject *parent)
    :QObject (parent)
{
    connect(this,&BCMessageManager::catchPersonalInformationSignals,this,&BCMessageManager::catchPersonalInformationSlot);
}

BCMessageManager::~BCMessageManager()
{

}

BCMessageManager * BCMessageManager::getInstance()
{
    if(mMessageManager == nullptr)
    {
        mMessageManager = new BCMessageManager;
        return mMessageManager;
    }
    return mMessageManager;
}

void BCMessageManager::getPageVlaues(Page::BCPageEnum pageEnum)
{
    bool is_success;
    qDebug() << "getPageVlaues_with_" << static_cast<int>(pageEnum) << "\n";
    switch(pageEnum)
    {
    case Page::Postings:
        {
            auto parametes = BCDataManager::instance().getUpLoadPostings();
            is_success = BCGetArticlesListHandle(parametes.type,parametes.pagenum,parametes.pagesize);
            BCDataManager::instance().setBCArticlesListMap(mBCArticlesListMap);
            if(!is_success)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("暂无数据可更新!!"));
            }
            emit sendOperationResultSignal(is_success,pageEnum);
            break;
        }
    case Page::PostDetail:
        {
            auto parametes = BCDataManager::instance().getUpLoadPostDetail();
            is_success = BCGetDetailsOfTheArticle(parametes.articleid);
            if(is_success)
            {
                BCDataManager::instance().setBCCommentListMap(mBCCommentListMap);
                BCDataManager::instance().setBCArticlesListMap(mBCArticlesListMap);
            }
            else
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("获取帖子详情失败!!"));
                return;
            }
            emit sendOperationResultSignal(is_success,pageEnum);
            break;
        }
    case Page::PostMaster:
        {
            auto parametes = BCDataManager::instance().getUpLoadPostMaster();
            is_success = BCGetSomebodyPostArticlesHandle(parametes.userid,parametes.pagenum,parametes.pagesize);
            if(is_success)
            {
                BCDataManager::instance().setCurrentCatchArticlesList(mCurrentCatchArticlesList);
                BCDataManager::instance().setCurrentCatchArticlesListAuthor(mCurrentCatchArticlesListAuthor);
            }
            else
            {
                //TODO emit xxx(false,pageEnum);
                return;
            }

            is_success = BCGetSomebodyPostActivitiesHandle(parametes.userid,parametes.pagenum,parametes.pagesize);
            if(is_success)
            {
                BCDataManager::instance().setCurrentCatchActivitiesList(mCurrentCatchActivitiesList);
                BCDataManager::instance().setCurrentCatchActivitiesLisAuthor(mCurrentCatchActivitiesLisAuthor);
            }
            else
            {
                //TODO emit xxx(false,pageEnum);
                return;
            }

            is_success = BCGetPersonalInformationHandle(mCurrentCatchArticlesListAuthor);
            if(!is_success)
            {
                //TODO emit xxx(false,pageEnum);
                return;
            }
            //TODO emit xxx(true,pageEnum);
            break;
        }
    case Page::PublishPost:
        {
            auto parametes = BCDataManager::instance().getUpLoadPublishPost();
            is_success = BCReleaseArticleHandle(parametes.title,parametes.content,parametes.type);
            if(!is_success)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("发布失败，请稍后重试"));
                sendOperationResultSignal(is_success,pageEnum);
                return;
            }
            emit sendOperationResultSignal(is_success,pageEnum);
            break;
        }
    case Page::Activity:
        {
            auto parametes = BCDataManager::instance().getUpLoadActivity();
            is_success = BCGetActivitiesListHandle(parametes.begintime,parametes.endtime,parametes.selectcity,parametes.pagenum,parametes.pagesize);
            if(is_success)
            {
                BCDataManager::instance().setBCActivitiesListMap(mBCActivitiesListMap);
            }
            else
            {
                emit sendOperationResultSignal(false,pageEnum);
                return;
            }
            emit sendOperationResultSignal(true,pageEnum);
            break;
        }
    case Page::ActivityDetail:
        {
            auto parametes = BCDataManager::instance().getUpLoadActivityDetail();
            is_success = BCGetDetailsOfTheAction(parametes.actionid);
            if(is_success)
            {
                BCDataManager::instance().setBCActivitiesListMap(mBCActivitiesListMap);
                BCDataManager::instance().setBCFileListMap(mBCFileListMap);
            }
            else
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("获取活动详情失败!!"));
                return;
            }
            emit sendOperationResultSignal(is_success,pageEnum);
            break;
        }
    case Page::PublishActivity:
        {
            auto parametes = BCDataManager::instance().getUpLoadPublishActivity();
            is_success = BCReleaseActionHandle(parametes.title,parametes.content,parametes.city,parametes.begintime,parametes.endtime,parametes.first,parametes.second,parametes.third);
            if(!is_success)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("发布活动失败"));
                return;
            }
            emit sendOperationResultSignal(is_success,pageEnum);
            break;
        }
    case Page::Message:
        {
            auto parametes = BCDataManager::instance().getUpLoadMessage();
            is_success = BCGetMessageListHandle(parametes.accepterid);
            if(is_success)
            {
                BCDataManager::instance().setBCMessageListMap(mBCMessageListMap);
            }
            else
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("暂无未读消息!!"));
                emit sendOperationResultSignal(false,pageEnum);
                return;
            }
            emit sendOperationResultSignal(true,pageEnum);
            break;
        }
    case Page::Chat:
        {
            auto parametes = BCDataManager::instance().getUpLoadChat();
            is_success = BCSendMessageHandle(parametes.messgaebody,parametes.senderid,parametes.accepterid,parametes.sessionid,parametes.messagetype);
            if(!is_success)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("发送失败!!"));
                emit sendOperationResultSignal(false,pageEnum);
                return;
            }
            BCDataManager::instance().setBCMessageListMap(mBCMessageListMap);
            qDebug() << "BCMessageListMap_size:" << mBCMessageListMap.count() << "\n";
            emit sendOperationResultSignal(true,pageEnum);
            break;
        }
    case Page::PersonalInformation:
        {
            auto parametes = BCDataManager::instance().getUpLoadPersonalInformation();
            is_success = BCLoginHandle(parametes.username,parametes.password);
            if(!is_success)
            {
                emit sendOperationResultSignal(false,pageEnum);
                return;
            }
            qDebug() << "head_img:" << mCurrentUser.head_image.c_str() << "\n";
            QString head_image = QString("%1/%2").arg(BC_API_URL).arg(mCurrentUser.head_image.c_str());
            mCurrentUser.head_image = head_image.toStdString();
            qDebug() << "head_img" << head_image << "\n";
            BCDataManager::instance().setCurrentLoginUserInfo(mCurrentUser);

//            is_success = BCGetArticlesListHandle(1,0,20);
            if(BCGetArticlesListHandle(1,0,20))
            {
                BCDataManager::instance().setBCArticlesListMap(mBCArticlesListMap);
            }

//            is_success = BCGetMessageListHandle(QString().fromStdString(mCurrentUser.user_id));

            if(BCGetMessageListHandle(QString().fromStdString(mCurrentUser.user_id)))
            {
                BCDataManager::instance().setBCMessageListMap(mBCMessageListMap);
            }

            emit sendOperationResultSignal(is_success,pageEnum);
            break;
        }
    case Page::MineFocus:
        {
            auto parametes = BCDataManager::instance().getUpLoadMineFocus();
            is_success = BCGetInterestListWithSomeoneHandle(parametes.userid);
            if(is_success)
            {
                BCDataManager::instance().setBCInterestListMap(mBCInterestListMap);
            }
            else
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("获取关注列表信息失败"));
                return;
            }
            emit sendOperationResultSignal(is_success,pageEnum);
            break;
        }
    case Page::Search:
        {
            break;
        }
    case Page::Init:
        {
            is_success = BCSystemInit();
            if(is_success)
            {
                BCDataManager::instance().setBCCityIdToName(mBCCityIdToName);
                BCDataManager::instance().setBCChildCityInfoMap(mBCChildCityInfoMap);
                BCDataManager::instance().setBCParentCityInfoMap(mBCParentCityInfoMap);
            }
            else
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("获取数据字典失败"));
                return;
            }

            //TODO emit xxx(true,pageEnum);

            break;
        }
    case Page::Regiest:
        {
            auto parametes = BCDataManager::instance().getUpLoadRegiest();

            QString fileMd5 = BCUpLoadSimpleFile(parametes.headimage);

            if(fileMd5.size() <= 0)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("头像上传失败，请检查网络后重试！"));
                emit sendOperationResultSignal(false,pageEnum);
                return;
            }

            qDebug() << "fileMd5:" << fileMd5 << "\n";

            QString filePath = BCGetFileInfo(fileMd5);

            if(filePath.size() <= 0)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("头像信息获取失败，请稍后重试！"));
                emit sendOperationResultSignal(false,pageEnum);
                return;
            }

            is_success = BCRegistHandle(parametes.username,parametes.password,parametes.nickname,parametes.school,filePath,parametes.city);

            if(!is_success)
            {
                //TODO emit xxx(false,pageEnum);
                return;
            }
            emit sendOperationResultSignal(true,pageEnum);
            break;
        }
    case Page::ChangeMessageStatus:
        {
            auto parametes = BCDataManager::instance().getUploadChangeMessageStatus();
            is_success = BCChangeMessageStatusHandle(parametes.senderId,parametes.sessionId,parametes.messageType);
//            if(!is_success)
//            {
//                BCDataManager::instance().setErrorMsg(QStringLiteral("暂无未读消息!!"));
//                emit sendOperationResultSignal(false,Page::Message);
//                return;
//            }
            is_success = BCGetMessageListHandle(parametes.sessionId);

            BCDataManager::instance().setBCMessageListMap(mBCMessageListMap);
            if(!is_success)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("暂无未读消息!!"));
            }
            emit sendOperationResultSignal(is_success,Page::Message);
            break;
        }
    case Page::UploadFile:
        {
            auto parametes = BCDataManager::instance().getUploadFile();
            QString filemd5 = BCUpLoadSimpleFile(parametes.filepath);
            if(filemd5.size() <= 0)
            {
                BCDataManager::instance().setErrorMsg(QStringLiteral("文件上传失败，请稍后重试!"));
                emit sendOperationResultSignal(false,Page::UploadFile);
                return;
            }
            BCDataManager::instance().setErrorMsg(filemd5);
            emit sendOperationResultSignal(true,Page::UploadFile);
            break;
        }
    default:
        {
            break;
        }
    }
}

void BCMessageManager::catchPersonalInformationSlot(std::string userId)
{
    qDebug() << "BCMessageManager::catchPersonalInformationSlot" << "\n";
    if(BCDataManager::instance().checkUserInformaitonCatched(QString().fromStdString(userId)))
    {
        return;
    }
    qDebug() << "BCGetPersonalInformationHandle:"<< userId.c_str() << "\n";
    this->BCGetPersonalInformationHandle(QString().fromStdString(userId));
//    std::thread thread(
//                [&userId,this]()
//                {
//                    this->BCGetPersonalInformationHandle(QString().fromStdString(userId));
//                }
//                );
//    thread.detach();
}

bool BCMessageManager::BCLoginHandle(QString username,QString password)
{
    QString parametes = QString("username=%1&password=%2").arg(username).arg(password);
    QString reply_str = BCHttpRequestHandle(GET_API(BC_API_LOGIN), parametes);
    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

    if (json_str["code"] == 200)
    {
        auto temp_user = json_str["user"].get<user_info>();

        mCurrentUser.id = temp_user.id;
        mCurrentUser.user_id = temp_user.user_id;
        mCurrentUser.phone_number = temp_user.phone_number;
        mCurrentUser.nick_name = temp_user.nick_name;
        mCurrentUser.pass_word = temp_user.pass_word;
        mCurrentUser.school = temp_user.school;
        mCurrentUser.city = temp_user.city;
        mCurrentUser.head_image = temp_user.head_image;
        mCurrentUser.funs_number = temp_user.funs_number;
        mCurrentUser.article_number = temp_user.article_number;
        mCurrentUser.action_number = temp_user.action_number;
    }
    else
    {
        qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
    }

    return json_str["code"] == 200;
}

bool BCMessageManager::BCRegistHandle(QString username, QString password, QString nickname, QString school, QString headimage, QString city)
{
	QString userid = QUuid::createUuid().toString();
    QString parametes = QString("userid=%1&username=%2&password=%3&nickname=%4&school=%5&city=%6&headimage=%7").arg(userid).arg(username).arg(password).arg(nickname).arg(school).arg(city).arg(headimage);
	qDebug() << "BCRegistHandle parametes:" << parametes << "\n";
    qDebug() << "BCRegistHandle headimage:" << headimage << "\n";
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_REGIST), parametes);
	qDebug() << "BCRegistHandle json_str:" << reply_str.length() << "\n";

    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
    return json_str["code"] == 200;
}

bool BCMessageManager::BCGetMessageListHandle(QString accepterId)
{
    QString parametes = QString("userid=%1").arg(accepterId);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_MESSAGE_LIST), parametes);
	qDebug() << "BCGetMessageListHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetMessageListHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
    mBCMessageListMap.clear();
	if (json_str["code"] == 200)
	{
		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<message_info>();
			qDebug() << "mBCMessageListMap-temp_value-message_id:" << temp_value.message_id.c_str() << "\n";
			mBCMessageListMap[temp_value.message_id.c_str()] = temp_value;
            emit catchPersonalInformationSignals(temp_value.sender_id);
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCMessageListMap-size:" << mBCMessageListMap.count() << "\n";
	}
	else
	{
		qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
	}
    return mBCMessageListMap.size() > 0;
}

bool BCMessageManager::BCGetArticlesListHandle(int type, int pagenum /*= -1*/,int pagesize /*= 20*/)
{
	QString parametes = QString("page_num=%1&page_size=%2&type=%3").arg(pagenum).arg(pagesize).arg(type);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_ARTICLES_LIST), parametes);
	qDebug() << "BCGetArticlesListHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetArticlesListHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	mBCArticlesListMap.clear();
	if (pagenum >= 0)
	{
        mMainArticlesPageNum = pagenum;
	}
	else
	{
        pagenum = mMainArticlesPageNum;
	}
	if (json_str["code"] == 200)
	{
		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<article_info>();
            qDebug() << "mBCArticlesListMap-temp_value-author_id:" << temp_value.author_id.c_str() << "\n";
			mBCArticlesListMap[temp_value.article_id.c_str()] = temp_value;
            emit catchPersonalInformationSignals(temp_value.author_id);
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCArticlesListMap-size:" << mBCArticlesListMap.count() << "\n";
	}
	else
	{
		qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
	}
    return mBCArticlesListMap.size() > 0;
}

bool BCMessageManager::BCReleaseArticleHandle(QString title, QString content, int type)
{
	QString articleid = QUuid::createUuid().toString();
    auto release_time = QDateTime::currentDateTime().toTime_t();
    QString parametes = QString("article_id=%1&article_title=%2&article_content=%3&article_type=%4&release_time=%5&author_id=%6").arg(articleid).arg(title).arg(content).arg(type).arg(release_time).arg(this->mCurrentUser.user_id.c_str());
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_RELEASE_ARTICLE), parametes);
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	qDebug() << "BCReleaseArticleHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCReleaseArticleHandle json_str:" << reply_str << "\n";
	return json_str["code"] == 200;
}

bool BCMessageManager::BCReleaseActionHandle(QString title, QString content, QString city, QString begintime, QString endtime, QString first, QString second, QString third)
{
	QString actionid = QUuid::createUuid().toString();
    auto release_time = QDateTime::currentDateTime().toTime_t();
    QString parametes = QString("action_id=%1&action_title=%2&action_content=%3&action_city=%4&begin_time=%5&end_time=%6&author_id=%7&first_file=%8&second_file=%9&third_file=%10&release_time=%11").arg(actionid).arg(title).arg(content).arg(city).arg(begintime).arg(endtime).arg(this->mCurrentUser.user_id.c_str()).arg(first).arg(second).arg(third).arg(release_time);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_RELEASE_ACTION), parametes);
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	qDebug() << "BCReleaseActionHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCReleaseActionHandle json_str:" << reply_str << "\n";

	return json_str["code"] == 200;
}

bool BCMessageManager::BCGetDetailsOfTheArticle(QString articleid)
{
	QString parametes = QString("article_id=%1").arg(articleid);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_DETAIL_OF_ATRICLE), parametes);
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	qDebug() << "BCGetDetailsOfTheArticle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetDetailsOfTheArticle json_str:" << reply_str << "\n";
	if (json_str["code"] == 200)
	{
		auto article = json_str["article"].get<article_info>();
		mBCArticlesListMap[article.article_id.c_str()] = article;

		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<message_info>();
			qDebug() << "mBCCommentListMap-temp_value-message_id:" << temp_value.message_id.c_str() << "\n";
			mBCCommentListMap[article.article_id.c_str()][temp_value.message_id.c_str()] = temp_value;
            emit catchPersonalInformationSignals(temp_value.sender_id);
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCCommentListMap-size:" << mBCCommentListMap[article.article_id.c_str()].count() << "\n";
        emit catchPersonalInformationSignals(article.author_id);
	}
	return json_str["code"] == 200;
}

bool BCMessageManager::BCGetActivitiesListHandle(QString begintime, QString endtime, QString selectcity, int pagenum, int pagesize)
{
    if (pagenum >= 0)
    {
        mMainActivitiesPageNum = pagenum;
    }
    else
    {
        pagenum = mMainActivitiesPageNum;
    }
	QString parametes = QString("page_num=%1&page_size=%2&action_city=%3&begin_time=%4&end_time=%5").arg(pagenum).arg(pagesize).arg(selectcity).arg(begintime).arg(endtime);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_ACTIVITIES_LIST), parametes);
	qDebug() << "BCGetActivitiesListHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetActivitiesListHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	mBCActivitiesListMap.clear();

	if (json_str["code"] == 200)
	{
		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<action_info>();
            qDebug() << "mBCActivitiesListMap-iter-dump:" << iter->dump().c_str() << "\n";
			qDebug() << "mBCActivitiesListMap-temp_value-action_id:" << temp_value.action_id.c_str() << "\n";
			mBCActivitiesListMap[temp_value.action_id.c_str()] = temp_value;
            emit catchPersonalInformationSignals(temp_value.author_id);
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
        qDebug() << "mBCActivitiesListMap-size:" << mBCActivitiesListMap.count() << "\n";
	}
	else
	{
		qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
	}

    return mBCActivitiesListMap.size() > 0;
}

bool BCMessageManager::BCGetDetailsOfTheAction(QString actionid)
{
	QString parametes = QString("action_id=%1").arg(actionid);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_DETAIL_OF_ACTION), parametes);
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	qDebug() << "BCGetDetailsOfTheaction json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetDetailsOfTheaction json_str:" << reply_str << "\n";
	if (json_str["code"] == 200)
	{
		auto action = json_str["action"].get<action_info>();
		mBCActivitiesListMap[action.action_id.c_str()] = action;

		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<message_info>();
			qDebug() << "mBCCommentListMap-temp_value-message_id:" << temp_value.message_id.c_str() << "\n";
			mBCCommentListMap[action.action_id.c_str()][temp_value.message_id.c_str()] = temp_value;
		}

		nlohmann::json json_files = json_str["files"];
		if (json_files.find("first_file") != json_files.end())
		{
			auto first_file = json_files["first_file"].get<file_base_info>();
			mBCFileListMap[first_file.file_md5.c_str()] = first_file;
		}
		if (json_files.find("second_file") != json_files.end())
		{
			auto second_file = json_files["second_file"].get<file_base_info>();
			mBCFileListMap[second_file.file_md5.c_str()] = second_file;
		}
		if (json_files.find("third_file") != json_files.end())
		{
			auto third_file = json_files["third_file"].get<file_base_info>();
			mBCFileListMap[third_file.file_md5.c_str()] = third_file;
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCCommentListMap-size:" << mBCCommentListMap[action.action_id.c_str()].count() << "\n";
        emit catchPersonalInformationSignals(action.author_id);
	}
	return json_str["code"] == 200;
}

bool BCMessageManager::BCSendMessageHandle(QString messgae_body, QString sender_id, QString accepter_id, QString session_id, int message_type)
{
	QString message_id = QUuid::createUuid().toString();
    auto send_time = QDateTime::currentDateTime().toTime_t();
	QString parametes = QString("message_id=%1&messgae_body=%2&sender_id=%3&accepter_id=%4&session_id=%5&send_time=%6&message_type=%7").arg(message_id).arg(messgae_body).arg(sender_id).arg(accepter_id).arg(session_id).arg(send_time).arg(message_type);
//	qDebug() << "BCSendMessageHandle parametes:" << parametes << "\n";
    mBCMessageListMap.clear();
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_SEND_MESSAGE), parametes);
    qDebug() << "BCSendMessageHandle reply_str:" << reply_str << "\n";
    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
    if(json_str["code"] == 200)
    {
        auto message = json_str["message"].get<message_info>();
        mBCMessageListMap[message.message_id.c_str()] = message;
    }
	qDebug() << "BCSendMessageHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCSendMessageHandle json_str[\"msg\"]:" << json_str["msg"].get<std::string>().c_str() << "\n";

    return json_str["code"] == 200;
}

bool BCMessageManager::BCChangeMessageStatusHandle(QString sendId, QString sessionId, int messageType)
{
    QString parametes = QString("sender_id=%1&session_id=%2&message_type=%3").arg(sendId).arg(sessionId).arg(messageType);
    QString reply_str = BCHttpRequestHandle(GET_API(BC_API_CHANGE_MESSAGE_STATUS), parametes);
    qDebug() << "BCChangeMessageStatusHandle parametes:" << parametes << "\n";

    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

    qDebug() << "BCChangeMessageStatusHandle json_str:" << reply_str.length() << "\n";
    qDebug() << "BCChangeMessageStatusHandle json_str[\"msg\"]:" << json_str["msg"].get<std::string>().c_str() << "\n";

    return json_str["code"] == 200;
}

bool BCMessageManager::BCSystemInit()
{
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_INIT_CITY),"");

    qDebug() << "BCSystemInit json_str:" << reply_str.length() << "\n";

    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
    mBCParentCityInfoMap.clear();
    if(json_str["code"] == 200)
    {
        nlohmann::json json_city = json_str["city"];

        for(auto iter = json_city.begin(); iter!=json_city.end(); ++iter)
        {
            //qDebug() << "parent:" << iter.key().c_str() << "\n";
            mBCParentCityInfoMap[iter.key().c_str()] = QString::fromStdString(iter.value()["name"].get<std::string>());
            mBCCityIdToName[iter.key().c_str()] = QString::fromStdString(iter.value()["name"].get<std::string>());
            for(auto it = iter.value()["child"].begin(); it != iter.value()["child"].end(); ++it)
            {
                //qDebug() << iter.key().c_str() << "--" << it.key().c_str() << it.value()["name"].get<std::string>().c_str() << "\n";
                mBCChildCityInfoMap[iter.key().c_str()][it.key().c_str()] = QString::fromStdString(it.value()["name"].get<std::string>());
                mBCCityIdToName[it.key().c_str()] = QString::fromStdString(it.value()["name"].get<std::string>());
//                qDebug() << it.key().c_str() << "---" << it.value()["name"].get<std::string>().c_str() << "\n";
            }
        }
        qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCParentCityInfoMap-size:" << mBCParentCityInfoMap.count() << "\n";
		qDebug() << "mBCChildCityInfoMap-size:" << mBCChildCityInfoMap.count() << "\n";
    }
    else
    {
        qDebug() << "Dictionary Data parsing exception" << "\n";
    }

    return mBCParentCityInfoMap.size() > 0;
}

bool BCMessageManager::BCGetSomebodyPostArticlesHandle(QString user_id, int pagenum , int pagesize)
{
    QString parametes = QString("userid=%1&page_num=%2&page_size=%3").arg(user_id).arg(pagenum).arg(pagesize);
    QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_ACTIVITIES_LIST), parametes);
    qDebug() << "BCGetSomebodyPostArticlesHandle json_str:" << reply_str.length() << "\n";
    qDebug() << "BCGetSomebodyPostArticlesHandle json_str:" << reply_str << "\n";
    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
    mCurrentCatchArticlesList.clear();
    if (pagenum >= 0)
    {
        mCatchArticlesPageNum = pagenum;
    }
    else
    {
        pagenum = mCatchArticlesPageNum;
    }
    if (json_str["code"] == 200)
    {
        nlohmann::json json_list = json_str["list"];

        for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
        {
            auto temp_value = (*iter).get<article_info>();
            qDebug() << "mCurrentCatchArticlesList-temp_value-action_id:" << temp_value.author_id.c_str() << "\n";
            mCurrentCatchArticlesList.push_back(temp_value);
        }
        qDebug() << "Dictionary Data parsing complete" << "\n";
        qDebug() << "mCurrentCatchArticlesList-size:" << mCurrentCatchArticlesList.count() << "\n";
    }
    else
    {
        qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
    }

    return json_str["code"] == 200;
}

bool BCMessageManager::BCGetSomebodyPostActivitiesHandle(QString user_id, int pagenum, int pagesize)
{
    QString parametes = QString("userid=%1&page_num=%2&page_size=%3").arg(user_id).arg(pagenum).arg(pagesize);
    QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_ACTIVITIES_LIST), parametes);
    qDebug() << "BCGetSomebodyPostActivitiesHandle json_str:" << reply_str.length() << "\n";
    qDebug() << "BCGetSomebodyPostActivitiesHandle json_str:" << reply_str << "\n";
    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
    mCurrentCatchActivitiesList.clear();
    if (pagenum >= 0)
    {
        mCatchActivitiesPageNum = pagenum;
    }
    else
    {
        pagenum = mCatchActivitiesPageNum;
    }
    if (json_str["code"] == 200)
    {
        nlohmann::json json_list = json_str["list"];

        for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
        {
            auto temp_value = (*iter).get<action_info>();
            qDebug() << "mCurrentCatchActivitiesList-temp_value-action_id:" << temp_value.author_id.c_str() << "\n";
            mCurrentCatchActivitiesList.push_back(temp_value);
        }
        qDebug() << "Dictionary Data parsing complete" << "\n";
        qDebug() << "mCurrentCatchActivitiesList-size:" << mCurrentCatchActivitiesList.count() << "\n";
    }
    else
    {
        qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
    }

    return json_str["code"] == 200;
}

bool BCMessageManager::BCFollowSomeBodyHandle(QString user_id, QString follow_id)
{
	QString interest_id = QUuid::createUuid().toString();
    auto follow_time = QDateTime::currentDateTime().toTime_t();
	QString parametes = QString("interest_id=%1&user_id=%2&follow_id=%3&date=%4").arg(interest_id).arg(user_id).arg(follow_id).arg(follow_time);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_FOLLOW_SOMEBODY), parametes);
	qDebug() << "BCFollowSomeBodyHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCFollowSomeBodyHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

	return json_str["code"] == 200;
}

bool BCMessageManager::BCFollowCancleSomeBodyHandle(QString interest_id)
{
	QString parametes = QString("interest_id=%1").arg(interest_id);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_FOLLOW_CANCLE), parametes);
	qDebug() << "BCFollowCancleSomeBodyHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCFollowCancleSomeBodyHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

	return json_str["code"] == 200;
}

bool BCMessageManager::BCGetInterestListWithSomeoneHandle(QString user_id)
{
    QString parametes = QString("user_id=%1").arg(user_id);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_SOMEONE_INTEREST_LIST), parametes);
	qDebug() << "BCGetInterestListWithSomeoneHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetInterestListWithSomeoneHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

	if (json_str["code"] == 200)
	{
		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<interest_list>();
			qDebug() << "mBCMessageListMap-temp_value-message_id:" << temp_value.interest_id.c_str() << "\n";
			mBCInterestListMap[temp_value.interest_id.c_str()] = temp_value;
//            emit catchPersonalInformationSignals(temp_value.follower_id);
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCInterestListMap-size:" << mBCInterestListMap.count() << "\n";
	}
	else
	{
		qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
	}
    return json_str["code"] == 200;
}

bool BCMessageManager::BCGetPersonalInformationHandle(QString user_id)
{
    QString parametes = QString("user_id=%1").arg(user_id);
    QString reply_str = BCHttpRequestHandle(GET_API(BC_API_PERSONALINFORMATION), parametes);
    qDebug() << "BCGetPersonalInformationHandle json_str:" << reply_str.length() << "\n";
    qDebug() << "BCGetPersonalInformationHandle json_str:" << reply_str << "\n";
    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

    if(json_str["code"] == 200)
    {
        auto user = json_str["user"].get<user_info>();
        QString head_image = QString("%1/%2").arg(BC_API_URL).arg(user.head_image.c_str());
        user.head_image = head_image.toStdString();
        while (BCDataManager::instance().isLock())
        {
            QApplication::processEvents();
        }
        BCDataManager::instance().Lock();
        BCDataManager::instance().addPersonalInformationToList(user);
        BCDataManager::instance().UnLock();
    }
    else
    {
        qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
    }

    return json_str["code"] == 200;
}

QString BCMessageManager::BCHttpRequestHandle(QString requrl, QString parameter, QString contenttype)
{
// 	QString url_str = GET_API(BC_API_INIT_CITY);

//	qDebug() << "BCHttpRequestHandle url_str:" << requrl << "\n";

	QUrl url(requrl);
	QNetworkAccessManager m_accessManager;
	QNetworkRequest request;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, contenttype);

	QByteArray postData;
	postData.append(parameter);
//	qDebug() << "BCHttpRequestHandle before request:" << "\n";

	QNetworkReply* reply = m_accessManager.post(request, postData);

//	qDebug() << "BCHttpRequestHandle after request:" << "\n";

	while (!reply->isFinished())
	{
		QApplication::processEvents();
		//QTimer::singleShot( 100,this, SLOT(isOvertime()) );
	}

	QString reply_str = reply->readAll();
//    qDebug() << "BCHttpRequestHandle return:" << reply_str << "\n";
	return reply_str;
}

QByteArray BCMessageManager::BCImageToBase64(QString imgpath)
{
    QImage image;
    if(image.load(imgpath))
    {
        QByteArray ba;
        QBuffer buf(&ba);
        image.save(&buf, "PNG", 20);
        QByteArray hexed = ba.toBase64();
        buf.close();
        return hexed;
    }
    else
    {
        return QByteArray("");
    }
}

QPixmap BCMessageManager::BCBase64ToImage(QByteArray data, bool issave)
{
	QByteArray Ret_bytearray;
	Ret_bytearray = QByteArray::fromBase64(data);
	QBuffer buffer(&Ret_bytearray);

	buffer.open(QIODevice::WriteOnly);
	QPixmap imageresult;
	imageresult.loadFromData(Ret_bytearray);

    if(issave)
	{
        //TODO
        QString appDataPath = BCDataManager::instance().getAppDataPath() + "/imageLog/";
        QDir dir;
        dir.setPath(appDataPath);
        if(!dir.exists(appDataPath))
        {
            dir.mkpath(appDataPath);
        }

        imageresult.save(appDataPath);
	}
    buffer.close();
    return imageresult;
}

QString BCMessageManager::BCUpLoadSimpleFile(QString filepath)
{
    QUrl url = QUrl(GET_API(BC_API_UPLOAD_SIMPLE_FILE));

	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

	const char* bd = "--acebdf13572468--acebdf13572468--";
	multiPart->setBoundary(bd);

	QHttpPart imagePart;

	QFile *file = new QFile(filepath);
	QFileInfo info(*file);

	imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
	imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\"; filename=\"" + info.fileName() + "\""));

	file->open(QIODevice::ReadOnly);
	imagePart.setBodyDevice(file);

	//    QString bd = "__fasdlkfjassdasddafdfgdfgsdfgasgdfsgaSdhhkjljkl__";
	//    multiPart->setBoundary(bd.toLatin1());

	file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart
	multiPart->append(imagePart);

	QNetworkRequest request(url);

	request.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data; boundary=" + multiPart->boundary());

	QNetworkAccessManager manager;
	QNetworkReply *reply = manager.post(request, multiPart);
	multiPart->setParent(reply); // delete the multiPart with the reply

	while (!reply->isFinished())
	{
		QApplication::processEvents();
	}
	QString reply_str = reply->readAll();

	nlohmann::json reply_json = nlohmann::json::parse(reply_str.toStdString());

	if (reply_json["code"] == 200)
	{
		return QString().fromStdString(reply_json["file_md5"].get<std::string>());
	}
	return QString();
}

QString BCMessageManager::BCGetFileInfo(QString filemd5)
{
	QString parametes = QString("file_md5=%1").arg(filemd5);

	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_FILE_INFO), parametes);
	
	nlohmann::json reply_json = nlohmann::json::parse(reply_str.toStdString());

	if (reply_json["code"] == 200)
	{
		return QString().fromStdString(reply_json["local_path"].get<std::string>());
	}

	return QString();
}

QByteArray BCMessageManager::BCDownLoadSimpleFile(QString filemd5)
{
	QString parametes = QString("file_md5=%1").arg(filemd5);

	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_FILE_INFO), parametes);

	nlohmann::json reply_json = nlohmann::json::parse(reply_str.toStdString());

	if (reply_json["code"] == 200)
	{
		std::string file_path = reply_json["local_path"].get<std::string>();
		std::string str_url;
		std::string file_name;
		if (file_path.find(BC_API_URL) != std::string::npos)
		{
			str_url = file_path;
			file_name = "." + file_path.substr(strlen(BC_API_URL), file_path.length() - strlen(BC_API_URL));
		}
		else
		{
			str_url = BC_API_URL + file_path.substr(file_path.find_first_not_of('.'));
			file_name = file_path;
		}
		qDebug() << "BCDownLoadSimpleFile str_url:" << str_url.c_str() << "\n";
		qDebug() << "BCDownLoadSimpleFile file_name:" << file_name.c_str() << "\n";
		QNetworkAccessManager m_accessManager;
		QNetworkRequest request;
		request.setUrl(QUrl(str_url.c_str()));

		QNetworkReply* reply = m_accessManager.get(request);

		while (!reply->isFinished())
		{
			QApplication::processEvents();
			//QTimer::singleShot( 100,this, SLOT(isOvertime()) );
		}

		if (!reply->isFinished())
		{
			return QByteArray();
		}
		else
		{
			return reply->readAll();
		}
	}
	qDebug() << "BCDownLoadSimpleFile after request:" << reply_json["msg"].get<std::string>().c_str() << "\n";
    return QByteArray();
}
