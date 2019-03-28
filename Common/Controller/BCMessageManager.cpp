#include"BCMessageManager.h"
#include<QUrl>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QApplication>
#include<QNetworkReply>
#include<QDebug>
#include"nlohmann_json.hpp"
#include <QUuid>

#include <QImage>
#include <QBuffer>

BCMessageManager* BCMessageManager::mMessageManager = nullptr;

BCMessageManager::BCMessageManager()
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
	QString reply_str = BCHttpRequestHandle(GET_API(BC_API_REGIST), parametes);
	qDebug() << "BCRegistHandle json_str:" << reply_str.length() << "\n";
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
            qDebug() << "parent:" << iter.key().c_str() << "\n";
            mBCParentCityInfoMap[iter.key().c_str()] = QString::fromStdString(iter.value()["name"].get<std::string>());
            for(auto it = iter.value()["child"].begin(); it != iter.value()["child"].end(); ++it)
            {
                qDebug() << iter.key().c_str() << "--" << it.key().c_str() << it.value()["name"].get<std::string>().c_str() << "\n";
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
	QImage image(imgpath);
	QByteArray ba;
	QBuffer buf(&ba);
	image.save(&buf, "PNG", 20);
	QByteArray hexed = ba.toBase64();
	buf.close();
	return hexed;
}

QPixmap BCMessageManager::BCBase64ToImage(QByteArray data, bool issave, QString savepath)
{
	QByteArray Ret_bytearray;
	Ret_bytearray = QByteArray::fromBase64(data);
	QBuffer buffer(&Ret_bytearray);

	buffer.open(QIODevice::WriteOnly);
	QPixmap imageresult;
	imageresult.loadFromData(Ret_bytearray);

	if (issave && savepath != "")
	{
		imageresult.save(savepath);
	}
	return imageresult;
}
