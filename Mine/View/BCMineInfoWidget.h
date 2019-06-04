#ifndef BCMINEINFOWIDGET_H
#define BCMINEINFOWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCImageView.h"
#include "BCPolymorphicLabel.h"
#include "BCPolymorphicButton.h"

class BCMineInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMineInfoWidget(QWidget *parent = nullptr);
    void initData();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotEditButtonClicked();
    void slotLogoutButtonClicked();

private:
    void init();
    void initStyle();
    void initConnect();
    void setHeadImage(const QString& image);
    void setName(const QString& name);
    void setCity(const QString& city);
    void setSchool(const QString& school);
    void setPhone(const QString& phone);
    void setPassword(const QString& password);
    void setFansNum(const QString& num);

private:
    BCImageView *mHeadImageView{};
    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicLabel *mCityLabel{};
    BCPolymorphicLabel *mSchoolLabel{};
    BCPolymorphicLabel *mPhoneLabel{};
    BCPolymorphicLabel *mPasswordLabel{};
    BCPolymorphicLabel *mFansNumLabel{};

    BCPolymorphicButton *mEditInfoButton{};
    BCPolymorphicButton *mLogoutButton{};
};

#endif // BCMINEINFOWIDGET_H
