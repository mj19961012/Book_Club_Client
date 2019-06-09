#include "BCMineUpdateInfoWidget.h"
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>
#include "BCDataManager.h"
#include "BCMessageManager.h"
#include "BCToastTips.h"

BCMineUpdateInfoWidget::BCMineUpdateInfoWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCMineUpdateInfoWidget::initData()
{
//    setImageView();
//    setName();
//    setCity();
//    setSchool();
//    setPhone();
//    setPassword();

    updateGeometry();
}

void BCMineUpdateInfoWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(255,255,255));
    painter.drawRoundedRect(0,0,this->width(),this->height(),40,40,Qt::AbsoluteSize);

    QFont font;
    font.setFamily("Microsoft Yahei");

    //Name tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,370,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请输入1~12位字符，支持数字、字母、数字和字母组合。"));

    //city tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,450,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请选择所在城市"));

    //school tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,530,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral(" 请输入2~12位字符，仅支持汉字。"));

    //phone tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,610,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请输入11位手机号码"));

    //password tips
    font.setPixelSize(15);
    font.setWeight(25);
    painter.setFont(font);
    painter.setPen(QPen(QColor(51,51,51),1));
    painter.drawText(this->width()/2 - 225,690,500,30,Qt::AlignLeft | Qt::AlignVCenter,
                     QStringLiteral("请输入6~12位字符，支持数字、字母、数字和字母组合。"));
}

void BCMineUpdateInfoWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    updateGeometry();
}

void BCMineUpdateInfoWidget::init()
{
    mCloseButton = new BCPolymorphicButton(this);

    mImageView = new BCImageView(this,true);
    mImageView->setImage("http://192.168.1.3:8123/./static/1558862588.jpg");

    mNameLineEdit = new BCInformationLineEdit(this);
    mNameLineEdit->setMaxLength(12);
    mNameLineEdit->setPlaceholderText(QStringLiteral("昵称"));

    mCityButton = new BCCityButton(this);

    mSchoolLineEdit = new BCInformationLineEdit(this);
    mSchoolLineEdit->setMaxLength(12);
    mSchoolLineEdit->setPlaceholderText(QStringLiteral("所在学校（选填）"));

    mPhoneLineEdit = new BCInformationLineEdit(this);
    mPhoneLineEdit->setMaxLength(11);
    mPhoneLineEdit->setPlaceholderText(QStringLiteral("手机号码"));

    mPasswordLineEdit = new BCInformationLineEdit(this);
    mPasswordLineEdit->setMaxLength(12);
    mPasswordLineEdit->setPlaceholderText(QStringLiteral("设置密码"));

    mUpdateButton = new BCPolymorphicButton(this);
    mUpdateButton->setText(QStringLiteral("修改"));
}

void BCMineUpdateInfoWidget::initStyle()
{
    mCloseButton->setImageStyle(":/res/common/registerClose.png");

    mImageView->setDefaultImage(":/res/common/defaultHeadImage.png");
    mImageView->setToolTip(QStringLiteral("从计算机中选择头像"));

    mUpdateButton->setColorStyle("rgba(247,187,100,1)",
                                   "rgba(247,187,100,0.8)",
                                   "rgba(247,187,100,1)",
                                   "rgba(247,187,100,1)",
                                   "white",0,"transparent",25);
    mUpdateButton->setFontStyle(20);
}

void BCMineUpdateInfoWidget::initConnect()
{
    connect(mCloseButton,&BCPolymorphicButton::clicked,this,&BCMineUpdateInfoWidget::sigEditInfoBack);
    connect(mUpdateButton,&BCPolymorphicButton::clicked,this,&BCMineUpdateInfoWidget::sigUpdateInfo);

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
                mImgPath = fileName;
            }
        }
    });
}

void BCMineUpdateInfoWidget::updateGeometry()
{
    mCloseButton->setGeometry(this->width() - 100,50,32,32);

    mImageView->setGeometry(this->width()/2 - 50,100,100,100);

    mNameLineEdit->setGeometry(this->width()/2 - 250,320,500,50);
    mCityButton->setGeometry(this->width()/2 - 250,400,500,50);
    mSchoolLineEdit->setGeometry(this->width()/2 - 250,480,500,50);
    mPhoneLineEdit->setGeometry(this->width()/2 - 250,560,500,50);
    mPasswordLineEdit->setGeometry(this->width()/2 - 250,640,500,50);

    mUpdateButton->setGeometry(this->width()/2 - 150,800,300,50);

    initStyle();
}

void BCMineUpdateInfoWidget::setImageView(const QString &image)
{
    mImageView->setImage(image);
}

void BCMineUpdateInfoWidget::setName(const QString &name)
{
    mNameLineEdit->setText(name);
}

void BCMineUpdateInfoWidget::setCity(const QString &city)
{
//    mNameLineEdit->setText(city);
}

void BCMineUpdateInfoWidget::setSchool(const QString &school)
{
    mSchoolLineEdit->setText(school);
}

void BCMineUpdateInfoWidget::setPhone(const QString &phone)
{
    mPhoneLineEdit->setText(phone);
}

void BCMineUpdateInfoWidget::setPassword(const QString &password)
{
    mPasswordLineEdit->setText(password);
}
