#ifndef BCMINEACTIVITYITEMWIDGET_H
#define BCMINEACTIVITYITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCMineActivityItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMineActivityItemWidget(QWidget *parent = nullptr);
    void initData(const QString& title,const QString& content,const QString& date);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void createTitleWidget();
    void initStyle();
    void setTitle(const QString& title);
    void setDate(const QString& date);
    void setContent(const QString& content);

private:
    QWidget *mTitleWidget{};
    BCPolymorphicLabel *mContentLabel{};

    BCPolymorphicLabel *mTitleLabel{};
    BCPolymorphicLabel *mDateLabel{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mTitleHLayout{};
};

#endif // BCMINEACTIVITYITEMWIDGET_H
