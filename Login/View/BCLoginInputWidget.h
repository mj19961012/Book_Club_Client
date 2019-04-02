#ifndef BCLOGININPUTWIDGET_H
#define BCLOGININPUTWIDGET_H

#include <QWidget>
#include "BCLoginLineEdit.h"

class BCLoginInputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCLoginInputWidget(QWidget *parent = nullptr);

    void reset();

    BCLoginLineEdit* getUserPhoneLineEdit() const;

    BCLoginLineEdit* getPasswordLineEdit() const;
protected:
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);
signals:
    void sigLoginButtonClicked();
    void sigRegisterButtonClicked();

private:
    void init();

    void initStyle();

    void initConnect();

private:
    class BCLoginLineEdit* mUserPhoneLineEdit{};
    class BCLoginLineEdit* mPasswordLineEdit{};

    class BCPolymorphicButton* mLoginButton{};
    class BCPolymorphicButton* mRegisterButton{};
};

#endif // BCLOGININPUTWIDGET_H
