#ifndef BCPOLYMORPHICLABEL_H
#define BCPOLYMORPHICLABEL_H

#include <QLabel>

class BCPolymorphicLabel : public QLabel
{
    Q_OBJECT
public:
    explicit BCPolymorphicLabel(QWidget *parent = nullptr);

    /// \brief 设置样式(背景色、字体颜色、圆角值(默认为0)、边框值(默认为0)、边框颜色(默认为透明))
    void setStyle(const QString &backgroundColor,const QString& fontColor,const Qt::Alignment& textAlign,const int& borderRadius = 0,const int& border = 0,const QString& borderColor = "transparent");

    /// \brief 设置字体
    void setFontStyle(const int &fontPixelSize,const int &fontWeight = 50,const QString &fontFamily = "Microsoft YaHei");

    QFont getFont() const;
private:
    void init();

private:
    QFont mFont;
};

#endif // BCPOLYMORPHICLABEL_H
