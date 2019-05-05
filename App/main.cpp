#include "BCMainWindow.h"
#include <QApplication>
#include <iostream>
#include "BCMessageManager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BCMainWindow::instance()->show();
    BCMainWindow::instance()->showBasePage(BasePage::Login);


//	QString phone_number = "19910120215";
//	QString head_image = "./res/common/logo.png";
//	QString nick_name = "Jey";
//	QString pass_word = "!Qaz1234";
//	QString user_id = "boost::uuids::to_string(a_uuid);";
//	QString city = "BeiJing";
//	QString school = "NCIST";


// 	BCMessageManager::getInstance()->BCGetMessageListHandle();


//    QString message_body = "BCMessageManager::getInstance()->BCSendMessageHandle()";
//    QString sender_id = "2c1d394d222493560df2c793d660a133";
//    QString accepter_id = "2c1d394d222493560df2c793d660a134";
//    QString session_id = "2c1d394d222493560df2c793d660a134";
//    int message_type = 1;
//    BCMessageManager::getInstance()->BCSendMessageHandle(message_body, sender_id, accepter_id, session_id, message_type);



// 	BCMessageManager::getInstance()->BCRegistHandle(phone_number, pass_word, nick_name, school, head_image, city);
// 
// 2c1d394d772493560df2c793d660a134
// 	BCMessageManager::getInstance()->BCUpLoadSimpleFile(head_image);
//	auto file = BCMessageManager::getInstance()->BCDownLoadSimpleFile("2c1d394d222493560df2c793d660a134");
//	qDebug() << "download_file_size:" << file.size() << "\n";
    return a.exec();
}
