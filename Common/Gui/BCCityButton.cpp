#include "BCCityButton.h"
#include <QPainter>

BCCityButton::BCCityButton(QWidget *parent)
    :QPushButton(parent)
{
    setObjectName("BCRegisterCityButton");
    setStyleSheet("QPushButton#BCRegisterCityButton{"
                  "background-color:white;"
                  "border:1px solid #333333;"
                  "border-radius:25px;"
                  "}");
}

void BCCityButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    painter.setFont(font);
    painter.setPen(QPen(QColor(149,149,149),2));
    painter.drawText(30,0,this->width() - 30,this->height(),Qt::AlignLeft | Qt::AlignVCenter,QStringLiteral("所在城市"));

    QPixmap pixmap;
    if(pixmap.load(":/res/Login/down.png"))
    {
        painter.drawPixmap(this->width() - 49,this->height()/2 - 16/2,28,16,pixmap);
    }
}
