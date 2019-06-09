#ifndef BCMINEUPDATEINFOWIDGET_H
#define BCMINEUPDATEINFOWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"
#include "BCInformationLineEdit.h"
#include "BCRegisterCityButton.h"
#include "BCImageView.h"

class BCMineUpdateInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMineUpdateInfoWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();

private:
    BCPolymorphicButton* mCloseButton{};

    BCImageView *mImageView{};

    BCInformationLineEdit* mNameLineEdit{};
    BCRegisterCityButton *mCityButton{};
    BCInformationLineEdit* mSchoolLineEdit{};
    BCInformationLineEdit* mPhoneLineEdit{};
    BCInformationLineEdit* mPasswordLineEdit{};

    BCPolymorphicButton* mRegisterButton{};
    QString mImgPath;
};

#endif // BCMINEUPDATEINFOWIDGET_H
