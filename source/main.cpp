#ifdef QT_WIDGETS_LIB
#include <QApplication>
#define Application QApplication
#else
#include <QGuiApplication>
#define Application QGuiApplication
#endif
#include <QQmlApplicationEngine>
#include <QTextCodec>
#include <QFontDatabase>
#include <QQuickStyle>
#include <QtWebEngine>

#include "cpp/textstore.h"
#include "cpp/soundstore.h"
#include "cpp/uicontroller.h"
#include "cpp/Utilits/setting.h"

const QDir input = QDir("/home/gva/Desktop/input");
const QDir output = QDir("/home/gva/Desktop/output");

void clearInput()
{
    DataPreparation::clearDir(input);
    DataPreparation::clearTrash();
}

bool copyInOutput()
{
    QStringList mask;
    mask.push_back("*.bnd");
    mask.push_back("*.html");
    mask.push_back("*.txt");
    mask.push_back("*.mp4");
    mask.push_back("*.wav");
    return DataPreparation::copy(input, output, mask);
}

void handleInputFiles()
{
    QFile file("Log.txt");
    file.open(QFile::WriteOnly);
    QTextStream fileStream(&file);
    QTime curTime;
    fileStream << "Begin binding time: " << curTime.toString();
    QStringList bindFiles = input.entryList(QStringList("*.mp4"));
    auto soundStore = SoundStore::factoryMethod();
    auto textStore = TextStore::factoryMethod();
    auto logic = Logic::factoryMethod();
    auto bindMaker = BindMaker::factoryMethod(textStore, soundStore, logic);

    for (QString mp4 : bindFiles)
    {
        QUrl url = QUrl::fromLocalFile(mp4);
        fileStream << "File " << url.toString() << " begin: " << curTime.toString();
        QString fileName = input.absolutePath() + "/" + url.toLocalFile();
        logic->createFromNewSoundFile(fileName, textStore, soundStore);
        bindMaker->setSplitSize(4.0f, 2.0f);
        bindMaker->runInThisThread();
       // _logic->bindLogicHanding();
        logic->writeInFile(textStore, soundStore);
        fileStream << "File " << url.toString() << " end: " << curTime.toString();
    }
    fileStream << "End binding time: " << curTime.toString();

    qDebug() << "ok. Well done!";
}

int main(int argc, char *argv[])
{
    Settings::setDefaults();
    const bool f_cmd = false;

    if (f_cmd)
    {
        handleInputFiles();
        if (copyInOutput())
            clearInput();
        return 0;
    }

    int enum_index = qt_getQtMetaObject()->indexOfEnumerator("ApplicationAttribute");
    QString dpiScaling = Settings::get(Settings::DpiScaling, Settings::Video).toString();
    auto enumerator = qt_getQtMetaObject()->enumerator(enum_index);
    Qt::ApplicationAttribute dpiScalingKey = (Qt::ApplicationAttribute)(enumerator.keysToValue(dpiScaling.toLatin1()));

    Application app(argc, argv);
    QCoreApplication::setAttribute(dpiScalingKey);
    Application::setApplicationName("eduEnReader");
    QApplication::setOrganizationName("gva-error");

    QQmlApplicationEngine engine;

    QFontDatabase fontDatabase;
    if (fontDatabase.addApplicationFont(":/fonts/fontello.ttf") == -1)
        qWarning() << "Failed to load fontello.ttf";
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QUrl appPath(QString("%1").arg(app.applicationDirPath()));
    engine.rootContext()->setContextProperty("appPath", appPath);

    QtWebEngine::initialize();
    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
    VlcQmlVideoPlayer::registerPlugin();

    qmlRegisterType<UIController>("UiControllerModul", 1, 2, "UiController");
    qmlRegisterType<TextStore>("TextStoreModul", 1, 0, "TextStore");
    qmlRegisterType<SoundStore>("SoundStoreModul", 1, 1, "SoundStore");
    qmlRegisterType<QML_Settings>("QML_SettingsModul", 1, 0, "QML_Settings");
    engine.load(QUrl(QStringLiteral("qrc:/qml/READ_main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();


    return 0;
}
