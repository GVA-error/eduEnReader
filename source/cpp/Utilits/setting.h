#ifndef SETTING_H
#define SETTING_H

/*
 * Код класса взят с https://habrahabr.ru/post/149085/
*/

#include <QObject>
#include <QSettings>
#include <QMetaEnum>
#include <QRegExp>
#include <QStringList>
#include <QVariant>
#include <QSettings>
#include <QMetaEnum>
#include <QFile>
#include <QColor>

class Settings{
    Q_GADGET
    Q_ENUMS(Section)
    Q_ENUMS(Key)
public:
    enum Section{
        Video,
        TextViewer,
        Location,
        Behavior,
        Examples,
        CrationOptions
    };

    enum Key{
        DpiScaling, // Использование dpiScaling - на некоторых системах помогает избавиться от графических глюков
        ShowLectureText, // Показ текста к основному видео
        ShowExampleText, // .. к видео примерам
        TextMarkColor, // Каким цветом помечаем бинды
        ExampleSize, // Желаемый размер примеров в секундах
        ExampleDiff, // На сколько можно отклониться от размера примеров
        BindLocation, // не используется.
        ShowTranslateDialog, // Показывать диалог перевода вместо страници перевода
        postfix, // Постфикс который может добавлятся к корню во время поиска примеров
        showUserLikeComments, // Показывать комментарии при редактировании как их видит пользователь
        AutoCommentNumber, // количество биндов в одном комментарии при автоматиеском создании комментариев
        DefaultRemoteSource // Если видео файла ненайдётся на текущей машине, он будет взят с данного ресурса
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

    static void setDefaults();
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

// Qml обёртка для settings
class QML_Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool showLectureText READ showLectureText WRITE setShowLectureText NOTIFY showLectureTextChanged)
    Q_PROPERTY(bool showExampleText READ showExampleText WRITE setShowExampleText NOTIFY showExampleTextChanged)
    Q_PROPERTY(qint32 exampleSize READ exampleSize WRITE setExampleSize NOTIFY exampleSizeChanged)
    Q_PROPERTY(qint32 exampleDiff READ exampleDiff WRITE setExampleDiff NOTIFY exampleDiffChanged)
    Q_PROPERTY(QColor textMarkColor READ textMarkColor WRITE setTextMarkColor NOTIFY textMarkColorChanged)
    Q_PROPERTY(bool showTranslateDialog READ showTranslateDialog WRITE setShowTranslateDialog NOTIFY showTranslateDialogChanged)
    Q_PROPERTY(bool showUserLikeComments READ showUserLikeComments WRITE setShowUserLikeComments NOTIFY showUserLikeCommentsChanged)
    Q_PROPERTY(qint32 autoCommentNumber READ autoCommentNumber WRITE setAutoCommentNumber NOTIFY autoCommentNumberChanged)
public:
    explicit QML_Settings(QObject* parent = 0);

public slots:
    bool showLectureText() const {
        return Settings::get(Settings::ShowLectureText, Settings::TextViewer).toBool();
    }
    void setShowLectureText(const bool& newValue) {
        Settings::set(Settings::ShowLectureText, Settings::TextViewer) = newValue;
    }
    bool showExampleText() const {
        return Settings::get(Settings::ShowExampleText, Settings::TextViewer).toBool();
    }
    void setShowExampleText(const bool& newValue) {
        Settings::set(Settings::ShowExampleText, Settings::TextViewer) = newValue;
    }
    QColor textMarkColor() const {
        QString colorStrig = Settings::get(Settings::TextMarkColor, Settings::TextViewer).toString();
        QStringList colorStringList = colorStrig.split("_");
        QString rString = *(colorStringList.begin());
        QString gString = *(colorStringList.begin() + 1);
        QString bString = *(colorStringList.begin() + 2);
        QString aString = *(colorStringList.begin() + 3);
        QColor rezColor = QColor(rString.toInt(),
                                 gString.toInt(),
                                 bString.toInt(),
                                 aString.toInt());
        return rezColor;
    }
    void setTextMarkColor(const QColor& newValue) {
        QString colorText = QString("%1_%2_%3_%4")
        .arg(newValue.red())
        .arg(newValue.green())
        .arg(newValue.blue())
        .arg(newValue.alpha());
        Settings::set(Settings::TextMarkColor, Settings::TextViewer) = colorText;
    }
    qint32 exampleSize() const {
        return Settings::get(Settings::ExampleSize, Settings::TextViewer).toInt();
    }
    void setExampleSize(const qint32& newValue) {
        Settings::set(Settings::ExampleSize, Settings::TextViewer) = newValue;
    }
    qint32 exampleDiff() const {
        return Settings::get(Settings::ExampleDiff, Settings::TextViewer).toInt();
    }
    void setExampleDiff(const qint32& newValue) {
        Settings::set(Settings::ExampleDiff, Settings::TextViewer) = newValue;
    }
    bool showTranslateDialog() const{
        return Settings::get(Settings::ShowTranslateDialog, Settings::Behavior).toBool();
    }
    void setShowTranslateDialog(bool newValue){
        Settings::set(Settings::ShowTranslateDialog, Settings::Behavior) = newValue;
    }
    bool showUserLikeComments(){
        return Settings::get(Settings::showUserLikeComments, Settings::Behavior).toBool();
    }
    void setShowUserLikeComments(bool newValue){
        Settings::set(Settings::showUserLikeComments, Settings::Behavior) = newValue;
    }
    qint32 autoCommentNumber(){
        return Settings::get(Settings::AutoCommentNumber, Settings::CrationOptions).toInt();
    }
    void setAutoCommentNumber(qint32 newValue){
        Settings::set(Settings::AutoCommentNumber, Settings::CrationOptions) = newValue;
    }
signals:
    void showLectureTextChanged();
    void showExampleTextChanged();
    void textMarkColorChanged();
    void exampleSizeChanged();
    void exampleDiffChanged();
    void showTranslateDialogChanged();
    void showUserLikeCommentsChanged();
    void autoCommentNumberChanged();
private:
    void setDefaults();
};

#endif // SETTING_H
