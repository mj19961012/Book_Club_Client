#ifndef BCREGISTERWIDGET_H
#define BCREGISTERWIDGET_H

#include <QWidget>

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
    class BCPolymorphicButton* mCloseButton{};
};

#endif // BCREGISTERWIDGET_H
