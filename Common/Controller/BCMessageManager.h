#ifndef BCMESSAGEMANAHER_H
#define BCMESSAGEMANAHER_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QPixmap>
#include <QByteArray>
#include "BookClubEntity.hpp"
#include "BCCommonApiDef.hpp"

class BCMessageManager : public QObject
{
    Q_OBJECT
public :
    ~BCMessageManager();
    static BCMessageManager * getInstance();
    void BCLoginHandle(std::string username,std::string password);
	void BCRegistHandle(QString username, QString password, QString nickname, QString school, QString headimage, QString city);
	void BCGetMessageListHandle();
	void BCGetArticlesListHandle(int pagenum = -1,int pagesize = 20);
	bool BCReleaseArticleHandle(QString title,QString content,int type);
	bool BCReleaseActionHandle(QString title,QString content,QString city,QString begintime,QString endtime,QString first,QString second,QString third);
	bool BCGetDetailsOfTheArticle(QString articleid);
	void BCGetActivitiesListHandle(QString begintime, QString endtime, QString selectcity, int pagenum = -1, int pagesize = 20);
	bool BCGetDetailsOfTheaction(QString actionid);
	bool BCSendMessageHandle(QString messgae_body, QString sender_id, QString accepter_id, QString session_id, int message_type);
    void BCSystemInit();
    QString BCHttpRequestHandle(QString requrl,QString parameter,QString contenttype = BC_CONTENTTYPE_HEADER);
	QByteArray BCImageToBase64(QString imgpath);
    QPixmap BCBase64ToImage(QByteArray data, bool issave);
	QString BCUpLoadSimpleFile(QString filepath);
	QString BCGetFileInfo(QString filemd5);
	QByteArray BCDownLoadSimpleFile(QString filemd5);
public:
    QMap<QString, QMap<QString,QString>> mBCChildCityInfoMap{};
    QMap<QString, QString> mBCParentCityInfoMap{};
    QMap<QString, message_info> mBCMessageListMap{};
    QMap<QString, article_info> mBCArticlesListMap{};
    QMap<QString, action_info> mBCActivitiesListMap{};
    QMap<QString, QMap<QString, message_info>> mBCCommentListMap{};
private:
    explicit BCMessageManager(QObject *parent = nullptr);
    static BCMessageManager* mMessageManager;

    user_info current_user{};
    int m_activities_page_num{0};
    int m_articles_page_num{0};
};

#endif // BCMESSAGEMANAHER_H
