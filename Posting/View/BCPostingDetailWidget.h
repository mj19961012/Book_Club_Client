#ifndef BCPOSTINGDETAILWIDGET_H
#define BCPOSTINGDETAILWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"
#include "BCListWidget.h"
#include "BCPostingDetailItemWidget.h"

class BCPostingDetailWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCPostingDetailWidget(QWidget *parent = nullptr);
    void initData();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void init();
    void initStyle();
    void initConnect();

private:
    BCPolymorphicButton *mBackButton{};
    BCListWidget *mDetailWidget{};
};

#endif // BCPOSTINGDETAILWIDGET_H
