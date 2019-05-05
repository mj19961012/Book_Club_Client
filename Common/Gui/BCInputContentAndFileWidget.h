#ifndef BCINPUTCONTENTANDFILEWIDGET_H
#define BCINPUTCONTENTANDFILEWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextEdit>
#include "BCFileWidget.h"
#include "BCPolymorphicButton.h"

class BCInputContentAndFileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCInputContentAndFileWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();
    void createFileWidget();

private:
    QTextEdit *mContentTextEdit{};
    QWidget *mFileWidget{};

    BCFileWidget *mFirstFileWidget{};
    BCFileWidget *mSecondFileWidget{};
    BCFileWidget *mThirdFileWidget{};
    BCPolymorphicButton *mAddFileButton{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mFileHLayout{};
};

#endif // BCINPUTCONTENTANDFILEWIDGET_H
