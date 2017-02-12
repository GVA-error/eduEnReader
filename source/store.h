#ifndef STORE_H
#define STORE_H
#include <QString>
#include <QUrl>
#include <QFileInfo>
#include <QQmlFile>
#include <QCryptographicHash>

// Базовый класс хранилища данных
// TODO Добавить проверки на нулевые указатели.
class SoundStore;
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

    // Берём относительный путь до файла, сейчас считаем что все файлы в одной директории
    QString toString(const QUrl& url) const
    {
        QString stringUrl = url.toLocalFile();// toString();
        QFileInfo info(stringUrl);
        stringUrl = info.fileName();
        return stringUrl;
    }

    // Важно: Возвращает локальный url
    QString toString() const
    {
        QUrl url = fileUrl();
        QString fileString = toString(url);
        return fileString;
    }

    // Важно: читает из локального url
    void fromString(QString storeString)
    {
        QFileInfo localFile(storeString);
        QString apsoluteStringUrl = localFile.absoluteFilePath();
        QUrl fileUrl = QUrl::fromLocalFile(apsoluteStringUrl);
        setFileUrl(fileUrl);
    }

    virtual ~Store() {
       // qDebug() << "~Store()";
    }

protected:
    QString getHash(QUrl url)
    {
        return QString("MD5"); // TODO
    }
    Store(){
        //qDebug() << "Store()";

    }
};

#endif // STORE_H
