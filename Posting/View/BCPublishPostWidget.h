#ifndef BCPUBLISHPOSTWIDGET_H
#define BCPUBLISHPOSTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "BCCommonEnumData.h"
#include "BCPolymorphicButton.h"
#include "BCInputContentAndFileWidget.h"

class BCPublishPostWidget :public QWidget
{
    Q_OBJECT
public:
    explicit BCPublishPostWidget(QWidget *parent = nullptr);
signals:
    void doPublishPosting(Page::BCPageEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotSubjectBtnClicked();
    void receiveOperationResult(bool isSuccess,Page::BCPageEnum pageEnum);
private:
    void init();
    void initStyle();
    void initConnect();
    void setButtonText();

private:
    BCPolymorphicButton *mBackButton{};
    QLineEdit *mTitleLineEdit{};
    BCInputContentAndFileWidget *mInputContentWidget{};
    BCPolymorphicButton *mPublishButton{};

    int mBCPostingType{};
private:
    QMap<int,BCPolymorphicButton*> mSubjectButtonMap{};
};

#endif // BCPUBLISHPOSTWIDGET_H
