#ifndef BCMAINWINDOW_H
#define BCMAINWINDOW_H

#include <QMainWindow>
#include "BCCommonEnumData.h"

class BCMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static BCMainWindow* getInstance();
private:
    BCMainWindow(QWidget *parent = nullptr);

private:
    void init();

    void addPage();

    void showPage();
private:
    static BCMainWindow* m_BCMainWindow;

    class BCLoginWidget* mLoginWidget{};
};

#endif // BCMAINWINDOW_H
