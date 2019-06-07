#include "BCPostingDetailItemWidget.h"
#include <QPainter>
#include <QScrollBar>
#include <QDateTime>
#include "BCDataManager.h"

BCPostingDetailItemWidget::BCPostingDetailItemWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
}

void BCPostingDetailItemWidget::initData(const QString &id)
{
    auto post = BCDataManager::instance().getPostingInfoWithId(id);
    auto user = BCDataManager::instance().getPersonalInformationWithId(post.getauthorId().c_str());
    setName(post.getarticleTitle().c_str());
    setAuthorHeadImage(user.getheadImage().c_str());
    setAuthorName(user.getnickName().c_str());
    setReadCount(QString::number(post.getpageView()));
    setDateTime(QDateTime::fromTime_t(QString::fromStdString(post.getreleaseTime()).toUInt()).toString("yyyy-MM-dd hh:mm:ss"));
    setContent(post.getarticleContent().c_str());
    setComment(QStringLiteral("（已有") + QString::number(65535) + QStringLiteral("条评论）"));

    initStyle();
    initGeometry();
}

void BCPostingDetailItemWidget::setListWidgetItem(QListWidgetItem* item)
{
    mCurrentItem = item;
}

QListWidgetItem *BCPostingDetailItemWidget::getListWidgetItem() const
{
    return mCurrentItem;
}

void BCPostingDetailItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCPostingDetailItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    initGeometry();
}

void BCPostingDetailItemWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);

    mNameLabel = new BCPolymorphicLabel(this);
    createPropertyWidget();
    mContentTextBrowser = new QTextBrowser(this);
    mPublishCommentLabel = new BCPolymorphicLabel(this);
    mPublishCommentWidget = new BCInputWidget(this);
    mCommentLabel = new BCPolymorphicLabel(this);

    mMainVLayout->addWidget(mNameLabel);
    mMainVLayout->addWidget(mPropertyWidget);
    mMainVLayout->addWidget(mContentTextBrowser);
    mMainVLayout->addWidget(mPublishCommentLabel);
    mMainVLayout->addWidget(mPublishCommentWidget);
    mMainVLayout->addWidget(mCommentLabel);

    this->setLayout(mMainVLayout);
}

void BCPostingDetailItemWidget::initStyle()
{
    mNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mNameLabel->setFontStyle(30,75);

    mAuthorHeadImageLabel->setPixmap(QPixmap(":/res/common/defaultHeadImage.png"));
    mAuthorHeadImageLabel->setScaledContents(true);

    mAuthorNameLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mAuthorNameLabel->setFontStyle(20,63);

    mReadCountLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mReadCountLabel->setFontStyle(15,25);

    mDateTimeLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mDateTimeLabel->setFontStyle(15,25);

    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(20);
    mContentTextBrowser->setFont(font);
    mContentTextBrowser->setObjectName("mContentLabel");
    mContentTextBrowser->setStyleSheet("QWidget#mContentLabel{border:0px;}");
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

    mPublishCommentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mPublishCommentLabel->setFontStyle(15,25);
    mPublishCommentLabel->setText(QStringLiteral("发表评论"));

    mCommentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mCommentLabel->setFontStyle(15,25);
}

void BCPostingDetailItemWidget::initGeometry()
{
    mMainVLayout->setMargin(5);
    mMainVLayout->setSpacing(20);

    mPropertyHLayout->setContentsMargins(0,0,20,0);
    mPropertyHLayout->setSpacing(30);

    mPropertyWidget->setFixedHeight(60);
    mAuthorHeadImageLabel->setFixedSize(60,60);
    mNameLabel->setFixedHeight(30);
    mPublishCommentWidget->setFixedHeight(150);
    mCommentLabel->setFixedHeight(20);
    mContentTextBrowser->setFixedHeight(700);

    mNameLabel->adjustSize();
    mAuthorNameLabel->adjustSize();
    mReadCountLabel->adjustSize();
    mContentTextBrowser->adjustSize();
    mDateTimeLabel->adjustSize();
    mCommentLabel->adjustSize();
}

void BCPostingDetailItemWidget::createPropertyWidget()
{
    mPropertyWidget = new QWidget(this);
    mPropertyHLayout = new QHBoxLayout(mPropertyWidget);

    mAuthorHeadImageLabel = new BCPolymorphicLabel(mPropertyWidget);
    mAuthorNameLabel = new BCPolymorphicLabel(mPropertyWidget);
    mReadCountLabel = new BCPolymorphicLabel(mPropertyWidget);
    mDateTimeLabel = new BCPolymorphicLabel(mPropertyWidget);

    mPropertyHLayout->addWidget(mAuthorHeadImageLabel);
    mPropertyHLayout->addWidget(mAuthorNameLabel);
    mPropertyHLayout->addStretch(0);
    mPropertyHLayout->addWidget(mReadCountLabel);
    mPropertyHLayout->addWidget(mDateTimeLabel);

    mPropertyWidget->setLayout(mPropertyHLayout);
}

void BCPostingDetailItemWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCPostingDetailItemWidget::setAuthorHeadImage(const QString &image)
{
    mAuthorHeadImageLabel->setText(image);
}

void BCPostingDetailItemWidget::setAuthorName(const QString &name)
{
    mAuthorNameLabel->setText(name);
}

void BCPostingDetailItemWidget::setReadCount(const QString &count)
{
    mReadCountLabel->setText(count);
}

void BCPostingDetailItemWidget::setDateTime(const QString &dateTime)
{
    mDateTimeLabel->setText(dateTime);
}

void BCPostingDetailItemWidget::setContent(const QString &content)
{
    mContentTextBrowser->setText(content);
}

void BCPostingDetailItemWidget::setComment(const QString &comment)
{
    mCommentLabel->setText(comment);
}
