#ifndef BCPOSTMASTERWIDGET_H
#define BCPOSTMASTERWIDGET_H

#include <QWidget>
#include "BCCommonEnumData.h"
#include "BCImageView.h"
#include "BCPolymorphicLabel.h"
#include "BCPolymorphicButton.h"

class BCPostMasterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCPostMasterWidget(QWidget *parent = nullptr);
    void initData();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();
    void updateGeometry();
    void setHeadImage(const QString& image);
    void setName(const QString& name);
    void setCity(const QString& city);
    void setSchool(const QString& school);
    void setPostingsNum(const QString& num);
    void setFansNum(const QString& num);
    void setIsFollow(bool isFollow);

private:
    BCPolymorphicButton *mBackButton{};

    BCImageView *mHeadImageView{};
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicLabel *mCityLabel{};
    BCPolymorphicLabel *mSchoolLabel{};
    BCPolymorphicLabel *mPostingsNumLabel{};
    BCPolymorphicLabel *mFansNumLabel{};

    BCPolymorphicButton *mFollowButton{};
    BCPolymorphicButton *mFollowedButton{};
private:
    Page::BCPageEnum mEntrancePageEnum;
};

#endif // BCPOSTMASTERWIDGET_H
