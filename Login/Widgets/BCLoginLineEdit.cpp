#include "BCLoginLineEdit.h"
#include <QPainter>
#include <QRegExpValidator>

BCLoginLineEdit::BCLoginLineEdit(QWidget *parent)
    :QWidget (parent)
    ,mMaxLength(0)
{
    init();
}

void BCLoginLineEdit::clear()
{
    mLineEdit->clear();
}

bool BCLoginLineEdit::isEmpty() const
{
    return mLineEdit->text().isEmpty();
}

bool BCLoginLineEdit::isMaxInputLength() const
{
    return mLineEdit->text().length() == mMaxLength ? true : false;
}

void BCLoginLineEdit::setType(BCLoginLineEditEnum type)
{
    switch(type)
    {
    case Login_LineEdit_Phone:
        mLineEdit->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$")));//只能输入数字
        mLineEdit->setEchoMode(QLineEdit::Normal);
        break;
    case Login_LineEdit_Password:
        mLineEdit->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z0-9]+$"))); //只能输入数字和字母
        mLineEdit->setEchoMode(QLineEdit::Password);
        break;
    }
}

void BCLoginLineEdit::setMaxInputLength(int length)
{
    mLineEdit->setMaxLength(length);
}

void BCLoginLineEdit::setTips(QString tips)
{
    mLineEdit->setPlaceholderText(tips);
}

QString BCLoginLineEdit::getInputText()
{
    return mLineEdit->text();
}

void BCLoginLineEdit::setImage(QString imgPath)
{
    mLabel->setPixmap(QPixmap(imgPath).scaled(32,32,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

void BCLoginLineEdit::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.3);
    painter.drawRoundedRect(0,0,this->width(),this->height(),this->height()/2,this->height()/2,Qt::AbsoluteSize);
}

void BCLoginLineEdit::init()
{
    mMainHLayout = new QHBoxLayout(this);

    mMainHLayout->setContentsMargins(20,0,this->height()/2,0);
    mMainHLayout->setSpacing(20);

    addIconLabel();
    addLineEdit();

    mMainHLayout->addWidget(mLabel);
    mMainHLayout->addWidget(mLineEdit);

    this->setLayout(mMainHLayout);
}

void BCLoginLineEdit::addIconLabel()
{
    mLabel = new QLabel(this);
    mLabel->setFixedSize(32,32);
}

void BCLoginLineEdit::addLineEdit()
{
    mLineEdit = new QLineEdit(this);
    mLineEdit->setFixedHeight(this->height());
    mLineEdit->setObjectName("mLineEdit");
    mLineEdit->setStyleSheet(QString("QLineEdit#mLineEdit{"
                                     "background:transparent;"
                                     "border:0px;"
                                     "}"));

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(20);
    mLineEdit->setFont(font);
}
