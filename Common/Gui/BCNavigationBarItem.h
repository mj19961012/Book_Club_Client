#ifndef BCNAVIGATIONBARITEM_H
#define BCNAVIGATIONBARITEM_H

#include <QToolButton>
#include <QLayout>
#include "BCCommonEnumData.h"

class BCNavigationBarItem : public QToolButton
{
    Q_OBJECT
public:
    explicit BCNavigationBarItem(QWidget *parent = nullptr);

    void setType(NavigationBar::BCNavigationBarEnum itemEnum);

    void setIsSelected(bool isSelected);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void init();

    void initStyle();
private:
    bool mIsSelected{false};
};

#endif // BCNAVIGATIONBARITEM_H
