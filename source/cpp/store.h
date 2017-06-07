#ifndef STORE_H
#define STORE_H
#include <QString>
#include <QUrl>
#include <QDir>
#include <QFileInfo>
#include <QQmlFile>
#include <QCryptographicHash>
#include "cpp/Utilits/setting.h"

// Базовый класс хранилища данных
// TODO Добавить проверки на нулевые указатели.
//class SoundStore;
template <class StoreType> // Нужна для фабрики
class Store
{
public:
    virtual QUrl fileUrl() const = 0;
    virtual void setFileUrl(const QUrl& url) = 0;

    typedef QSharedPointer <StoreType> PTR;
    static QSharedPointer <StoreType> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <StoreType> (new StoreType());
        return rezPtr;
    }
    QString getHash()
    {
        QUrl url = fileUrl();
        QString md5 = getHash(url);
        return md5;
    }
    QString toString(const QUrl& url, QString curPath) const
    {
        if (isRemoteSource(url))
            return url.toString();

        QString stringUrl = url.toLocalFile();// toString();
        QDir curDir = QDir(curPath);
        stringUrl = curDir.relativeFilePath(stringUrl);
        return stringUrl;
    }
    QString toString(QString curPath) const
    {
        QUrl url = fileUrl();
        QString fileString = toString(url, curPath);
        return fileString;
    }
    QString getFileName()
    {
        QString fileName = fileUrl().fileName();
        return fileName;
    }
    static bool isRemoteSource(QString storeString)
    {
        //bool isRemote = QUrl(storeString).isLocalFile() == false; - не работает если в начале не указывать file:///
        auto httpI = storeString.indexOf("http");
        if (httpI !=0)
            return false;
        return true;
    }
    static bool isRemoteSource(QUrl url)
    {
        QString urlStrin = url.toString();
        return isRemoteSource(urlStrin);
    }
    // TODO в данный момент потдерживаются только относительные пути
    // в дирректории ниже исполнительного файла
    void fromString(QString storeString, QString curPath)
    {
        QUrl fileUrl;
        bool isRemote = isRemoteSource(storeString);
        if (isRemote)
            fileUrl = QUrl(storeString);
        else
        {
            storeString = curPath + "/" + storeString;
            QFileInfo localFile(storeString);
            if (localFile.exists() == false)
            {
                QString defaultRemoteSource = Settings::get(Settings::DefaultRemoteSource, Settings::Location).toString();
                defaultRemoteSource = defaultRemoteSource.trimmed();
                QString remoteAnalog = defaultRemoteSource + localFile.fileName();
                fileUrl = QUrl(remoteAnalog);
                if (defaultRemoteSource.length() == 0)
                    return;
            }
            else
            {
                QString apsoluteStringUrl = localFile.absoluteFilePath();
                fileUrl = QUrl::fromLocalFile(apsoluteStringUrl);
            }
        }
        setFileUrl(fileUrl);
    }
    virtual ~Store() {
       // qDebug() << "~Store()";
    }
protected:
    QString getHash(QUrl url)
    {
        return QString("MD5"); // так как используем удалённые истоники не используем
    }
    Store(){
        //qDebug() << "Store()";
    }
};

#endif // STORE_H
