#include "BCInputContentAndFileWidget.h"
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include <QFileIconProvider>
#include <QScrollBar>
#include "BCDataManager.h"
#include "BCToastTips.h"
#include "BCMessageManager.h"

BCInputContentAndFileWidget::BCInputContentAndFileWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

QString BCInputContentAndFileWidget::getContentText()
{
    return mContentTextEdit->document()->toPlainText();
}

void BCInputContentAndFileWidget::setAddFileButtonHide()
{
    mAddFileButton->hide();
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

void BCInputContentAndFileWidget::slotAddFileButtonClicked()
{
    QFileDialog fileDialog(this);//定义文件对话框类
    fileDialog.setWindowTitle((QStringLiteral("选择帖子附件")));//定义文件对话框标题
    fileDialog.setDirectory(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));//设置默认文件路径
    fileDialog.setNameFilter(tr("File(*.*)"));//设置文件过滤器
    fileDialog.setFileMode(QFileDialog::ExistingFiles);//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog.setViewMode(QFileDialog::List);//设置视图模式
    //打印所有选择的文件的路径
    if(fileDialog.exec())
    {
        QString fileName = fileDialog.selectedFiles()[0];
        QFile file(fileName);
        QFileInfo info(fileName);

        QString appDataPath = BCDataManager::instance().getAppDataPath() + "/posting/";
        QDir dir;
        dir.setPath(appDataPath);
        dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
        if(!dir.exists(appDataPath))
        {
            dir.mkpath(appDataPath);
        }
        QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
        int i = 1;
        QString newFileName;
        foreach (QFileInfo file, fileList) //遍历文件信息
        {
            if(file.isFile() && file.completeBaseName() == info.completeBaseName())
            {
                newFileName = appDataPath + "/" + info.baseName() + "(" + QString::number(i) + ")." + info.suffix();
            }
            else
            {
                newFileName = appDataPath + "/" + info.completeBaseName();
            }
        }

        if(file.copy(newFileName))
        {
            int insertKey = mFilePathMap.size() + 1;
            mFilePathMap[insertKey] = newFileName;
            BCDataManager::instance().setUploadFile(newFileName);
            emit doUploadFile(Page::BCPageEnum::UploadFile);
            if(mFilePathMap.size() == 3)
            {
                mAddFileButton->setVisible(false);
            }
            for(auto iter = mFileWidgetMap.begin(); iter != mFileWidgetMap.end(); iter++)
            {
                if(iter.key() == insertKey)
                {
                    iter.value()->setVisible(true);
                    iter.value()->setIcon(":/res/common/file.png");
                    iter.value()->setText(info.baseName());
                }
            }
        }
    }
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

    mFileWidget->setObjectName("mFileWidget");
    mFileWidget->setStyleSheet("QWidget#mFileWidget{"
                               "background-color:rgba(247,187,100,10);"
                               "}");
}

void BCInputContentAndFileWidget::initConnect()
{
    connect(mAddFileButton,&BCPolymorphicButton::clicked,this,&BCInputContentAndFileWidget::slotAddFileButtonClicked);
    connect(this,&BCInputContentAndFileWidget::doUploadFile,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
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
    mAddFileButton->setImageStyle(":/res/common/addFile.png");

    mFileHLayout->addWidget(mFirstFileWidget);
    mFileHLayout->addWidget(mSecondFileWidget);
    mFileHLayout->addWidget(mThirdFileWidget);
    mFileHLayout->addStretch(0);
    mFileHLayout->addWidget(mAddFileButton);

    mFileWidget->setLayout(mFileHLayout);

    mFirstFileWidget->setVisible(false);
    mSecondFileWidget->setVisible(false);
    mThirdFileWidget->setVisible(false);

    mFileWidgetMap[1] = mFirstFileWidget;
    mFileWidgetMap[2] = mSecondFileWidget;
    mFileWidgetMap[3] = mThirdFileWidget;
}
