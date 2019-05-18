#ifndef BCMESSAGEWIDGET_H
#define BCMESSAGEWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "BCListWidget.h"
#include "BCMessageEnumData.h"
#include "BCPolymorphicButton.h"

class BCMessageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMessageWidget(QWidget * parent = nullptr);
    void showPage(MessagePage::BCMessagePageEnum page);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void slotMessageButtonClicked();
    void slotHasBeenReadButtonClicked();

private:
    void init();
    void initStyle();
    void initConnect();
    void addPage(MessagePage::BCMessagePageEnum page);

private:
    BCPolymorphicButton *mChatListButton{};
    BCPolymorphicButton *mPostingListButton{};

    BCPolymorphicButton *mHasBeenReadButton{};

    QStackedWidget *mStackedWidget{};
    BCListWidget *mChatListWidget;
    BCListWidget *mPostingListWidget;
};

#endif // BCMESSAGEWIDGET_H
