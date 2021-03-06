﻿#ifndef BCMINEWIDGET_H
#define BCMINEWIDGET_H

#include <QMap>
#include <QWidget>
#include <QStackedWidget>
#include "BCPolymorphicButton.h"
#include "BCMineEnumData.h"
#include "BCListWidget.h"
#include "BCMineInfoWidget.h"
#include "BCMineUpdateInfoWidget.h"
#include "BCMineFollowedPostingMasterWidget.h"

class BCMineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMineWidget(QWidget *parent = nullptr);
    void showPage(MinePage::BCMinePageEnum page);
signals:
    void getPageValues(Page::BCPageEnum);
public slots:
    void receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotMineButtonClicked();

private:
    void init();
    void initStyle();
    void initConnect();
    void addPage(MinePage::BCMinePageEnum page);
    void switchPageButtonStyle(MinePage::BCMinePageEnum page);

private:
    BCPolymorphicButton *mMineInfoButton{};
    BCPolymorphicButton *mMinePostingButton{};
    BCPolymorphicButton *mMineActivityButton{};
    BCPolymorphicButton *mInterestListButton{};
    QStackedWidget *mStackedWidget{};

    BCMineInfoWidget *mMineInfoWidget{};
    BCMineUpdateInfoWidget *mMineUpdateInfoWidget{};
    BCListWidget *mMinePostingListWidget;
    BCListWidget *mMineActivityListWidget;
    BCListWidget *mMineFollowedListWidget;
    BCMineFollowedPostingMasterWidget *mMineFollowedPostingMasterWidget{};

private:
    QMap<MinePage::BCMinePageEnum,BCPolymorphicButton*> mButtonMap{};
};

#endif // BCMINEWIDGET_H
