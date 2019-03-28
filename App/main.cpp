#include "BCLoginWindow.h"
#include <QApplication>
#include <iostream>
#include "BCMessageManager.h"

int main(int argc, char *argv[])
{
//     QApplication a(argc, argv);
//     BCLoginWindow window;
//     window.show();


	QString phone_number = "19910120215";
	QString head_image = "/res/default.png";
	QString nick_name = "Jey";
	QString pass_word = "!Qaz1234";
	QString user_id = "boost::uuids::to_string(a_uuid);";
	QString city = "成都";
	QString school = "加里敦大学";

	BCMessageManager::getInstance()->BCRegistHandle(phone_number, pass_word, nick_name, school, head_image, city);

//    return a.exec();
	std::getchar();
    return 0;
}
