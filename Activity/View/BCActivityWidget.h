#ifndef BCACTIVITYWIDGET_H
#define BCACTIVITYWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"
#include "BCListWidget.h"
#include "BCCommonEnumData.h"

class BCActivityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCActivityWidget(QWidget *parent = nullptr);
    void initData();
signals:
    void getActivitiesList(Page::BCPageEnum);
public slots:
    void receiveOperationResult(bool isSuccess,Page::BCPageEnum pageEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();

private:
    BCPolymorphicButton *mAddActivityButton{};
    BCListWidget *mActivityListWidget{};

    int mPageSize;
    int mPageNum;
};

#endif // BCACTIVITYWIDGET_H
