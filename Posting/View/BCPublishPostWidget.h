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

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotSubjectBtnClicked();

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
private:
    QMap<int,BCPolymorphicButton*> mSubjectButtonMap{};
};

#endif // BCPUBLISHPOSTWIDGET_H
