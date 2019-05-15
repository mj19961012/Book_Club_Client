#ifndef BCPUBLISHACTIVITYWIDGET_H
#define BCPUBLISHACTIVITYWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "BCPolymorphicButton.h"
#include "BCInputContentAndFileWidget.h"

class BCPublishActivityWidget :public QWidget
{
    Q_OBJECT
public:
    explicit BCPublishActivityWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotPublishActivityBtnClicked();

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
};

#endif // BCPUBLISHACTIVITYWIDGET_H
