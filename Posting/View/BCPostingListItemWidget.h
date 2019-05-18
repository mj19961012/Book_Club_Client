#ifndef BCPOSTINGLISTITEMWIDGET_H
#define BCPOSTINGLISTITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCPostingListItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCPostingListItemWidget(QWidget *parent = nullptr);
    void initData(const QString& name, const QString& content);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void init();
    void initStyle();
    void setName(const QString& name);
    void setContent(const QString& content);

private:
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicLabel *mContentLabel{};

    QVBoxLayout *mMainVLayout{};
};

#endif // BCPOSTINGLISTITEMWIDGET_H
