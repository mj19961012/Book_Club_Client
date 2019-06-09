#ifndef BCDATEBUTTON_H
#define BCDATEBUTTON_H

#include <QToolButton>

class BCDateButton : public QToolButton
{
    Q_OBJECT
public:
    explicit BCDateButton(QWidget *parent = nullptr);

    void initData(const QString& text);

signals:
    void sigSelectDate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();
    void setButtonText(const QString& text);

private:
    QString mButtonText{};
};

#endif // BCDATEBUTTON_H
