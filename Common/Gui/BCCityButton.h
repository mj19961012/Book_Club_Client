﻿#ifndef BCCITYBUTTON_H
#define BCCITYBUTTON_H

#include <QToolButton>

class BCCityButton : public QToolButton
{
    Q_OBJECT
public:
    explicit BCCityButton(QWidget *parent = nullptr);
    void initData(const QString& text);

signals:
    void sigSelectCity();

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

#endif // BCCITYBUTTON_H
