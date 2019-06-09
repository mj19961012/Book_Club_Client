#ifndef BCMINEFOLLOWEDPOSTINGMASTERWIDGET_H
#define BCMINEFOLLOWEDPOSTINGMASTERWIDGET_H

#include <QWidget>
#include "BCImageView.h"
#include "BCPolymorphicLabel.h"
#include "BCPolymorphicButton.h"
#include "BCListWidget.h"

class BCMineFollowedPostingMasterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMineFollowedPostingMasterWidget(QWidget *parent = nullptr);
    void initData();

signals:
    void sigMineFollowedPostingMasterBack();

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
    void setFansNum(const QString& num);

private:
    BCPolymorphicButton *mBackButton{};

    BCImageView *mHeadImageView{};
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicButton *mChatButton{};

    BCPolymorphicLabel *mCityLabel{};
    BCPolymorphicLabel *mSchoolLabel{};
    BCPolymorphicLabel *mFansNumLabel{};

    BCListWidget *mPostingsListWidget{};
    BCListWidget *mActivityListWidget{};
};

#endif // BCMINEFOLLOWEDPOSTINGMASTERWIDGET_H
