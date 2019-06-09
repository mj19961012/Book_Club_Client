#ifndef BCMESSAGEPOSTINGITEMWIDGET_H
#define BCMESSAGEPOSTINGITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCMessagePostingItemWidget  : public QWidget
{
    Q_OBJECT
public:
    explicit BCMessagePostingItemWidget(QWidget *parent = nullptr);
    void initData(const QString& title,const QString& date,const QString& content,const bool isRead);
    void setIsRead(const bool& isRead);

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

private:
    bool mIsRead{true};
};

#endif // BCMESSAGEPOSTINGITEMWIDGET_H
