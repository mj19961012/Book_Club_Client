#ifndef BCMINEUPDATEINFOWIDGET_H
#define BCMINEUPDATEINFOWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"
#include "BCInformationLineEdit.h"
#include "BCCityButton.h"
#include "BCImageView.h"

class BCMineUpdateInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMineUpdateInfoWidget(QWidget *parent = nullptr);
    void initData();

signals:
    void sigEditInfoBack();
    void sigUpdateInfo();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();
    void updateGeometry();
    void setImageView(const QString& image);
    void setName(const QString& name);
    void setCity(const QString& city);
    void setSchool(const QString& school);
    void setPhone(const QString& phone);
    void setPassword(const QString& password);

private:
    BCPolymorphicButton* mCloseButton{};

    BCImageView *mImageView{};

    BCInformationLineEdit* mNameLineEdit{};
    BCCityButton *mCityButton{};
    BCInformationLineEdit* mSchoolLineEdit{};
    BCInformationLineEdit* mPhoneLineEdit{};
    BCInformationLineEdit* mPasswordLineEdit{};

    BCPolymorphicButton* mUpdateButton{};
    QString mImgPath;
};

#endif // BCMINEUPDATEINFOWIDGET_H
