#ifndef BCREGISTERWIDGET_H
#define BCREGISTERWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"
#include "BCRegisterLineEdit.h"
#include "BCRegisterCityButton.h"

class BCRegisterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCRegisterWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);

signals:
    void sigRegisterCloseButtonClicked();

private:
    void init();

    void initStyle();

    void initConnect();

private:
    BCPolymorphicButton* mCloseButton{};

    BCRegisterLineEdit* mNameLineEdit{};
    BCRegisterCityButton *mCityButton{};
    BCRegisterLineEdit* mSchoolLineEdit{};
    BCRegisterLineEdit* mPhoneLineEdit{};
    BCRegisterLineEdit* mPasswordLineEdit{};

    BCPolymorphicButton* mRegisterButton{};
};

#endif // BCREGISTERWIDGET_H
