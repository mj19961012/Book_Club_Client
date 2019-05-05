#ifndef BCREGISTERCITYBUTTON_H
#define BCREGISTERCITYBUTTON_H

#include <QPushButton>

class BCRegisterCityButton : public QPushButton
{
    Q_OBJECT
public:
    explicit BCRegisterCityButton(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BCREGISTERCITYBUTTON_H
