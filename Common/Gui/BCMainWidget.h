#ifndef BCMAINWIDGET_H
#define BCMAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "BCCommonEnumData.h"
#include "BCPostingWidget.h"
#include "BCPublishPostWidget.h"

class BCMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMainWidget(QWidget *parent = nullptr);

    void showPage(Page::BCPageEnum pageEnum);
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
    class BCNavigationBar *mNavigationBar{};
    /// \brief 堆叠窗口
    class QStackedWidget *mStackWidget{};

    BCPostingWidget *mPostingWidget{};
    BCPublishPostWidget *mPublishPostWidget{};
};

#endif // BCMAINWIDGET_H
