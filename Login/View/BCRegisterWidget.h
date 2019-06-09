#ifndef BCREGISTERWIDGET_H
#define BCREGISTERWIDGET_H

#include <QWidget>
#include "BCPolymorphicButton.h"
#include "BCInformationLineEdit.h"
#include "BCCityButton.h"
#include "BCImageView.h"
#include "BCCommonEnumData.h"

class BCRegisterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCRegisterWidget(QWidget *parent = nullptr);
public slots:
    void receiveOperationResult(bool isSuccess,Page::BCPageEnum pageEnum);
    void onRegisterButtonClicked();
protected:
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);

signals:
    void sigRegisterCloseButtonClicked();
    void doRegiestSignal(Page::BCPageEnum pageNum);
private:
    void init();
    void initStyle();
    void initConnect();

private:
    BCPolymorphicButton* mCloseButton{};

    BCImageView *mImageView{};

    BCInformationLineEdit* mNameLineEdit{};
    BCCityButton *mCityButton{};
    BCInformationLineEdit* mSchoolLineEdit{};
    BCInformationLineEdit* mPhoneLineEdit{};
    BCInformationLineEdit* mPasswordLineEdit{};

    BCPolymorphicButton* mRegisterButton{};
    QString mImgPath;
};

#endif // BCREGISTERWIDGET_H
