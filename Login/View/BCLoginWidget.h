#ifndef BCLOGINWIDGET_H
#define BCLOGINWIDGET_H

#include <QWidget>

class BCLoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCLoginWidget(QWidget *parent = nullptr);

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
