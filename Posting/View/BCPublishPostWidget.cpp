#include "BCPublishPostWidget.h"
#include <QPainter>
#include "BCMainWindow.h"

BCPublishPostWidget::BCPublishPostWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
    setButtonText();
}

void BCPublishPostWidget::paintEvent(QPaintEvent *event)
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
                     QStringLiteral("选择学科分类"));
}

void BCPublishPostWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mBackButton->setGeometry(75,25,50,50);
    mTitleLineEdit->setGeometry(75,100,this->width() - 150,50);

    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        iter.value()->setFixedSize(100,40);
        mSubjectButtonMap.value(iter.key())->move(75 + (iter.key() - 1)*(iter.value()->width() + 5),270);
    }

    mInputContentWidget->setGeometry(75,350,this->width() - 150,500);

    mPublishButton->setGeometry(this->width()/2 - 100,892,200,50);

    initStyle();
}

void BCPublishPostWidget::slotSubjectBtnClicked()
{
    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        if(sender() == iter.value())
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(247,187,100)",20,1,"rgb(247,187,100)");
        }
        else
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(51,51,51)",20,1,"rgb(51,51,51)");
        }
    }
}

void BCPublishPostWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);

    mTitleLineEdit = new QLineEdit(this);
    mTitleLineEdit->setPlaceholderText(QStringLiteral("输入标题"));
    mTitleLineEdit->setMaxLength(30);

    for(int i = 1; i <=14; i++)
    {
        BCPolymorphicButton *button = new BCPolymorphicButton(this);
        connect(button,&BCPolymorphicButton::clicked,this,&BCPublishPostWidget::slotSubjectBtnClicked);
        mSubjectButtonMap[i] = button;
    }

    mInputContentWidget = new BCInputContentAndFileWidget(this);

    mPublishButton = new BCPolymorphicButton(this);
    mPublishButton->setText(QStringLiteral("发布帖子"));
}

void BCPublishPostWidget::initStyle()
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

    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        if(iter.key() == Subject::All)
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(247,187,100)",20,1,"rgb(247,187,100)");
        }
        else
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(51,51,51)",20,1,"rgb(51,51,51)");
        }
        iter.value()->setFontStyle(20);
    }



    mPublishButton->setColorStyle("rgba(247,187,100,1)",
                                  "rgba(247,187,100,0.8)",
                                  "rgba(247,187,100,1)",
                                  "rgba(247,187,100,1)",
                                  "white",25,0,"transparent");
    mPublishButton->setFontStyle(20);
}

void BCPublishPostWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::Postings);
    });
}

void BCPublishPostWidget::setButtonText()
{
    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        switch(iter.key())
        {
        case Subject::All:
            iter.value()->setText(QStringLiteral("全部"));
            break;
        case Subject::Economics:
            iter.value()->setText(QStringLiteral("经济学"));
            break;
        case Subject::Law:
            iter.value()->setText(QStringLiteral("法学"));
            break;
        case Subject::Engineering:
            iter.value()->setText(QStringLiteral("工学"));
            break;
        case Subject::Pedagogy:
            iter.value()->setText(QStringLiteral("教育学"));
            break;
        case Subject::Literature:
            iter.value()->setText(QStringLiteral("文学"));
            break;
        case Subject::History:
            iter.value()->setText(QStringLiteral("历史学"));
            break;
        case Subject::Philosophy:
            iter.value()->setText(QStringLiteral("哲学"));
            break;
        case Subject::Science:
            iter.value()->setText(QStringLiteral("理学"));
            break;
        case Subject::Agronomy:
            iter.value()->setText(QStringLiteral("农学"));
            break;
        case Subject::ArtTheory:
            iter.value()->setText(QStringLiteral("艺术学"));
            break;
        case Subject::Management:
            iter.value()->setText(QStringLiteral("管理学"));
            break;
        case Subject::MilitaryScience:
            iter.value()->setText(QStringLiteral("军事学"));
            break;
        case Subject::Medicine:
            iter.value()->setText(QStringLiteral("医学"));
            break;
        }
    }
}
