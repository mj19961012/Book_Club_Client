#include "BCDataManager.h"
#include <QStandardPaths>
#include <QDir>

BCDataManager *BCDataManager::sDataManager = nullptr;

BCDataManager &BCDataManager::instance()
{
    if(!sDataManager)
    {
        sDataManager = new BCDataManager;
    }
    return *sDataManager;
}

void BCDataManager::release()
{
    if(sDataManager)
    {
        delete sDataManager;
        sDataManager = nullptr;
    }
}

const QString &BCDataManager::getAppDataPath()
{
    QDir tempDir;
    tempDir.setPath(mAppDataPath);
    if(!tempDir.exists(mAppDataPath))
    {
        tempDir.mkpath(mAppDataPath);
    }
    return mAppDataPath;
}

void BCDataManager::setUpLoadPostings(int type)
{
    mUpLoadPostings.type = type;
    mUpLoadPostings.pagenum = -1;
    mUpLoadPostings.pagesize = 20;
}

void BCDataManager::setUpLoadPostings(int type, int pagenum)
{
    mUpLoadPostings.type = type;
    mUpLoadPostings.pagenum = pagenum;
    mUpLoadPostings.pagesize = 20;
}

void BCDataManager::setUpLoadPostings(int type, int pagenum, int pagesize)
{
    mUpLoadPostings.type = type;
    mUpLoadPostings.pagenum = pagenum;
    mUpLoadPostings.pagesize = pagesize;
}

void BCDataManager::setUpLoadPostDetail(QString postid)
{
    mUpLoadPostDetail.articleid = postid;
}

void BCDataManager::setUpLoadPostMaster(QString userid)
{
    mUpLoadPostMaster.userid = userid;
    mUpLoadPostMaster.pagenum = -1;
    mUpLoadPostMaster.pagesize = 20;
}

void BCDataManager::setUpLoadPostMaster(QString userid, int pagenum)
{
    mUpLoadPostMaster.userid = userid;
    mUpLoadPostMaster.pagenum = pagenum;
    mUpLoadPostMaster.pagesize = 20;
}

void BCDataManager::setUpLoadPostMaster(QString userid, int pagenum, int pagesize)
{
    mUpLoadPostMaster.userid = userid;
    mUpLoadPostMaster.pagenum = pagenum;
    mUpLoadPostMaster.pagesize = pagesize;
}

void BCDataManager::setUpLoadPublishPost(QString title, QString content, int type)
{
    mUpLoadPublishPost.title = title;
    mUpLoadPublishPost.content = content;
    mUpLoadPublishPost.type = type;
}

void BCDataManager::setUpLoadActivityDetail(QString articleid)
{
    mUpLoadActivityDetail.actionid = articleid;
}

void BCDataManager::setUpLoadPublishActivity(QString title, QString content, QString city, QString begintime, QString endtime, QString first, QString second, QString third)
{
    mUpLoadPublishActivity.title = title;
    mUpLoadPublishActivity.content = content;
    mUpLoadPublishActivity.city = city;
    mUpLoadPublishActivity.begintime = begintime;
    mUpLoadPublishActivity.endtime = endtime;
    mUpLoadPublishActivity.first = first;
    mUpLoadPublishActivity.second = second;
    mUpLoadPublishActivity.third = third;
}

void BCDataManager::setUpLoadMessage(QString accepterId, int messageType)
{
    mUpLoadMessage.accepterid = accepterId;
    mUpLoadMessage.messagetype = messageType;
}

void BCDataManager::setUpLoadChat(QString messgaebody, QString senderid, QString accepterid, QString sessionid, int messagetype)
{
    mUpLoadChat.messgaebody = messgaebody;
    mUpLoadChat.senderid = senderid;
    mUpLoadChat.accepterid = accepterid;
    mUpLoadChat.sessionid = sessionid;
    mUpLoadChat.messagetype = messagetype;
}

void BCDataManager::setUpLoadPersonalInformation(QString username, QString password)
{
    mUpLoadPersonalInformation.username = username;
    mUpLoadPersonalInformation.password = password;
}

void BCDataManager::setUpLoadMineFocus(QString userid)
{
    mUpLoadMineFocus.userid = userid;
}

void BCDataManager::setUpLoadSearch()
{

}

UpLoadPostings BCDataManager::getUpLoadPostings() const
{
    return mUpLoadPostings;
}

UpLoadPostDetail BCDataManager::getUpLoadPostDetail() const
{
    return mUpLoadPostDetail;
}

UpLoadPostMaster BCDataManager::getUpLoadPostMaster() const
{
    return mUpLoadPostMaster;
}

UpLoadPublishPost BCDataManager::getUpLoadPublishPost() const
{
    return mUpLoadPublishPost;
}

UpLoadActivity BCDataManager::getUpLoadActivity() const
{
    return  mUpLoadActivity;
}

UpLoadActivityDetail BCDataManager::getUpLoadActivityDetail() const
{
    return mUpLoadActivityDetail;
}

UpLoadPublishActivity BCDataManager::getUpLoadPublishActivity() const
{
    return mUpLoadPublishActivity;
}

UpLoadMessage BCDataManager::getUpLoadMessage() const
{
    return mUpLoadMessage;
}

UpLoadChat BCDataManager::getUpLoadChat() const
{
    return mUpLoadChat;
}

UpLoadPersonalInformation BCDataManager::getUpLoadPersonalInformation() const
{
    return mUpLoadPersonalInformation;
}

UpLoadMineFocus BCDataManager::getUpLoadMineFocus() const
{
    return mUpLoadMineFocus;
}

UpLoadSearch BCDataManager::getUpLoadSearch() const
{
    return mUpLoadSearch;
}

BCDataManager::BCDataManager(QObject *parent)
    :QObject (parent)
{
    mAppDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
}

void BCDataManager::setCurrentLoginUserInfo(const user_info &currentLoginUserInfo)
{
    mCurrentLoginUserInfo = currentLoginUserInfo;
}

user_info BCDataManager::getCurrentLoginUserInfo() const
{
    return mCurrentLoginUserInfo;
}

QList<action_info> BCDataManager::getCurrentCatchActivitiesList() const
{
    return mCurrentCatchActivitiesList;
}

void BCDataManager::setCurrentCatchActivitiesList(const QList<action_info> &currentCatchActivitiesList)
{
    mCurrentCatchActivitiesList = currentCatchActivitiesList;
}

bool BCDataManager::checkUserInformaitonCatched(QString userId)
{
    return (mBCCatchUserInfoListMap.find(userId) != mBCCatchUserInfoListMap.end());
}

user_info BCDataManager::getPersonalInformationWithId(QString userId)
{
    return mBCCatchUserInfoListMap.value(userId);
}

void BCDataManager::addPersonalInformationToList(user_info user)
{
    mBCCatchUserInfoListMap[user.user_id.c_str()] = user;
}

QString BCDataManager::getCurrentCatchActivitiesLisAuthor() const
{
    return mCurrentCatchActivitiesLisAuthor;
}

void BCDataManager::setCurrentCatchActivitiesLisAuthor(const QString &currentCatchActivitiesLisAuthor)
{
    mCurrentCatchActivitiesLisAuthor = currentCatchActivitiesLisAuthor;
}

QList<article_info> BCDataManager::getCurrentCatchPostingList() const
{
    return mCurrentCatchArticlesList;
}

void BCDataManager::setCurrentCatchArticlesList(const QList<article_info> &currentCatchArticlesList)
{
    mCurrentCatchArticlesList = currentCatchArticlesList;
}

QString BCDataManager::getCurrentCatchPostingListAuthor() const
{
    return mCurrentCatchArticlesListAuthor;
}

void BCDataManager::setCurrentCatchArticlesListAuthor(const QString &currentCatchArticlesListAuthor)
{
    mCurrentCatchArticlesListAuthor = currentCatchArticlesListAuthor;
}

QMap<QString, interest_list> BCDataManager::getBCMineFocusListMap() const
{
    return mBCInterestListMap;
}

void BCDataManager::setBCInterestListMap(const QMap<QString, interest_list> &bCInterestListMap)
{
    mBCInterestListMap = bCInterestListMap;
}

QMap<QString, file_base_info> BCDataManager::getBCFileListMap() const
{
    return mBCFileListMap;
}

void BCDataManager::setBCFileListMap(const QMap<QString, file_base_info> &bCFileListMap)
{
    mBCFileListMap = bCFileListMap;
}

void BCDataManager::setBCCommentListMap(const QMap<QString, QMap<QString, message_info> > &bCCommentListMap)
{
    mBCCommentListMap = bCCommentListMap;
}

QMap<QString, action_info> BCDataManager::getBCActivitiesListMap() const
{
    return mBCActivitiesListMap;
}

void BCDataManager::setBCActivitiesListMap(const QMap<QString, action_info> &bCActivitiesListMap)
{
    mBCActivitiesListMap = bCActivitiesListMap;
}

QMap<QString, article_info> BCDataManager::getBCPostingListMap() const
{
    return mBCArticlesListMap;
}

void BCDataManager::setBCArticlesListMap(const QMap<QString, article_info> &bCArticlesListMap)
{
    mBCArticlesListMap = bCArticlesListMap;
}

QMap<QString, message_info> BCDataManager::getBCMessageListMap() const
{
    return mBCMessageListMap;
}

void BCDataManager::setBCMessageListMap(const QMap<QString, message_info> &bCMessageListMap)
{
    mBCMessageListMap = bCMessageListMap;
}

QMap<QString, QString> BCDataManager::getBCParentCityInfoMap() const
{
    return mBCParentCityInfoMap;
}

void BCDataManager::setBCParentCityInfoMap(const QMap<QString, QString> &bCParentCityInfoMap)
{
    mBCParentCityInfoMap = bCParentCityInfoMap;
}

void BCDataManager::setBCChildCityInfoMap(const QMap<QString, QMap<QString, QString> > &bCChildCityInfoMap)
{
    mBCChildCityInfoMap = bCChildCityInfoMap;
}

QMap<QString, QMap<QString, QString> > BCDataManager::getBCChildCityInfoMap() const
{
    return mBCChildCityInfoMap;
}
