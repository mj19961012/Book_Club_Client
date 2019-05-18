#ifndef BCMINEINTERESTITEMWIDGET_H
#define BCMINEINTERESTITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCMineInterestItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMineInterestItemWidget(QWidget *parent = nullptr);
    void initData();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void setHeadImage(const QString& image);
    void setName(const QString& name);

private:
    BCPolymorphicLabel *mHeadImageLabel{};
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicLabel *mEnterLabel{};

    QHBoxLayout *mMainHLayout{};
};

#endif // BCMINEINTERESTITEMWIDGET_H
