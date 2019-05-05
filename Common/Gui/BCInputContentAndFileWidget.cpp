#include "BCInputContentAndFileWidget.h"
#include <QPainter>

BCInputContentAndFileWidget::BCInputContentAndFileWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCInputContentAndFileWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setPen(QPen(QColor(247,187,100),4));
    painter.setBrush(QColor(255,255,255));
    painter.drawRect(0,0,this->width(),this->height());
}

void BCInputContentAndFileWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mContentTextEdit->setFixedSize(this->width() - 8,this->height() - 128);
    mFileWidget->setFixedSize(this->width() - 8,120);

    mFirstFileWidget->setFixedHeight(120);
    mSecondFileWidget->setFixedHeight(120);
    mThirdFileWidget->setFixedHeight(120);
    mAddFileButton->setFixedSize(73,64);

    initStyle();
}

void BCInputContentAndFileWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);
    mMainVLayout->setContentsMargins(4,4,4,4);
    mMainVLayout->setSpacing(0);

    mContentTextEdit = new QTextEdit(this);
    mContentTextEdit->setPlaceholderText(QStringLiteral("输入内容"));
    createFileWidget();

    mMainVLayout->addWidget(mContentTextEdit);
    mMainVLayout->addWidget(mFileWidget);

    setLayout(mMainVLayout);
}

void BCInputContentAndFileWidget::initStyle()
{
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    mContentTextEdit->setFont(font);
    mContentTextEdit->setObjectName("mContentTextEdit");
    mContentTextEdit->setStyleSheet("QTextEdit#mContentTextEdit{"
                                    "background-color:rgba(247,187,100,10);"
                                    "border:0px;"
                                    "}");

    mFileWidget->setObjectName("mFileWidget");
    mFileWidget->setStyleSheet("QWidget#mFileWidget{"
                               "background-color:rgba(247,187,100,10);"
                               "}");
}

void BCInputContentAndFileWidget::initConnect()
{

}

void BCInputContentAndFileWidget::createFileWidget()
{
    mFileWidget = new QWidget(this);
    mFileHLayout = new QHBoxLayout(mFileWidget);
    mFileHLayout->setContentsMargins(20,0,20,0);
    mFileHLayout->setSpacing(30);

    mFirstFileWidget = new BCFileWidget(mFileWidget);
    mSecondFileWidget = new BCFileWidget(mFileWidget);
    mThirdFileWidget = new BCFileWidget(mFileWidget);
    mAddFileButton = new BCPolymorphicButton(mFileWidget);

    mFirstFileWidget->setIcon(":/res/common/file.png");
    mFirstFileWidget->setText(QStringLiteral("第一个"));

    mSecondFileWidget->setIcon(":/res/common/file.png");
    mSecondFileWidget->setText(QStringLiteral("第二个"));

    mThirdFileWidget->setIcon(":/res/common/file.png");
    mThirdFileWidget->setText(QStringLiteral("第三个"));

    mAddFileButton->setImageStyle(":/res/common/addFile.png");

    mFileHLayout->addWidget(mFirstFileWidget);
    mFileHLayout->addWidget(mSecondFileWidget);
    mFileHLayout->addWidget(mThirdFileWidget);
    mFileHLayout->addStretch(0);
    mFileHLayout->addWidget(mAddFileButton);

    mFileWidget->setLayout(mFileHLayout);
}
