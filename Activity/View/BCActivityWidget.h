#ifndef BCACTIVITYWIDGET_H
#define BCACTIVITYWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"

class BCActivityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCActivityWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();

private:
    BCPolymorphicButton *mAddActivityButton{};
};

#endif // BCACTIVITYWIDGET_H
