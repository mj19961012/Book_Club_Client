#ifndef BCINFORMATIONLINEEDIT_H
#define BCINFORMATIONLINEEDIT_H

#include <QLineEdit>

class BCInformationLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit BCInformationLineEdit(QWidget* parent = nullptr);

private:
    void init();
};

#endif // BCINFORMATIONLINEEDIT_H
