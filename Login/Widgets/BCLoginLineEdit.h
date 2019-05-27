#ifndef BCLOGINLINEEDIT_H
#define BCLOGINLINEEDIT_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include "BCLoginEnumData.h"

class BCLoginLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit BCLoginLineEdit(QWidget *parent = nullptr);

    void clear();

    bool isEmpty() const;

    bool isMaxInputLength() const;

    void setImage(QString imgPath);

    void setType(BCLoginLineEditEnum type);

    void setMaxInputLength(int length);

    void setTips(QString tips);

    QString getInputText();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void init();

    void addIconLabel();

    void addLineEdit();

private:
    class QHBoxLayout* mMainHLayout{};

    class QLabel* mLabel{};
    class QLineEdit* mLineEdit{};

    int mMaxLength;
};

#endif // BCLOGINLINEEDIT_H
