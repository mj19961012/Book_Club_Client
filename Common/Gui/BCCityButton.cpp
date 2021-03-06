﻿#include "BCCityButton.h"
#include <QPainter>
#include <QMenu>
#include <QAction>

BCCityButton::BCCityButton(QWidget *parent)
    :QToolButton(parent)
{
    init();
    initStyle();
}

void BCCityButton::initData(const QString& text)
{
    setButtonText(text);

    QMenu *menu = new QMenu();

    menu->addAction(QStringLiteral("全部"));
    for(int i = 0; i < 10; i++)
    {
        menu->addAction(QString::number(i));
    }

    this->setMenu(menu);
    initConnect();
}

void BCCityButton::paintEvent(QPaintEvent *event)
{
    QToolButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    painter.setFont(font);
    painter.setPen(QPen(QColor(149,149,149),2));
    painter.drawText(30,0,this->width() - 30,this->height(),Qt::AlignLeft | Qt::AlignVCenter,mButtonText);

    QPixmap pixmap;
    if(pixmap.load(":/res/Login/down.png"))
    {
        painter.drawPixmap(this->width() - 49,this->height()/2 - 16/2,28,16,pixmap);
    }
}

void BCCityButton::init()
{
    setObjectName("BCRegisterCityButton");
    setStyleSheet("QToolButton#BCRegisterCityButton{"
                  "background-color:white;"
                  "border:1px solid #333333;"
                  "border-radius:25px;"
                  "}"
                  "QToolButton::menu-indicator{"
                  "image: none;"
                  "}");
    setPopupMode(QToolButton::InstantPopup);
}

void BCCityButton::initStyle()
{
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    this->setFont(font);
}

void BCCityButton::initConnect()
{
    connect(this->menu(),&QMenu::triggered,this,[this](QAction *action){
        this->setText(action->text());
        emit sigSelectCity();
    });
}

void BCCityButton::setButtonText(const QString &text)
{
    mButtonText = text;
}
