#ifndef BCACTIVITYLISTITEMWIDGET_H
#define BCACTIVITYLISTITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCActivityListItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCActivityListItemWidget(QWidget *parent = nullptr);
    void initData(const QString& name,const QString& content,const QString& date,const QString& num);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void init();
    void initStyle();
    void createTipWidget();
    void setName(const QString& name);
    void setContent(const QString& content);
    void setDate(const QString& date);
    void setWatchNum(const QString& num);

private:
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicLabel *mContentLabel{};
    QWidget *mTipWidget{};

    BCPolymorphicLabel *mDateLabel{};
    BCPolymorphicLabel *mWatchNumLabel{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mTipHLayout{};
};

#endif // BCACTIVITYLISTITEMWIDGET_H
