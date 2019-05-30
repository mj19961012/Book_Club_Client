#include "BCInputWidget.h"
#include <QPainter>
#include <QScrollBar>

BCInputWidget::BCInputWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCInputWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.1);
    painter.drawRoundedRect(0,0,this->width(),this->height(),20,20,Qt::AbsoluteSize);
}

void BCInputWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mSubmitButton->setFixedSize(100,30);

    initStyle();
}

void BCInputWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);
    mMainVLayout->setContentsMargins(5,5,5,5);
    mMainVLayout->setSpacing(0);

    mContentTextEdit = new QTextEdit(this);
    mContentTextEdit->setPlaceholderText(QStringLiteral("输入内容"));
    createButtonWidget();

    mMainVLayout->addWidget(mContentTextEdit,4);
    mMainVLayout->addWidget(mButtonWidget,1);

    setLayout(mMainVLayout);
}

void BCInputWidget::initStyle()
{
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    mContentTextEdit->setFont(font);
    mContentTextEdit->setObjectName("mContentTextEdit");
    mContentTextEdit->setStyleSheet("QTextEdit#mContentTextEdit{"
                                    "background-color:transparent;"
                                    "border:0px;"
                                    "}");
    mContentTextEdit->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
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

    mSubmitButton->setColorStyle("rgba(247,187,100,1)",
                                 "rgba(247,187,100,0.8)",
                                 "rgba(247,187,100,1)",
                                 "rgba(247,187,100,1)",
                                 "white",0,"transparent",15);
    mSubmitButton->setFontStyle(20);
    mSubmitButton->setText(QStringLiteral("发送"));
}

void BCInputWidget::initConnect()
{

}

void BCInputWidget::createButtonWidget()
{
    mButtonWidget = new QWidget(this);
    mButtonHLayout = new QHBoxLayout(mButtonWidget);
    mButtonHLayout->setMargin(0);
    mButtonHLayout->setSpacing(0);

    mSubmitButton = new BCPolymorphicButton(mButtonWidget);

    mButtonHLayout->addStretch(0);
    mButtonHLayout->addWidget(mSubmitButton);

    mButtonWidget->setLayout(mButtonHLayout);
}
