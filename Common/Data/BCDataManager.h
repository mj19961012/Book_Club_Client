#ifndef BCDATAMANAGER_H
#define BCDATAMANAGER_H

#include <QObject>

class BCDataManager : public QObject
{
    Q_OBJECT
public:
    static BCDataManager& instance();
    void release();

    /// \brief 获取用户头像保存路径
    const QString& getUserHeadImgPath();

private:
    BCDataManager();
    static BCDataManager *sDataManager;

private:
    QString mUserHeadImgPath{""};
};

#endif // BCDATAMANAGER_H
