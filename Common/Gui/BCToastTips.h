#ifndef BCTOASTTIPS_H
#define BCTOASTTIPS_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

class BCToastTips : public QWidget
{
    Q_OBJECT
public:
    static BCToastTips &Instance();

    void setToastTip(QString strMessage, QColor backgroundColor = QColor(0,0,0), double opacity = 0.7, int durationSeconds = 3000);

protected:
    void paintEvent(QPaintEvent *event);

private:
    explicit BCToastTips(QWidget *parent = nullptr);

    void init();

    void initConnect();
private:
    static BCToastTips* sMessageTips;

    class QHBoxLayout *mMainHBoxLayout{};

    class BCPolymorphicLabel *mMessageLabel{};

    class QGraphicsOpacityEffect *mOpacityGraphicsOpacityEffect{};
    class QPropertyAnimation *mOpacityPropertyAnimation{};

    QString mMessageText;

    QColor mBackgroundColor;
    double mOpacity;
};

#endif // BCTOASTTIPS_H
