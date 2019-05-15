#ifndef BCREGISTERWIDGET_H
#define BCREGISTERWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"
#include "BCInformationLineEdit.h"
#include "BCRegisterCityButton.h"
#include "BCImageView.h"

class BCRegisterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCRegisterWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);

signals:
    void sigRegisterCloseButtonClicked();

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
};

#endif // BCREGISTERWIDGET_H
