#ifndef SETTING_H
#define SETTING_H

/*
 * Код класса взят с https://habrahabr.ru/post/149085/
*/

#include <QSettings>
#include <QMetaEnum>
#include <QRegExp>
#include <QStringList>
#include <QVariant>
#include <QSettings>
#include <QMetaEnum>
#include <QFile>

class Settings{
    Q_GADGET
    Q_ENUMS(Section)
    Q_ENUMS(Key)
public:
    enum Section{
        Video
    };

    enum Key{
        DpiScaling
    };

    class ValueRef{
    public:
        ValueRef(Settings &st, const QString &kp) :
            parent(st), keyPath(kp){}
        ValueRef & operator = (const QVariant &d);
    private:
        Settings &parent;
        const QString keyPath;
    };

    static void setDefaults(const QString &str);
    static QVariant get(Key, Section);
    static ValueRef set(Key, Section);

private:
    QString keyPath(Section, Key);
    static const QString _settingsFile;

    static Settings & instance();
    QMetaEnum keys;
    QMetaEnum sections;
    QMap<QString, QVariant> defaults;
    QSettings conf;

    Settings();
    Settings(const Settings &);
    Settings & operator = (const Settings &);
};

#endif // SETTING_H
