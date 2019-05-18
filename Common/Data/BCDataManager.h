#ifndef BCDATAMANAGER_H
#define BCDATAMANAGER_H

#include <QObject>

class BCDataManager : public QObject
{
    Q_OBJECT
public:
    static BCDataManager& instance();
    void release();

    /// \brief 获取AppData路径
    const QString& getAppDataPath();


private:
    explicit BCDataManager(QObject *parent = nullptr);
    static BCDataManager *sDataManager;

private:
    QString mAppDataPath{""};
};

#endif // BCDATAMANAGER_H
