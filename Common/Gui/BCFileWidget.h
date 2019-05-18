#ifndef BCFILEWIDGET_H
#define BCFILEWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCFileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCFileWidget(QWidget *parent = nullptr);
    void setIcon(const QString& icon);
    void setIcon(const QPixmap& pixmap);
    void setText(const QString& text);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void createIconWidget();

private:
    QWidget *mIconWidget{};
    BCPolymorphicLabel *mIconLabel{};
    BCPolymorphicLabel *mNameLabel{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mIconHLayout{};
};

#endif // BCFILEWIDGET_H
