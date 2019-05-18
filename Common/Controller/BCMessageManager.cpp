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
#include "BCDataManager.h"
#include "nlohmann_json.hpp"

BCMessageManager* BCMessageManager::mMessageManager = nullptr;

BCMessageManager::BCMessageManager(QObject *parent)
    :QObject (parent)
{

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

void BCMessageManager::BCLoginHandle(std::string username,std::string password)
{
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_LOGIN), "");
}

void BCMessageManager::BCRegistHandle(QString username, QString password, QString nickname, QString school, QString headimage, QString city)
{
	QString userid = QUuid::createUuid().toString();
	QString parametes = QString("userid=%1&username=%2&password=%3&nickname=%4&school=%5&city=%6&headimage=%7").arg(userid).arg(username).arg(password).arg(nickname).arg(school).arg(city).arg(BCImageToBase64(headimage).toStdString().c_str());
	qDebug() << "BCRegistHandle parametes:" << parametes << "\n";
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_REGIST), parametes);
	qDebug() << "BCRegistHandle json_str:" << reply_str.length() << "\n";
}

void BCMessageManager::BCGetMessageListHandle()
{
	QString parametes = QString("userid=%1").arg(current_user.user_id.c_str());
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_MESSAGE_LIST), parametes);
	qDebug() << "BCGetMessageListHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetMessageListHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

	if (json_str["code"] == 200)
	{
		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<message_info>();
			qDebug() << "mBCMessageListMap-temp_value-message_id:" << temp_value.message_id.c_str() << "\n";
			mBCMessageListMap[temp_value.message_id.c_str()] = temp_value;
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCMessageListMap-size:" << mBCMessageListMap.count() << "\n";
	}
	else
	{
		qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
	}
}

void BCMessageManager::BCGetArticlesListHandle(int pagenum,int pagesize /*= 20*/)
{
	QString parametes = QString("page_num=%1&page_size=%2").arg(pagenum).arg(pagesize);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_ARTICLES_LIST), parametes);
	qDebug() << "BCGetArticlesListHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetArticlesListHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	mBCArticlesListMap.clear();
	if (pagenum >= 0)
	{
		m_articles_page_num = pagenum;
	}
	else
	{
		pagenum = m_articles_page_num;
	}
	if (json_str["code"] == 200)
	{
		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<article_info>();
			qDebug() << "mBCArticlesListMap-temp_value-article_id:" << temp_value.article_id.c_str() << "\n";
			mBCArticlesListMap[temp_value.article_id.c_str()] = temp_value;
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCArticlesListMap-size:" << mBCArticlesListMap.count() << "\n";
	}
	else
	{
		qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
	}
}

bool BCMessageManager::BCReleaseArticleHandle(QString title, QString content, int type)
{
	QString articleid = QUuid::createUuid().toString();
	long release_time = QDateTime::currentDateTime().toTime_t();
	QString parametes = QString("article_id=%1&article_title=%2&article_content=%3&article_type=%4&release_time=%5&author_id=%6").arg(articleid).arg(title).arg(content).arg(type).arg(release_time).arg(this->current_user.user_id.c_str());
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_RELEASE_ARTICLE), parametes);
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	qDebug() << "BCReleaseArticleHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCReleaseArticleHandle json_str:" << reply_str << "\n";
	return json_str["code"] == 200;
}

bool BCMessageManager::BCReleaseActionHandle(QString title, QString content, QString city, QString begintime, QString endtime, QString first, QString second, QString third)
{
	QString actionid = QUuid::createUuid().toString();
	long release_time = QDateTime::currentDateTime().toTime_t();
	QString parametes = QString("action_id=%1&action_title=%2&action_content=%3&action_city=%4&begin_time=%5&end_time=%6&author_id=%7&first_file=%8&second_file=%9&third_file=%10&release_time=%11").arg(actionid).arg(title).arg(content).arg(city).arg(begintime).arg(endtime).arg(this->current_user.user_id.c_str()).arg(first).arg(second).arg(third).arg(release_time);
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
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCCommentListMap-size:" << mBCCommentListMap[article.article_id.c_str()].count() << "\n";
	}
	return json_str["code"] == 200;
}

void BCMessageManager::BCGetActivitiesListHandle(QString begintime, QString endtime, QString selectcity, int pagenum, int pagesize)
{
	QString parametes = QString("page_num=%1&page_size=%2&action_city=%3&begin_time=%4&end_time=%5").arg(pagenum).arg(pagesize).arg(selectcity).arg(begintime).arg(endtime);
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_GET_ACTIVITIES_LIST), parametes);
	qDebug() << "BCGetActivitiesListHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCGetActivitiesListHandle json_str:" << reply_str << "\n";
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());
	mBCActivitiesListMap.clear();
	if (pagenum >= 0)
	{
		m_activities_page_num = pagenum;
	}
	else
	{
		pagenum = m_activities_page_num;
	}
	if (json_str["code"] == 200)
	{
		nlohmann::json json_list = json_str["list"];

		for (auto iter = json_list.begin(); iter != json_list.end(); ++iter)
		{
			auto temp_value = (*iter).get<action_info>();
			qDebug() << "mBCActivitiesListMap-temp_value-action_id:" << temp_value.action_id.c_str() << "\n";
			mBCActivitiesListMap[temp_value.action_id.c_str()] = temp_value;
		}
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCActivitiesListMap-size:" << mBCArticlesListMap.count() << "\n";
	}
	else
	{
		qDebug() << QString::fromStdString(json_str["msg"].get<std::string>()) << "\n";
	}
}

bool BCMessageManager::BCGetDetailsOfTheaction(QString actionid)
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
		qDebug() << "Dictionary Data parsing complete" << "\n";
		qDebug() << "mBCCommentListMap-size:" << mBCCommentListMap[action.action_id.c_str()].count() << "\n";
	}
	return json_str["code"] == 200;
}

bool BCMessageManager::BCSendMessageHandle(QString messgae_body, QString sender_id, QString accepter_id, QString session_id, int message_type)
{
	QString message_id = QUuid::createUuid().toString();
	long send_time = QDateTime::currentDateTime().toTime_t();
	QString parametes = QString("message_id=%1&messgae_body=%2&sender_id=%3&accepter_id=%4&session_id=%5&send_time=%6&message_type=%7").arg(message_id).arg(messgae_body).arg(sender_id).arg(accepter_id).arg(session_id).arg(send_time).arg(message_type);
	qDebug() << "BCSendMessageHandle parametes:" << parametes << "\n";

	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_SEND_MESSAGE), parametes);
	nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

	qDebug() << "BCSendMessageHandle json_str:" << reply_str.length() << "\n";
	qDebug() << "BCSendMessageHandle json_str[\"msg\"]:" << json_str["msg"].get<std::string>().c_str() << "\n";


	return json_str["code"] == 200;
}

void BCMessageManager::BCSystemInit()
{
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_INIT_CITY),"");

    qDebug() << "BCSystemInit json_str:" << reply_str.length() << "\n";

    nlohmann::json json_str = nlohmann::json::parse(reply_str.toStdString());

    if(json_str["code"] == 200)
    {
        nlohmann::json json_city = json_str["city"];

        for(auto iter = json_city.begin(); iter!=json_city.end(); ++iter)
        {
            //qDebug() << "parent:" << iter.key().c_str() << "\n";
            mBCParentCityInfoMap[iter.key().c_str()] = QString::fromStdString(iter.value()["name"].get<std::string>());
            for(auto it = iter.value()["child"].begin(); it != iter.value()["child"].end(); ++it)
            {
                //qDebug() << iter.key().c_str() << "--" << it.key().c_str() << it.value()["name"].get<std::string>().c_str() << "\n";
                mBCChildCityInfoMap[iter.key().c_str()][it.key().c_str()] = QString::fromStdString(it.value()["name"].get<std::string>());
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


}

QString BCMessageManager::BCHttpRequestHandle(QString requrl, QString parameter, QString contenttype)
{
// 	QString url_str = GET_API(BC_API_INIT_CITY);

	qDebug() << "BCHttpRequestHandle url_str:" << requrl << "\n";

	QUrl url(requrl);
	QNetworkAccessManager m_accessManager;
	QNetworkRequest request;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, contenttype);

	QByteArray postData;
	postData.append(parameter);
	qDebug() << "BCHttpRequestHandle before request:" << "\n";

	QNetworkReply* reply = m_accessManager.post(request, postData);

	qDebug() << "BCHttpRequestHandle after request:" << "\n";

	while (!reply->isFinished())
	{
		QApplication::processEvents();
		//QTimer::singleShot( 100,this, SLOT(isOvertime()) );
	}

	QString reply_str = reply->readAll();

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
