#ifndef BCCITYBUTTON_H
#define BCCITYBUTTON_H

#include <QPushButton>

class BCCityButton : public QPushButton
{
    Q_OBJECT
public:
    explicit BCCityButton(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BCCITYBUTTON_H
