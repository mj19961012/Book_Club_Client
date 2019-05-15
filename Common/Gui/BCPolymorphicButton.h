#ifndef BCPOLYMORPHICBUTTON_H
#define BCPOLYMORPHICBUTTON_H

#include <QToolButton>

class BCPolymorphicButton : public QToolButton
{
    Q_OBJECT
public:
    explicit BCPolymorphicButton(QWidget *parent = nullptr);

    /// \brief 通过qrc路径、文件路径进行设置多状态图片 normal hover pressed enabled
    void setImageStyle(const QString &normalPath = "",const QString &hoverPath = "",const QString &pressedPath = "",const QString &enabledPath = "");

    /// \brief 通过QColor进行设置多状态背景色和圆角、边框 normal hover pressed enabled,需要背景文字同步传参才可以生效
    void setColorStyle(const QString &normalColor,
                       const QString &hoverColor,
                       const QString &pressedColor,
                       const QString &enabledColor,
                       const QString &fontColor,
                       const int& borderWidth,
                       const QString& borderColor,
                       const int& borderRadius);

    /// \brief 通过QColor进行设置多状态背景色和圆角、边框 normal hover pressed enabled,需要背景文字同步传参才可以生效
    void setColorStyle(const QString &normalColor,
                       const QString &hoverColor,
                       const QString &pressedColor,
                       const QString &enabledColor,
                       const QString &fontColor,
                       const int& borderWidth,
                       const QString& borderColor,
                       const QStringList& borderRadius);

    /// \brief 通过QColor进行设置多状态背景色和圆角、边框 normal hover pressed enabled,需要背景文字同步传参才可以生效
    void setColorStyle(const QString &normalColor,
                       const QString &hoverColor,
                       const QString &pressedColor,
                       const QString &enabledColor,
                       const QString &fontColor,
                       const QStringList& borderWidth,
                       const QStringList& borderColor,
                       const int& borderRadius);

    /// \brief 通过QColor进行设置多状态背景色和圆角、边框 normal hover pressed enabled,需要背景文字同步传参才可以生效
    void setColorStyle(const QString &normalColor,
                       const QString &hoverColor,
                       const QString &pressedColor,
                       const QString &enabledColor,
                       const QString &fontColor,
                       const QStringList& borderWidth,
                       const QStringList& borderColor,
                       const QStringList& borderRadius);

    void setButtonText(const QString& text);

    /// \brief 设置字体
    void setFontStyle(const int &fontPixelSize,const int &fontWeight = 50,const QString &fontFamily = "Microsoft YaHei");

private:
    void init();
};

#endif // BCPOLYMORPHICBUTTON_H
