#include "BCPolymorphicLabel.h"
#include <QPixmap>

BCPolymorphicLabel::BCPolymorphicLabel(QWidget *parent)
    :QLabel (parent)
{
    init();
}

void BCPolymorphicLabel::setStyle(const QString &backgroundColor, const QString &fontColor, const Qt::Alignment &textAlign, const int &borderRadius, const int &border, const QString &borderColor)
{
    setAlignment(textAlign);

    setStyleSheet(QString("QLabel#ACPolymorphicLabel{"
                          "background-color:%1;"
                          "color:%2;"
                          "border-radius:%3px;"
                          "border:%4px solid %5;"
                          "}"
                          "QToolTip{"
                          "background-color:white;"
                          "color: rgba(51,51,51,1);"
                          "font-family:Microsoft YaHei;"
                          "font-size:18px;"
                          "}")
                  .arg(backgroundColor)
                  .arg(fontColor)
                  .arg(borderRadius)
                  .arg(border)
                  .arg(borderColor));
}

void BCPolymorphicLabel::setFontStyle(const int &fontPixelSize, const int &fontWeight, const QString &fontFamily)
{
    QFont font;
    font.setFamily(fontFamily);
    font.setPixelSize(fontPixelSize);
    font.setWeight(fontWeight);

    mFont = font;

    setFont(font);
}

QFont BCPolymorphicLabel::getFont() const
{
    return mFont;
}

void BCPolymorphicLabel::init()
{
    setObjectName("ACPolymorphicLabel");
}
