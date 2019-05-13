#include "BCActivityWidget.h"
#include "BCMainWindow.h"

BCActivityWidget::BCActivityWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initStyle();
    initConnect();
}

void BCActivityWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCActivityWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mAddActivityButton->setGeometry(75,20,200,50);
}

void BCActivityWidget::init()
{
    mAddActivityButton = new BCPolymorphicButton(this);
}

void BCActivityWidget::initStyle()
{
    mAddActivityButton->setColorStyle("rgba(247,187,100,1)",
                                      "rgba(247,187,100,0.8)",
                                      "rgba(247,187,100,1)",
                                      "rgba(247,187,100,1)",
                                      "white",0,"transparent",25);
    mAddActivityButton->setFontStyle(25);
    mAddActivityButton->setButtonText(QStringLiteral("发布活动"));
}

void BCActivityWidget::initConnect()
{
    connect(mAddActivityButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::PublishActivity);
    });
}
