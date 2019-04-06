#ifndef BCNAVIGATIONBAR_H
#define BCNAVIGATIONBAR_H

#include <QWidget>
#include "BCCommonEnumData.h"

class BCNavigationBar : public QWidget
{
    Q_OBJECT
public:
    explicit BCNavigationBar(QWidget *parent = nullptr);

    void setSelectItem(NavigationBar::BCNavigationBarEnum barEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
    void init();

    void initStyle();

    void initConnect();
private:
    class BCPolymorphicLabel* mBookClubLabel{};

    class BCNavigationBarItem* mPostingsItem{};
    class BCNavigationBarItem* mActivityItem{};
    class BCNavigationBarItem* mMessageItem{};
    class BCNavigationBarItem* mSearchItem{};
    class BCNavigationBarItem* mMineInfoItem{};
};

#endif // BCNAVIGATIONBAR_H
