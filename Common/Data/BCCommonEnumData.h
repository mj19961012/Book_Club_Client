﻿#ifndef BCCOMMONENUMDATA_H
#define BCCOMMONENUMDATA_H

namespace BasePage
{
enum BCBasePageEnum
{
    Login,
    MainWindow,
};
}

namespace Page
{
/// \brief 窗口
enum BCPageEnum
{
    Postings,                     //帖子主页
    PostDetail,                   //帖子详情
    PostMaster,                   //帖主
    PublishPost,                  //发布帖子
    Activity,                     //活动主页
    ActivityDetail,               //活动详情
    PublishActivity,              //发布活动
    Message,                      //消息主页
    Chat,                         //私信聊天
    PersonalInformation,          //个人信息（登陆）
    MineFocus,                    //我关注帖主的信息
    Search,                       //搜索
    Init,                         //初始化
    Regiest,                      //注册
    ChangeMessageStatus,          //变更消息状态
    UploadFile,                   //上传文件
    Interest,                     //关注
    CancleInterest,               //取消关注
};
}

namespace NavigationBar
{
enum BCNavigationBarEnum
{
    Postings,                //帖子主页
    Activity,                //活动主页
    Message,                 //消息主页
    Search,                  //搜索
    PersonalInformation,     //个人信息主页
};
}

namespace Subject
{
enum BCSubjectEnum
{
    /// \brief 全部
    All = 1,
    /// \brief 经济学
    Economics,
    /// \brief 法学
    Law,
    /// \brief 工学
    Engineering,
    /// \brief 教育学
    Pedagogy,
    /// \brief 文学
    Literature,
    /// \brief 历史学
    History,
    /// \brief 哲学
    Philosophy,
    /// \brief 理学
    Science,
    /// \brief 农学
    Agronomy,
    /// \brief 艺术学
    ArtTheory,
    /// \brief 管理学
    Management,
    /// \brief 军事学
    MilitaryScience,
    /// \brief 医学
    Medicine,
};
}

namespace ListItem
{
enum BCListWidgetType
{
    Posting,              //帖子列表item
    PostingDetail,
    Activity,             //活动列表item
    MinePosting,
    MineAvtivity,
    MineFollowed,
    MessageChat,
    MessagePosting,
    MessageChatBubble,
    MineFollowMasterPostings,
    MineFollowMasterActivity,
};
}

#endif // BCCOMMONENUMDATA_H
