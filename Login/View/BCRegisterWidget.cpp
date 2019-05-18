#include "BCRegisterWidget.h"
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>
#include "BCDataManager.h"

BCRegisterWidget::BCRegisterWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCRegisterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(255,255,255));
    painter.drawRoundedRect(0,0,this->width(),this->height(),40,40,Qt::AbsoluteSize);

    QPixmap pixmap;
    pixmap.load(":/res/common/start_logo.png");
    painter.drawPixmap(this->width()/2 - 168/2,20,48,50,pixmap.scaled(48,50,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(25);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 12,20,100,50,Qt::AlignCenter,QStringLiteral("用户注册"));

    //Name tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,270,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请输入1~12位字符，支持数字、字母、数字和字母组合。"));

    //city tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,350,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请选择所在城市"));

    //school tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,430,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral(" 请输入2~12位字符，仅支持汉字。"));

    //phone tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,510,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请输入11位手机号码"));

    //password tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,590,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请输入6~12位字符，支持数字、字母、数字和字母组合。"));
}

void BCRegisterWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mCloseButton->setGeometry(this->width() - 70,25,32,32);

    mImageView->setGeometry(this->width()/2 - 50,100,100,100);

    mNameLineEdit->setGeometry(this->width()/2 - 250,220,500,50);
    mCityButton->setGeometry(this->width()/2 - 250,300,500,50);
    mSchoolLineEdit->setGeometry(this->width()/2 - 250,380,500,50);
    mPhoneLineEdit->setGeometry(this->width()/2 - 250,460,500,50);
    mPasswordLineEdit->setGeometry(this->width()/2 - 250,540,500,50);

    mRegisterButton->setGeometry(this->width()/2 - 150,630,300,50);

    initStyle();
}

void BCRegisterWidget::init()
{
    mCloseButton = new BCPolymorphicButton(this);

    mImageView = new BCImageView(this,true);

    mNameLineEdit = new BCInformationLineEdit(this);
    mNameLineEdit->setMaxLength(12);
    mNameLineEdit->setPlaceholderText(QStringLiteral("昵称"));

    mCityButton = new BCRegisterCityButton(this);

    mSchoolLineEdit = new BCInformationLineEdit(this);
    mSchoolLineEdit->setMaxLength(12);
    mSchoolLineEdit->setPlaceholderText(QStringLiteral("所在学校（选填）"));

    mPhoneLineEdit = new BCInformationLineEdit(this);
    mPhoneLineEdit->setMaxLength(11);
    mPhoneLineEdit->setPlaceholderText(QStringLiteral("手机号码"));

    mPasswordLineEdit = new BCInformationLineEdit(this);
    mPasswordLineEdit->setMaxLength(12);
    mPasswordLineEdit->setPlaceholderText(QStringLiteral("设置密码"));

    mRegisterButton = new BCPolymorphicButton(this);
    mRegisterButton->setText(QStringLiteral("注册"));
}

void BCRegisterWidget::initStyle()
{
    mCloseButton->setImageStyle(":/res/common/registerClose.png");

    mImageView->setDefaultImage(":/res/common/defaultHeadImage.png");
    mImageView->setToolTip(QStringLiteral("从计算机中选择头像"));

    mRegisterButton->setColorStyle("rgba(247,187,100,1)",
                                   "rgba(247,187,100,0.8)",
                                   "rgba(247,187,100,1)",
                                   "rgba(247,187,100,1)",
                                   "white",0,"transparent",25);
    mRegisterButton->setFontStyle(20);
}

void BCRegisterWidget::initConnect()
{
    connect(mCloseButton,&BCPolymorphicButton::clicked,this,[this](){
        emit sigRegisterCloseButtonClicked();
    });

    connect(mImageView,&BCImageView::clicked,this,[this](){
        QFileDialog fileDialog(this);//定义文件对话框类
        fileDialog.setWindowTitle((QStringLiteral("打开图片")));//定义文件对话框标题
        fileDialog.setDirectory(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));//设置默认文件路径
        fileDialog.setNameFilter(tr("Images(*.png;*.jpg;*.jpeg)"));//设置文件过滤器
        fileDialog.setFileMode(QFileDialog::ExistingFiles);//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
        fileDialog.setViewMode(QFileDialog::List);//设置视图模式
        //打印所有选择的文件的路径
        if(fileDialog.exec())
        {
            QString fileName = fileDialog.selectedFiles()[0];
            QImage image;
            QPixmap pixmap;
            if(image.load(fileName))
            {
                pixmap = QPixmap::fromImage(image.scaled(mImageView->size(),Qt::KeepAspectRatio));
                QString path = BCDataManager::instance().getAppDataPath() + "/HeadImage.png";
                if(pixmap.save(path))
                {
                    qDebug() << "头像保存成功，路径为：" << path;
                    mImageView->setImage(pixmap);
                }
            }
        }
    });
}
