#ifndef BCACTIVITYDETAILWIDGET_H
#define BCACTIVITYDETAILWIDGET_H

#include <QWidget>
#include <QTextBrowser>
#include "BCImageView.h"
#include "BCPolymorphicLabel.h"
#include "BCPolymorphicButton.h"

class BCActivityDetailWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCActivityDetailWidget(QWidget *parent = nullptr);
    void initData(const QString& id);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void init();
    void initStyle();
    void initGeometry();
    void initConnect();
    void setImage(const QString& image);
    void setName(const QString& name);
    void setActivityName(const QString& name);
    void setCity(const QString& city);
    void setDate(const QString& date);
    void setContent(const QString& content);

private:
    BCPolymorphicButton *mBackButton{};
    BCImageView *mImageView{};
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicButton *mAttentionButton{};

    BCPolymorphicLabel *mActivityNameLabel{};
    BCPolymorphicLabel *mCityLabel{};
    BCPolymorphicLabel *mDateTimeLabel{};

    QTextBrowser *mContentTextBrowser{};
};

#endif // BCACTIVITYDETAILWIDGET_H
