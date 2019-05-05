#ifndef BCREGISTERLINEEDIT_H
#define BCREGISTERLINEEDIT_H

#include <QLineEdit>

class BCRegisterLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit BCRegisterLineEdit(QWidget* parent = nullptr);

private:
    void init();
};

#endif // BCREGISTERLINEEDIT_H
