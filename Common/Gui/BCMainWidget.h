#ifndef BCMAINWIDGET_H
#define BCMAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "BCCommonEnumData.h"
#include "BCNavigationBar.h"
#include "BCPostingWidget.h"
#include "BCPostingDetailWidget.h"
#include "BCPublishPostWidget.h"
#include "BCActivityWidget.h"
#include "BCPublishActivityWidget.h"
#include "BCMineWidget.h"
#include "BCMessageWidget.h"
#include "BCActivityDetailWidget.h"

class BCMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMainWidget(QWidget *parent = nullptr);

    void showPage(Page::BCPageEnum pageEnum);
signals:
    void getPageValuesSignal(Page::BCPageEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private slots:
    void slotNavigationBarSelected(NavigationBar::BCNavigationBarEnum enumData);
private:
    void init();

    void initStyle();

    void initConnect();

    void addPage(Page::BCPageEnum pageEnum);
private:
    BCNavigationBar *mNavigationBar{};
    /// \brief 堆叠窗口
    QStackedWidget *mStackWidget{};

    BCPostingWidget *mPostingWidget{};
    BCPostingDetailWidget *mPostingDetailWidget{};
    BCPublishPostWidget *mPublishPostWidget{};
    BCActivityWidget *mActivityWidget{};
    BCPublishActivityWidget *mPublishActivityWidget{};
    BCActivityDetailWidget *mActivityDetailWidget{};
    BCMineWidget *mMineWidget{};
    BCMessageWidget *mMessageWidget{};
};

#endif // BCMAINWIDGET_H
