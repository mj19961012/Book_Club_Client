#include "BCActivityDetailWidget.h"
#include <QScrollBar>
#include "BCMainWindow.h"

BCActivityDetailWidget::BCActivityDetailWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();

    initData("");
}

void BCActivityDetailWidget::initData(const QString &text)
{
    setImage(QStringLiteral("http://192.168.1.3:8123/./static/1558976068.jpeg"));
    setName(QStringLiteral("人在塔在"));
    setActivityName(QStringLiteral("啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"));
    setCity(QStringLiteral("所在城市：杭州市"));
    setDate(QStringLiteral("活动时间：2018-5-20 至 2019-5-20"));
    setContent(QStringLiteral("啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"
                              "啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啊啦啦啦啦啦啦啦"));

    initGeometry();
}

void BCActivityDetailWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCActivityDetailWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    initGeometry();
}

void BCActivityDetailWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);
    mImageView = new BCImageView(this);
    mNameLabel = new BCPolymorphicLabel(this);
    mAttentionButton = new BCPolymorphicButton(this);

    mActivityNameLabel = new BCPolymorphicLabel(this);
    mCityLabel = new BCPolymorphicLabel(this);
    mDateTimeLabel = new BCPolymorphicLabel(this);

    mContentTextBrowser = new QTextBrowser(this);
}

void BCActivityDetailWidget::initStyle()
{
    mBackButton->setImageStyle(":/res/common/back.png");

    mImageView->setDefaultImage(":/res/common/defaultHeadImage.png");

    mNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mNameLabel->setFontStyle(30,75);

    mAttentionButton->setColorStyle("rgba(247,187,100,1)",
                                    "rgba(247,187,100,0.8)",
                                    "rgba(247,187,100,1)",
                                    "rgba(247,187,100,1)",
                                    "white",0,"transparent",24);
    mAttentionButton->setFontStyle(20);
    mAttentionButton->setText(QStringLiteral("关注"));

    mActivityNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mActivityNameLabel->setFontStyle(30,75);

    mCityLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mCityLabel->setFontStyle(18,25);

    mDateTimeLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mDateTimeLabel->setFontStyle(18,25);

    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(20);
    mContentTextBrowser->setFont(font);
    mContentTextBrowser->setObjectName("mContentLabel");
    mContentTextBrowser->setStyleSheet("QWidget#mContentLabel{"
                                       "border:0px;"
                                       "}");
    mContentTextBrowser->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
                                                            "width:8px;"
                                                            "background:rgba(0,0,0,0%);"
                                                            "margin:0px,0px,0px,0px;"
                                                            "padding-top:0px;"
                                                            "padding-bottom:0px;"
                                                            "}"
                                                            "QScrollBar::handle:vertical{"
                                                            "width:8px;"
                                                            "background:rgba(0,0,0,50%);"
                                                            "border-radius:4px;"
                                                            "min-height:20;"
                                                            "}"
                                                            "QScrollBar::add-line:vertical{"
                                                            "height:0px;width:0px;"
                                                            "subcontrol-position:bottom;"
                                                            "}"
                                                            "QScrollBar::sub-line:vertical{"
                                                            "height:0px;width:0px;"
                                                            "subcontrol-position:top;"
                                                            "}");
}

void BCActivityDetailWidget::initGeometry()
{
    initStyle();

    mBackButton->setGeometry(75,25,50,50);

    mImageView->setGeometry(75,100,100,100);
    mNameLabel->setMinimumHeight(100);
    mNameLabel->adjustSize();
    mNameLabel->move(mImageView->pos().x() + mImageView->width() + 20,100);
    mAttentionButton->setGeometry(this->width() - 175,125,100,50);

    mActivityNameLabel->adjustSize();
    mActivityNameLabel->move(75,210);
    mCityLabel->adjustSize();
    mCityLabel->move(75,mActivityNameLabel->pos().y() + mActivityNameLabel->height() + 10);
    mDateTimeLabel->adjustSize();
    mDateTimeLabel->move(mCityLabel->pos().x() + mCityLabel->width() + 20,
                         mActivityNameLabel->pos().y() + mActivityNameLabel->height() + 10);

    mContentTextBrowser->setGeometry(75,300,this->width() - 150,this->height() - 150);
}

void BCActivityDetailWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::Activity);
    });
}

void BCActivityDetailWidget::setImage(const QString &image)
{
    mImageView->setImage(image);
}

void BCActivityDetailWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCActivityDetailWidget::setActivityName(const QString &name)
{
    mActivityNameLabel->setText(name);
}

void BCActivityDetailWidget::setCity(const QString &city)
{
    mCityLabel->setText(city);
}

void BCActivityDetailWidget::setDate(const QString &date)
{
    mDateTimeLabel->setText(date);
}

void BCActivityDetailWidget::setContent(const QString &content)
{
    mContentTextBrowser->setText(content);
}
