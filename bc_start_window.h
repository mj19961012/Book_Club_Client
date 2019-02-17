#ifndef BC_START_WINDOW_H
#define BC_START_WINDOW_H

#include <QMainWindow>

namespace Ui {
class BC_Start_Window;
}

class BC_Start_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit BC_Start_Window(QWidget *parent = nullptr);
    ~BC_Start_Window();

private:
    Ui::BC_Start_Window *ui;
};

#endif // BC_START_WINDOW_H
