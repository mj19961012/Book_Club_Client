#include "BCPublishActivityWidget.h"
#include <QPainter>
#include <QDateTime>
#include "BCMainWindow.h"
#include "BCMessageManager.h"
#include "BCToastTips.h"
#include "BCDataManager.h"

BCPublishActivityWidget::BCPublishActivityWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCPublishActivityWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.drawRect(75,150,this->width() - 150,2);

    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(75,152,this->width() - 150,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请输入1~30位字符，支持数字、字母、汉字和特殊字符。"));

    font.setPixelSize(25);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(75,222,this->width() - 150,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("选择所在城市："));

    font.setPixelSize(25);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(75,292,this->width() - 150,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("选择活动时间："));

}

void BCPublishActivityWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mBackButton->setGeometry(75,25,50,50);
    mTitleLineEdit->setGeometry(75,100,this->width() - 150,50);
    mCityButton->setGeometry(250,222,this->width() - 525,30);
    mCityArrowButton->setGeometry(mCityButton->pos().x() + mCityButton->width(),222,200,30);
    mDateTimeButton->setGeometry(250,292,this->width() - 525,30);
    mDateTimeArrowButton->setGeometry(mDateTimeButton->pos().x() + mDateTimeButton->width(),292,200,30);
    mInputContentWidget->setGeometry(75,362,this->width() - 150,500);
    mPublishButton->setGeometry(this->width()/2 - 100,904,200,50);

    initStyle();
}

void BCPublishActivityWidget::slotPublishActivityBtnClicked()
{
    QString tital = mTitleLineEdit->text();
    QString content = mInputContentWidget->getContentText();
    QString begintime = QString::number(QDateTime::currentDateTime().toTime_t() - 24 * 3600 *7);
    QString endtime = QString::number(QDateTime::currentDateTime().toTime_t() + 24 * 3600 *7);
    QString city = "110000";
    QString first;
    QString second;
    QString third;
    switch (mBCUploadFilesList.size())
    {
        case 3:
        {
            third = mBCUploadFilesList[2];
        }
        case 2:
        {
            second = mBCUploadFilesList[1];
        }
        case 1:
        {
            first = mBCUploadFilesList[0];
        }
        default:
        {

        }
    }
    BCDataManager::instance().setUpLoadPublishActivity(tital,content,city,begintime,endtime,first,second,third);
    emit doPublishActivity(Page::PublishActivity);
}

void BCPublishActivityWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
{
    switch (pageEnum)
    {
        case Page::PublishActivity:
            {
                if(isSuccess)
                {
                    qDebug() << "Release Success" << "\n";
                    BCToastTips::Instance().setToastTip(QStringLiteral("尊敬的用户，恭喜您活动发布成功"));
                    BCMainWindow::instance()->showPage(Page::Activity);
                    emit doPublishActivity(Page::BCPageEnum::Activity);
                }
                else
                {
                    QString errorMsg = BCDataManager::instance().getErrorMsg();
                    BCToastTips::Instance().setToastTip(errorMsg);
                }
                break;
            }
        case Page::UploadFile:
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                if(isSuccess)
                {
                    qDebug() << "UploadFile Success" << "\n";
                    mBCUploadFilesList.push_back(errorMsg);
                    BCToastTips::Instance().setToastTip(QStringLiteral("尊敬的用户，恭喜您文件上传成功"));
                }
                else
                {
                    BCToastTips::Instance().setToastTip(errorMsg);
                }
                break;
            }
        default:
        {
            return;
        }
    }
}

void BCPublishActivityWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);

    mTitleLineEdit = new QLineEdit(this);
    mTitleLineEdit->setPlaceholderText(QStringLiteral("输入标题"));
    mTitleLineEdit->setMaxLength(30);

    mCityButton = new BCPolymorphicButton(this);
    mCityArrowButton = new BCPolymorphicButton(this);
    mCityArrowButton->setArrowType(Qt::DownArrow);
    mDateTimeButton = new BCPolymorphicButton(this);
    mDateTimeArrowButton = new BCPolymorphicButton(this);
    mDateTimeArrowButton->setArrowType(Qt::DownArrow);

    mInputContentWidget = new BCInputContentAndFileWidget(this);

    mPublishButton = new BCPolymorphicButton(this);
    mPublishButton->setText(QStringLiteral("发布活动"));

    mBCUploadFilesList.clear();
}

void BCPublishActivityWidget::initStyle()
{
    mBackButton->setImageStyle(":/res/common/back.png");

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    mTitleLineEdit->setFont(font);
    mTitleLineEdit->setObjectName("mTitleLineEdit");
    mTitleLineEdit->setStyleSheet("QLineEdit#mTitleLineEdit{"
                                  "background-color:rgba(247,187,100,10);"
                                  "border:0px;"
                                  "}");

    mPublishButton->setColorStyle("rgba(247,187,100,1)",
                                  "rgba(247,187,100,0.8)",
                                  "rgba(247,187,100,1)",
                                  "rgba(247,187,100,1)",
                                  "white",0,"transparent",25);
    mPublishButton->setFontStyle(20);
}

void BCPublishActivityWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::Activity);
    });
    connect(this,&BCPublishActivityWidget::doPublishActivity,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(mPublishButton,&BCPolymorphicButton::clicked,this,&BCPublishActivityWidget::slotPublishActivityBtnClicked);
    connect(BCMessageManager::getInstance(),&BCMessageManager::sendOperationResultSignal,this,&BCPublishActivityWidget::receiveOperationResult);
}
