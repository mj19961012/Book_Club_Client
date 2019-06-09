#ifndef BCPOSTINGWIDGET_H
#define BCPOSTINGWIDGET_H

#include <QMap>
#include <QWidget>
#include "BCCommonEnumData.h"
#include "BCPolymorphicButton.h"
#include "BCListWidget.h"

class BCPostingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCPostingWidget(QWidget *parent = nullptr);
    void initData();
signals:
    void getPostingList(Page::BCPageEnum);
public slots:
    void receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotSubjectBtnClicked();

private:
    void init();
    void initStyle();
    void initConnect();
    void setButtonText();

private:
    BCPolymorphicButton *mAddPostingsButton{};
    BCListWidget *mPostingListWidget{};
private:
    QMap<int,BCPolymorphicButton*> mSubjectButtonMap{};
};

#endif // BCPOSTINGWIDGET_H
