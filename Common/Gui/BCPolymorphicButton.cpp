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

void BCPolymorphicButton::setColorStyle(const QString &normalColor, const QString &hoverColor, const QString &pressedColor, const QString &enabledColor, const QString &fontColor, const int &borderRadius, const int &borderWidth, const QString &borderColor)
{
    setStyleSheet(QString("QToolButton#BCPolymorphicButton{"
                          "background-color: %1;"
                          "color:%5;"
                          "border-radius:%6;"
                          "border:%7px solid %8;"
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
                  .arg(borderRadius)
                  .arg(borderWidth)
                  .arg(borderColor));
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
