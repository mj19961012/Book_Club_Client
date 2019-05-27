#ifndef BCLOGINWIDGET_H
#define BCLOGINWIDGET_H

#include <QWidget>
#include "BCCommonEnumData.h"

class BCLoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCLoginWidget(QWidget *parent = nullptr);
signals:
    void doLoginSignal(Page::BCPageEnum pageNum);
public slots:
   void receiveOperationResult(bool isSuccess,Page::BCPageEnum pageEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initConnect();

private:
    class QPushButton* mCloseButton{};

    class BCLoginInputWidget* mLoginInputWidget{};
    class BCRegisterWidget* mRegisterWidget{};
};

#endif // BCLOGINWIDGET_H
