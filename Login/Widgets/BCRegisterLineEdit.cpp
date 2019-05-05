#include "BCRegisterLineEdit.h"

BCRegisterLineEdit::BCRegisterLineEdit(QWidget* parent)
    :QLineEdit(parent)
{
    init();
}

void BCRegisterLineEdit::init()
{
    setObjectName("BCRegisterLineEdit");
    setStyleSheet("QLineEdit#BCRegisterLineEdit{"
                  "background-color:white;"
                  "border:1px solid #333333;"
                  "border-radius:25px;"
                  "padding-left:25px;}");

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    setFont(font);
}
