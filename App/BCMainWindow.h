#ifndef BCMAINWINDOW_H
#define BCMAINWINDOW_H

#include <QMainWindow>

class BCMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static BCMainWindow* getInstance();
private:
    BCMainWindow(QWidget *parent = nullptr);

private:
    void init();
    void initData();

private:
    static BCMainWindow* m_BCMainWindow;
};

#endif // BCMAINWINDOW_H
