#ifndef BCPUBLISHACTIVITYWIDGET_H
#define BCPUBLISHACTIVITYWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QList>
#include "BCPolymorphicButton.h"
#include "BCInputContentAndFileWidget.h"
#include "BCCommonEnumData.h"

class BCPublishActivityWidget :public QWidget
{
    Q_OBJECT
public:
    explicit BCPublishActivityWidget(QWidget *parent = nullptr);
signals:
    void doPublishActivity(Page::BCPageEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

public slots:
    void slotPublishActivityBtnClicked();
    void receiveOperationResult(bool isSuccess,Page::BCPageEnum pageEnum);
private:
    void init();
    void initStyle();
    void initConnect();

private:
    BCPolymorphicButton *mBackButton{};
    QLineEdit *mTitleLineEdit{};
    BCPolymorphicButton *mCityButton{};
    BCPolymorphicButton *mCityArrowButton{};
    BCPolymorphicButton *mDateTimeButton{};
    BCPolymorphicButton *mDateTimeArrowButton{};
    BCInputContentAndFileWidget *mInputContentWidget{};
    BCPolymorphicButton *mPublishButton{};

    QList<QString> mBCUploadFilesList;
};

#endif // BCPUBLISHACTIVITYWIDGET_H
