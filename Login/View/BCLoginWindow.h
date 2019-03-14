#ifndef BCLOGINWINDOW_H
#define BCLOGINWINDOW_H

#include <QMainWindow>

class BCLoginWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BCLoginWindow(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initConnect();

private:
    class QPushButton* mCloseButton{};

    class BCLoginLineEdit* mUserPhoneLineEdit{};
    class BCLoginLineEdit* mPasswordLineEdit{};

    class QPushButton* mLoginButton{};
};

#endif // BCLOGINWINDOW_H
