#ifndef BCPOSTINGDETAILITEMWIDGET_H
#define BCPOSTINGDETAILITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QTextBrowser>
#include <QListWidgetItem>
#include "BCPolymorphicLabel.h"
#include "BCInputWidget.h"
#include "BCCommonEnumData.h"

class BCPostingDetailItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCPostingDetailItemWidget(QWidget *parent = nullptr);
    void initData(const QString& id);
    void setListWidgetItem(QListWidgetItem* item);
    QListWidgetItem* getListWidgetItem() const;

signals:
    void sigResizeItem(int height);
    void doReleaseComment(Page::BCPageEnum);
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void init();
    void initStyle();
    void initConnect();
    void initGeometry();
    void createPropertyWidget();
    void setName(const QString& name);
    void setAuthorHeadImage(const QString& image);
    void setAuthorName(const QString& name);
    void setReadCount(const QString& count);
    void setDateTime(const QString& dateTime);
    void setContent(const QString& content);
    void setComment(const QString& comment);

private:
    BCPolymorphicLabel *mNameLabel{};
    QWidget *mPropertyWidget{};
    QTextBrowser *mContentTextBrowser{};
    BCPolymorphicLabel *mPublishCommentLabel{};
    BCInputWidget *mPublishCommentWidget{};
    BCPolymorphicLabel *mCommentLabel{};

    BCPolymorphicLabel *mAuthorHeadImageLabel{};
    BCPolymorphicLabel *mAuthorNameLabel{};
    BCPolymorphicLabel *mReadCountLabel{};
    BCPolymorphicLabel *mDateTimeLabel{};

    QVBoxLayout *mMainVLayout{};
    QHBoxLayout *mPropertyHLayout{};

private:
    QListWidgetItem *mCurrentItem{};
    QString mPostId{};
};

#endif // BCPOSTINGDETAILITEMWIDGET_H
