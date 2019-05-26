#include "BCImageView.h"
#include <QPainter>
#include <QRegExp>
#include <QNetworkRequest>
#include <QFile>

BCImageView::BCImageView(QWidget *parent, bool isPressed)
    :QLabel(parent)
    ,isPressed_(isPressed)
{
    this->setScaledContents(true);
}

void BCImageView::setDefaultImage(QString strPath)
{
//    strPath = "http://192.168.1.3:8123/./static/1558862588.jpg";
    m_b_default_image_set = m_default_image.load(strPath);
    realReloadImage();
}

void BCImageView::setDefaultImage(QImage image)
{
    m_default_image = QPixmap::fromImage(image);
    m_b_default_image_set = true;
    realReloadImage();
}

void BCImageView::setDefaultImage(QPixmap pixmap)
{
    m_default_image = pixmap;
    m_b_default_image_set = true;
    realReloadImage();
}

void BCImageView::setImage(QString strPath)
{
    QRegExp rx(tr("[Hh][Tt][Tt][Pp][Ss]?://.+"));
    if(rx.exactMatch(strPath))
    {
        //网络图片
        loadNetImage(strPath);
    }else
    {
        //本地图片
        m_image_prepared = m_show_image.load(strPath);
        realReloadImage();
    }
}

void BCImageView::setImage(QImage image)
{
    m_show_image = QPixmap::fromImage(image);
    m_image_prepared = true;
    realReloadImage();
}

void BCImageView::setImage(QPixmap pixmap)
{
    m_show_image = pixmap;
    m_image_prepared = true;
    realReloadImage();
}

void BCImageView::setContentsMargins(int value)
{
    margin = value;
}

void BCImageView::setContentsMargins(int left, int top, int right, int bottom)
{
    QWidget::setContentsMargins(left,top,right,bottom);
}

void BCImageView::setContentsMargins(const QMargins &margins)
{
    QWidget::setContentsMargins(margins);
}

void BCImageView::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
}

void BCImageView::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event);
    if(this->margin)
    {
        auto w = this->size().width();
        auto h = this->size().height();

        uint fixed = qAbs(w-h)/2;

        //qDebug() << "CircleImage:" <<fixed;

        if(w > h)
        {
            QWidget::setContentsMargins(margin+fixed,margin,margin+fixed,margin);
        }else if(h > w)
        {
            QWidget::setContentsMargins(margin,margin+fixed,margin,margin+fixed);
        }else
        {
            QWidget::setContentsMargins(margin,margin,margin,margin);
        }
    }
}

void BCImageView::mousePressEvent(QMouseEvent *event)
{
    QLabel::mousePressEvent(event);
    if(isPressed_ == true)
    {
        emit clicked();
    }
}

void BCImageView::loadNetImage(QString uri)
{
    QNetworkRequest request;
    request.setUrl(uri);
    m_network_access_manager = new QNetworkAccessManager;
    connect(m_network_access_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(downloadFinish(QNetworkReply*)));
    m_network_access_manager->get(request);
}

void BCImageView::realReloadImage()
{
    QPixmap *pixmap = nullptr;
    if(!m_image_prepared){
        if(m_b_default_image_set){
            pixmap = &m_default_image;
        }
    }else
    {
        pixmap = &m_show_image;
    }
    if(pixmap){
        QPixmap tmp_pixmap(pixmap->size());
        tmp_pixmap.fill(Qt::transparent);
        QPainter painter(&tmp_pixmap);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        QPainterPath path;
        path.addEllipse(0, 0, pixmap->size().width(), pixmap->size().height());
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, pixmap->size().width(), pixmap->size().height(),*pixmap);
        setPixmap(tmp_pixmap);
    }

    update();
}

void BCImageView::downloadFinish(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        if(m_show_image.loadFromData(bytes))
        {
            m_image_prepared = true;
            realReloadImage();
            return;
        }

        //        QFile file("E:/head.jpg"); //这里需要修改成真实路径。。。 不修改也行。。。 就当以后不缓存了。。。
        //        if (file.open(QIODevice::WriteOnly))
        //        {
        //            file.write(bytes);
        //        }

        //        file.close();
        delete m_network_access_manager;
        m_network_access_manager = nullptr;
    }
}
