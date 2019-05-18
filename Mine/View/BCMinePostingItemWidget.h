#ifndef BCMINEPOSTINGITEMWIDGET_H
#define BCMINEPOSTINGITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCMinePostingItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMinePostingItemWidget(QWidget *parent = nullptr);
    void initData();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void createTitleWidget();
    void initStyle();
    void setTitle(const QString& title);
    void setDate(const QString& date);
    void setContent(const QString& content);

private:
    QWidget *mTitleWidget{};
    BCPolymorphicLabel *mContentLabel{};

    BCPolymorphicLabel *mTitleLabel{};
    BCPolymorphicLabel *mDateLabel{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mTitleHLayout{};
};

#endif // BCMINEPOSTINGITEMWIDGET_H
