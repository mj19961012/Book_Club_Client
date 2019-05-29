#ifndef BCINPUTWIDGET_H
#define BCINPUTWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextEdit>
#include "BCPolymorphicButton.h"

class BCInputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCInputWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();
    void createButtonWidget();

private:
    QTextEdit *mContentTextEdit{};
    QWidget *mButtonWidget{};

    BCPolymorphicButton *mSubmitButton{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mButtonHLayout{};
};

#endif // BCINPUTWIDGET_H
