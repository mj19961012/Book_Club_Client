#include "BCLoginWindow.h"
#include <QFont>
#include <QPainter>
#include <QPushButton>
#include <QApplication>
#include "BCLoginLineEdit.h"

BCLoginWindow::BCLoginWindow(QWidget *parent)
    :QMainWindow(parent)
{
    init();
    initConnect();
}

void BCLoginWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    QPixmap pixmap;
    pixmap.load(":/res/common/logo.png");
    painter.drawPixmap(305,46,96,100,pixmap.scaled(96,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(14);
    painter.setFont(font);
    painter.setPen(QPen(QColor(16,16,16),3));
    painter.drawText(0,161,this->width(),20,Qt::AlignCenter,QStringLiteral("学更多的知识，交更好的朋友，过更丰富的大学生活！"));
}

void BCLoginWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(22);
    font.setWeight(63);

    mLoginButton->setFont(font);

    mCloseButton->setGeometry(this->width() - 32,0,32,32);

    mUserPhoneLineEdit->setGeometry(201,210,308,40);
    mPasswordLineEdit->setGeometry(201,260,308,40);

    mLoginButton->setGeometry(241,330,228,40);
}

void BCLoginWindow::init()
{
    setFixedSize(710,420);
    setWindowFlags(Qt::FramelessWindowHint);
    setObjectName("BCLoginWindow");
    setStyleSheet("QWidget#BCLoginWindow{"
                  "background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 #FF6B95, stop:1 #FFC796);"
                  "border-radius:30px;"
                  "}");

    mCloseButton = new QPushButton(this);
    mCloseButton->setFocusPolicy(Qt::NoFocus);
    mCloseButton->setToolTip(QStringLiteral("关闭"));
    mCloseButton->setIcon(QIcon(":/res/Login/login_close.png"));
    mCloseButton->setIconSize(QSize(32,32));
    mCloseButton->setStyleSheet("background-color:transparent;");
    mCloseButton->raise();

    mUserPhoneLineEdit = new BCLoginLineEdit(this);
    mUserPhoneLineEdit->setImage(":/res/Login/phone.png");
    mUserPhoneLineEdit->setType(Login_LineEdit_Phone);
    mUserPhoneLineEdit->setMaxInputLength(11);
    mUserPhoneLineEdit->setTips(QStringLiteral("请输入手机号..."));

    mPasswordLineEdit = new BCLoginLineEdit(this);
    mPasswordLineEdit->setImage(":/res/Login/password.png");
    mPasswordLineEdit->setType(Login_LineEdit_Password);
    mPasswordLineEdit->setMaxInputLength(12);
    mPasswordLineEdit->setTips(QStringLiteral("请输入密码..."));

    mLoginButton = new QPushButton(this);
    mLoginButton->setFocusPolicy(Qt::NoFocus);
    mLoginButton->setText(QStringLiteral("登录"));
    mLoginButton->setToolTip(QStringLiteral("登录"));
    mLoginButton->setObjectName("mLoginButton");
    mLoginButton->setStyleSheet("QPushButton#mLoginButton{"
                                "background-color: rgb(230,184,18);"
                                "border-radius:20px;"
                                "}");
    mLoginButton->raise();
}

void BCLoginWindow::initConnect()
{
    connect(mCloseButton,&QPushButton::clicked,this,[](){
        qApp->exit();
    });
}
