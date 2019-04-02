#ifndef BKCOMMONENUMDATA_H
#define BKCOMMONENUMDATA_H

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
        PersonalInformation,          //个人信息
        MineFocus,                    //我关注帖主的信息
        Search,                       //搜索
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
        MineInfo,                //个人信息主页
    };
}

#endif // BKCOMMONENUMDATA_H
