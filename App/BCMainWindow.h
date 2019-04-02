#ifndef BCMAINWINDOW_H
#define BCMAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QStackedWidget>
#include "BCCommonEnumData.h"

class BCMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static BCMainWindow* instance();

    void showBasePage(BasePage::BCBasePageEnum pageEnum);

    void showPage(Page::BCPageEnum pageEnum);
protected:
    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);
private:
    BCMainWindow(QWidget *parent = nullptr);

private:
    void init();

    void initToolButton();

    void initStyle();

    void initConnect();

    void addBasePage(BasePage::BCBasePageEnum pageEnum);
private:
    int mHFactor;
    int mWFactor;
    /// \brief 最小放缩比
    int mMinFactor;

    static BCMainWindow* m_BCMainWindow;

    /// \brief 主窗体堆叠窗口
    class QStackedWidget* mStackedWidget{};
    /// \brief 登录
    class BCLoginWidget* mLoginWidget{};
    /// \brief 主widget
    class BCMainWidget* mMainWidget{};

    class BCPolymorphicButton* mMiniSizeButton{};
    class BCPolymorphicButton* mExitButton{};
};

#endif // BCMAINWINDOW_H
