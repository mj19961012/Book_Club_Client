#include "BCPolymorphicButton.h"

BCPolymorphicButton::BCPolymorphicButton(QWidget *parent)
    :QToolButton(parent)
{
    init();
}

void BCPolymorphicButton::setImageStyle(const QString &normalPath, const QString &hoverPath, const QString &pressedPath, const QString &enabledPath)
{
    QString styleSheetStr = "";
    styleSheetStr.append(QString("QToolButton#BCPolymorphicButton{"
                                 "border-image: url(%1);"
                                 "}")
                         .arg(normalPath));

    // Hover
    if(!hoverPath.isEmpty())
    {
        styleSheetStr.append(QString("QToolButton#BCPolymorphicButton:hover{"
                                     "border-image: url(%1);"
                                     "}")
                             .arg(hoverPath));
    }

    //Pressed
    if(!pressedPath.isEmpty())
    {
        styleSheetStr.append(QString("QToolButton#BCPolymorphicButton:Pressed{"
                                     "border-image: url(%1);"
                                     "}")
                             .arg(pressedPath));
    }

    //Enabled
    if(!enabledPath.isEmpty())
    {
        styleSheetStr.append(QString("QToolButton#BCPolymorphicButton:!enabled{"
                                     "border-image: url(%1);"
                                     "}")
                             .arg(enabledPath));
    }

    setStyleSheet(styleSheetStr);
}

void BCPolymorphicButton::setColorStyle(const QString &normalColor, const QString &hoverColor, const QString &pressedColor, const QString &enabledColor, const QString &fontColor, const int &borderWidth, const QString &borderColor, const int &borderRadius)
{
    setStyleSheet(QString("QToolButton#BCPolymorphicButton{"
                          "background-color: %1;"
                          "color:%5;"
                          "border:%6px solid %7;"
                          "border-radius:%8;"
                          "}"
                          "QToolButton#BCPolymorphicButton:hover{"
                          "background-color: %2;"
                          "}"
                          "QToolButton#BCPolymorphicButton:pressed{"
                          "background-color: %3;"
                          "}"
                          "QToolButton#BCPolymorphicButton:!enabled{"
                          "background-color: %4;"
                          "}")
                  .arg(normalColor)
                  .arg(hoverColor)
                  .arg(pressedColor)
                  .arg(enabledColor)
                  .arg(fontColor)
                  .arg(borderWidth)
                  .arg(borderColor)
                  .arg(borderRadius));
}

void BCPolymorphicButton::setColorStyle(const QString &normalColor, const QString &hoverColor, const QString &pressedColor, const QString &enabledColor, const QString &fontColor, const int &borderWidth, const QString &borderColor, const QStringList &borderRadius)
{
    setStyleSheet(QString("QToolButton#BCPolymorphicButton{"
                          "background-color: %1;"
                          "color:%5;"
                          "border:%6px solid %7;"
                          "border-top-left-radius:%8;"
                          "border-top-right-radius:%9;"
                          "border-bottom-left-radius:%10;"
                          "border-bottom-right-radius:%11;"
                          "}"
                          "QToolButton#BCPolymorphicButton:hover{"
                          "background-color: %2;"
                          "}"
                          "QToolButton#BCPolymorphicButton:pressed{"
                          "background-color: %3;"
                          "}"
                          "QToolButton#BCPolymorphicButton:!enabled{"
                          "background-color: %4;"
                          "}")
                  .arg(normalColor)
                  .arg(hoverColor)
                  .arg(pressedColor)
                  .arg(enabledColor)
                  .arg(fontColor)
                  .arg(borderWidth)
                  .arg(borderColor)
                  .arg(borderRadius.at(0))
                  .arg(borderRadius.at(1))
                  .arg(borderRadius.at(2))
                  .arg(borderRadius.at(3)));
}

void BCPolymorphicButton::setColorStyle(const QString &normalColor, const QString &hoverColor, const QString &pressedColor, const QString &enabledColor, const QString &fontColor, const QStringList &borderWidth, const QStringList &borderColor, const int &borderRadius)
{
    setStyleSheet(QString("QToolButton#BCPolymorphicButton{"
                          "background-color: %1;"
                          "color:%5;"
                          "border-left:%6px solid %7;"
                          "border-top:%8px solid %9;"
                          "border-right:%10px solid %11;"
                          "border-bottom:%12px solid %13;"
                          "border-radius:%14;"
                          "}"
                          "QToolButton#BCPolymorphicButton:hover{"
                          "background-color: %2;"
                          "}"
                          "QToolButton#BCPolymorphicButton:pressed{"
                          "background-color: %3;"
                          "}"
                          "QToolButton#BCPolymorphicButton:!enabled{"
                          "background-color: %4;"
                          "}")
                  .arg(normalColor)
                  .arg(hoverColor)
                  .arg(pressedColor)
                  .arg(enabledColor)
                  .arg(fontColor)
                  .arg(borderWidth.at(0))
                  .arg(borderColor.at(0))
                  .arg(borderWidth.at(1))
                  .arg(borderColor.at(1))
                  .arg(borderWidth.at(2))
                  .arg(borderColor.at(2))
                  .arg(borderWidth.at(3))
                  .arg(borderColor.at(3))
                  .arg(borderRadius));
}

void BCPolymorphicButton::setColorStyle(const QString &normalColor, const QString &hoverColor, const QString &pressedColor, const QString &enabledColor, const QString &fontColor, const QStringList &borderWidth, const QStringList &borderColor, const QStringList &borderRadius)
{
    setStyleSheet(QString("QToolButton#BCPolymorphicButton{"
                          "background-color: %1;"
                          "color:%5;"
                          "border-top-left-radius:%6;"
                          "border-top-right-radius:%7;"
                          "border-bottom-left-radius:%8;"
                          "border-bottom-right-radius:%9;"
                          "border-left:%10px solid %11;"
                          "border-top:%12px solid %13;"
                          "border-right:%14px solid %15;"
                          "border-bottom:%16px solid %17;"
                          "}"
                          "QToolButton#BCPolymorphicButton:hover{"
                          "background-color: %2;"
                          "}"
                          "QToolButton#BCPolymorphicButton:pressed{"
                          "background-color: %3;"
                          "}"
                          "QToolButton#BCPolymorphicButton:!enabled{"
                          "background-color: %4;"
                          "}")
                  .arg(normalColor)
                  .arg(hoverColor)
                  .arg(pressedColor)
                  .arg(enabledColor)
                  .arg(fontColor)
                  .arg(borderWidth.at(0))
                  .arg(borderColor.at(0))
                  .arg(borderWidth.at(1))
                  .arg(borderColor.at(1))
                  .arg(borderWidth.at(2))
                  .arg(borderColor.at(2))
                  .arg(borderWidth.at(3))
                  .arg(borderColor.at(3))
                  .arg(borderRadius.at(0))
                  .arg(borderRadius.at(1))
                  .arg(borderRadius.at(2))
                  .arg(borderRadius.at(3)));
}

void BCPolymorphicButton::setButtonText(const QString &text)
{
    setText(text);
    setToolTip(text);
}

void BCPolymorphicButton::setFontStyle(const int &fontPixelSize, const int &fontWeight, const QString &fontFamily)
{
    QFont font;
    font.setFamily(fontFamily);
    font.setWeight(fontWeight);
    font.setPixelSize(fontPixelSize);

    setFont(font);
}

void BCPolymorphicButton::init()
{
    setObjectName("BCPolymorphicButton");
    setCursor(Qt::PointingHandCursor);
    setFocusPolicy(Qt::NoFocus);
}
