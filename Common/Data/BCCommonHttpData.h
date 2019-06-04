#ifndef BKCOMMONHTTPDATA_H
#define BKCOMMONHTTPDATA_H

#include <QString>


struct UpLoadPostings
{
    int type;
    int pagenum;
    int pagesize;
};

struct UpLoadPostDetail
{
    QString articleid;
};

struct UpLoadPostMaster
{
    QString userid;
    int pagenum;
    int pagesize;
};

struct UpLoadPublishPost
{
    QString title;
    QString content;
    int type;
};

struct UpLoadActivity
{
    QString begintime;
    QString endtime;
    QString selectcity;
    int pagenum;
    int pagesize;
};

struct UpLoadActivityDetail
{
    QString actionid;
};

struct UpLoadPublishActivity
{
    QString title;
    QString content;
    QString city;
    QString begintime;
    QString endtime;
    QString first;
    QString second;
    QString third;
};

struct UpLoadMessage
{
    QString accepterid;
    int messagetype;
};

struct UpLoadChat
{
    QString messgaebody;
    QString senderid;
    QString accepterid;
    QString sessionid;
    int messagetype;
};

struct UpLoadPersonalInformation
{
    QString username;
    QString password;
};

struct UpLoadMineFocus
{
    QString userid;
};

struct UpLoadSearch
{

};

struct UpLoadRegiest
{
    QString username;
    QString password;
    QString nickname;
    QString school;
    QString headimage;
    QString city;
};

struct UpLoadChangeMessageStatus
{
    QString messageId;
};

struct UploadFile
{
    QString filepath;
};

#endif // BKCOMMONHTTPDATA_H
