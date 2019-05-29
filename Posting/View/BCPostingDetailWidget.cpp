#include "BCPostingDetailWidget.h"
#include <QPainter>
#include "BCMainWindow.h"

BCPostingDetailWidget::BCPostingDetailWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCPostingDetailWidget::initData()
{
    mDetailWidget->addListItem(ListItem::PostingDetail);
}

void BCPostingDetailWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCPostingDetailWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mBackButton->setGeometry(75,25,50,50);
    mDetailWidget->setGeometry(75,100,this->width() - 150,this->height() - 100);

    initStyle();
}

void BCPostingDetailWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);
    mDetailWidget = new BCListWidget(this);
}

void BCPostingDetailWidget::initStyle()
{
    mBackButton->setImageStyle(":/res/common/back.png");
}

void BCPostingDetailWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::Postings);
    });
}
