#ifndef BCPOSTINGCOMMENTITEMWIDGET_H
#define BCPOSTINGCOMMENTITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCPostingCommentItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCPostingCommentItemWidget(QWidget *parent = nullptr);
    void initData();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void init();
    void initGeometry();
    void createPropertyWidget();
    void setHeadImage(const QString& image);
    void setName(const QString& name);
    void setDateTime(const QString& dateTime);
    void setContent(const QString& content);

private:
    QWidget *mPropertyWidget{};
    BCPolymorphicLabel *mContentLabel{};

    BCPolymorphicLabel *mHeadImageLabel{};
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicLabel *mDateTimeLabel{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mPropertyHLayout{};
};

#endif // BCPOSTINGCOMMENTITEMWIDGET_H
