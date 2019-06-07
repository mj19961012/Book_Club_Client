#ifndef BCDATAMANAGER_H
#define BCDATAMANAGER_H

#include <QObject>
#include <QList>
#include <QMap>
#include "BookClubEntity.hpp"
#include "BCCommonHttpData.h"

class BCDataManager : public QObject
{
    Q_OBJECT
public:
    static BCDataManager& instance();
    void release();

    /// \brief 获取AppData路径
    const QString& getAppDataPath();
    /// \brief 设置获取帖子主页帖子列表信息入参
    void setUpLoadPostings(int type);
    /// \brief 设置获取帖子主页帖子列表信息入参
    void setUpLoadPostings(int type, int pagenum);
    /// \brief 设置获取帖子主页帖子列表信息入参
    void setUpLoadPostings(int type, int pagenum,int pagesize);
    UpLoadPostings getUpLoadPostings() const;
    /// \brief 设置获取帖子详细信息入参
    void setUpLoadPostDetail(QString postid);
    UpLoadPostDetail getUpLoadPostDetail() const;
    /// \brief 设置获取帖子详情作者信息入参
    void setUpLoadPostMaster(QString userid);
    /// \brief 设置获取帖子详情作者信息入参
    void setUpLoadPostMaster(QString userid,int pagenum);
    /// \brief 设置获取帖子详情作者信息入参
    void setUpLoadPostMaster(QString userid,int pagenum,int pagesize);
    UpLoadPostMaster getUpLoadPostMaster() const;
    /// \brief 设置发布帖子入参
    void setUpLoadPublishPost(QString title,QString content,int type);
    UpLoadPublishPost getUpLoadPublishPost() const;
    /// \brief 设置获取活动主页活动列表信息入参
    void setUpLoadActivity(QString begintime, QString endtime, QString selectcity);
    /// \brief 设置获取活动主页活动列表信息入参
    void setUpLoadActivity(QString begintime, QString endtime, QString selectcity, int pagenum);
    /// \brief 设置获取活动主页活动列表信息入参
    void setUpLoadActivity(QString begintime, QString endtime, QString selectcity, int pagenum, int pagesize);
    UpLoadActivity getUpLoadActivity() const;
    /// \brief 设置获取活动详情信息入参
    void setUpLoadActivityDetail(QString articleid);
    UpLoadActivityDetail getUpLoadActivityDetail() const;
    /// \brief 设置发布活动入参
    void setUpLoadPublishActivity(QString title,QString content,QString city,QString begintime,QString endtime,QString first,QString second,QString third);
    UpLoadPublishActivity getUpLoadPublishActivity() const;
    /// \brief 设置获取未读消息列表信息入参
    void setUpLoadMessage(QString accepterId,int messageType);
    UpLoadMessage getUpLoadMessage() const;
    /// \brief 设置发送私信入参
    void setUpLoadChat(QString senderid, QString accepterid);
    void setUpLoadChat(QString messgaebody, QString senderid, QString accepterid, QString sessionid, int messagetype);
    UpLoadChat getUpLoadChat() const;
    /// \brief 设置获取个人信息入参
    void setUpLoadPersonalInformation(QString username,QString password);
    UpLoadPersonalInformation getUpLoadPersonalInformation() const;
    /// \brief 设置关注列表信息入参
    void setUpLoadMineFocus(QString userid);
    UpLoadMineFocus getUpLoadMineFocus() const;
    /// \brief 设置上传文件路径
    UploadFile getUploadFile() const;
    void setUploadFile(QString filepath);

    void setUpLoadSearch();
    UpLoadSearch getUpLoadSearch() const;

    /// \brief 设置注册用户入参
    void setUpLoadRegiest(QString username,QString password,QString nickname,QString school,QString headimage,QString city);
    UpLoadRegiest getUpLoadRegiest() const;

    /// \brief 获取二级城市列表
    QMap<QString, QMap<QString, QString> > getBCChildCityInfoMap() const;
    void setBCChildCityInfoMap(const QMap<QString, QMap<QString, QString> > &bCChildCityInfoMap);
    /// \brief 获取一级城市列表
    QMap<QString, QString> getBCParentCityInfoMap() const;
    void setBCParentCityInfoMap(const QMap<QString, QString> &bCParentCityInfoMap);
    /// \brief 私信消息列表
    QMap<QString, message_info> getBCMessageListMap(QString sessionId) const;
    QMap<QString, message_info> getBCMessageListMap() const;
    void setBCMessageListMap(const QMap<QString, message_info> &bCMessageListMap);
    /// \brief 帖子主页帖子列表信息
    QMap<QString, article_info> getBCPostingListMap() const;
    /// \brief 帖子详情信息
    article_info getPostingInfoWithId(QString postId);
    void setBCArticlesListMap(const QMap<QString, article_info> &bCArticlesListMap);
    /// \brief 活动主页活动列表信息
    QMap<QString, action_info> getBCActivitiesListMap() const;
    action_info getActionInfoWithId(QString actionId);
    void setBCActivitiesListMap(const QMap<QString, action_info> &bCActivitiesListMap);
    /// \brief 回复信息列表
    QMap<QString, message_info>getBCCommentListMap(QString postId) const;
    void setBCCommentListMap(const QMap<QString, QMap<QString, message_info> > &bCCommentListMap);
    /// \brief 文件信息列表
    QMap<QString, file_base_info> getBCFileListMap() const;
    void setBCFileListMap(const QMap<QString, file_base_info> &bCFileListMap);
    /// \brief 关注信息列表
    QMap<QString, interest_list> getBCMineFocusListMap() const;
    void setBCInterestListMap(const QMap<QString, interest_list> &bCInterestListMap);
    /// \brief 查看他人主页时缓存对应发布者的ID
    QString getCurrentCatchPostingListAuthor() const;
    void setCurrentCatchArticlesListAuthor(const QString &currentCatchArticlesListAuthor);
    /// \brief 他人发布的帖子列表(查看他人主页信息)
    QList<article_info> getCurrentCatchPostingList() const;
    void setCurrentCatchArticlesList(const QList<article_info> &currentCatchArticlesList);
    /// \brief 查看他人活动时缓存对应发布者的ID
    QString getCurrentCatchActivitiesLisAuthor() const;
    void setCurrentCatchActivitiesLisAuthor(const QString &currentCatchActivitiesLisAuthor);
    /// \brief 他人发布的活动列表(查看他人主页信息)
    QList<action_info> getCurrentCatchActivitiesList() const;
    void setCurrentCatchActivitiesList(const QList<action_info> &currentCatchActivitiesList);

    bool checkUserInformaitonCatched(QString userId);
    user_info getPersonalInformationWithId(QString userId);
    void addPersonalInformationToList(user_info user);

    user_info getCurrentLoginUserInfo() const;
    void setCurrentLoginUserInfo(const user_info &currentLoginUserInfo);

    QString getErrorMsg() const;
    void setErrorMsg(const QString &errorMsg);

    void Lock();
    void UnLock();
    bool isLock();

    QString getBCCityNameWithId(QString cId) const;
    void setBCCityIdToName(const QMap<QString, QString> &bCCityIdToName);

private:
    explicit BCDataManager(QObject *parent = nullptr);
    static BCDataManager *sDataManager;

private:
    QString mAppDataPath{""};

    UpLoadPostings mUpLoadPostings;
    UpLoadPostDetail mUpLoadPostDetail;
    UpLoadPostMaster mUpLoadPostMaster;
    UpLoadPublishPost mUpLoadPublishPost;
    UpLoadActivity mUpLoadActivity;
    UpLoadActivityDetail mUpLoadActivityDetail;
    UpLoadPublishActivity mUpLoadPublishActivity;
    UpLoadMessage mUpLoadMessage;
    UpLoadChat mUpLoadChat;
    UpLoadPersonalInformation mUpLoadPersonalInformation;
    UpLoadMineFocus mUpLoadMineFocus;
    UpLoadSearch mUpLoadSearch;
    UpLoadRegiest mUpLoadRegiest;
    UploadFile mUploadFile;

    QMap<QString, QMap<QString,QString>> mBCChildCityInfoMap;
    QMap<QString, QString> mBCParentCityInfoMap;
    QMap<QString, QString> mBCCityIdToName;
    QMap<QString, QMap<QString, message_info>> mBCMessageListMap;
    QMap<QString, article_info> mBCArticlesListMap;
    QMap<QString, action_info> mBCActivitiesListMap;
    QMap<QString, QMap<QString, message_info>> mBCCommentListMap;
    QMap<QString, file_base_info> mBCFileListMap;
    QMap<QString, interest_list> mBCInterestListMap;

    QMap<QString, user_info> mBCCatchUserInfoListMap;

    QString mCurrentCatchArticlesListAuthor;
    QList<article_info> mCurrentCatchArticlesList;

    QString mCurrentCatchActivitiesLisAuthor;
    QList<action_info> mCurrentCatchActivitiesList;

    user_info mCurrentLoginUserInfo;

    QString mErrorMsg;
    bool isLocked;
};

#endif // BCDATAMANAGER_H
