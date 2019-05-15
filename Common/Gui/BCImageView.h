#ifndef BCIMAGEVIEW_H
#define BCIMAGEVIEW_H

#include <QLabel>
#include <QString>
#include <QPaintEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMouseEvent>

class BCImageView : public QLabel
{
    Q_OBJECT
public:
    explicit BCImageView(QWidget *parent = nullptr,bool Clicked = false);

    void setDefaultImage(QString strPath);
    void setDefaultImage(QImage image);
    void setDefaultImage(QPixmap pixmap);

    void setImage(QString strPath);
    void setImage(QImage image);
    void setImage(QPixmap pixmap);

    void setContentsMargins(int value);
    void setContentsMargins(int left, int top, int right, int bottom);
    void setContentsMargins(const QMargins &margins);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void loadNetImage(QString uri);
    void realReloadImage();

signals:
    void clicked();

public slots:
    void downloadFinish(QNetworkReply *reply);

protected:
    QPixmap m_default_image;
    QPixmap m_show_image;
    bool m_b_default_image_set = false;
    bool m_image_prepared = false;
    unsigned int margin = 0;
    QNetworkAccessManager *m_network_access_manager = nullptr;
    bool isPressed_;
};

#endif // BCIMAGEVIEW_H
