#include "BCRegisterWidget.h"
#include "BCPolymorphicButton.h"
#include <QPainter>

BCRegisterWidget::BCRegisterWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCRegisterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(255,255,255));
    painter.drawRoundedRect(0,0,this->width(),this->height(),40,40,Qt::AbsoluteSize);

    QPixmap pixmap;
    pixmap.load(":/res/common/logo.png");
    painter.drawPixmap(this->width()/2 - 168/2,20,48,50,pixmap.scaled(48,50,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(25);
    font.setWeight(25);

    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 12,20,100,50,Qt::AlignCenter,QStringLiteral("用户注册"));
}

void BCRegisterWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mCloseButton->setGeometry(this->width() - 70,20,50,50);

    initStyle();
}

void BCRegisterWidget::init()
{
    mCloseButton = new BCPolymorphicButton(this);
}

void BCRegisterWidget::initStyle()
{
    mCloseButton->setImageStyle(":/res/common/registerClose.png");
}

void BCRegisterWidget::initConnect()
{
    connect(mCloseButton,&BCPolymorphicButton::clicked,this,[this](){
        emit sigRegisterCloseButtonClicked();
    });
}
