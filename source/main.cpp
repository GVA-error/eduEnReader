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

#include <VLCQtCore/Common.h>
#include <VLCQtQml/QmlVideoPlayer.h>

#include "cpp/textstore.h"
#include "cpp/soundstore.h"
#include "cpp/uicontroller.h"
#include "cpp/Utilits/setting.h"

int main(int argc, char *argv[])
{
    Settings::setDefaults("Video/DpiScaling:AA_EnableHighDpiScaling;");

    int enum_index = qt_getQtMetaObject()->indexOfEnumerator("ApplicationAttribute");
    QString dpiScaling = Settings::get(Settings::DpiScaling, Settings::Video).toString();
    auto enumerator = qt_getQtMetaObject()->enumerator(enum_index);
    Qt::ApplicationAttribute dpiScalingKey = (Qt::ApplicationAttribute)(enumerator.keysToValue(dpiScaling.toLatin1()));

    Application app(argc, argv);
    QCoreApplication::setAttribute(dpiScalingKey);
    Application::setApplicationName("eduEnReader");
    QApplication::setOrganizationName("gva-error");

    QQmlApplicationEngine engine;

    //Settings::setDefaults("Video/Regim: value2");

    QFontDatabase fontDatabase;
    if (fontDatabase.addApplicationFont(":/fonts/fontello.ttf") == -1)
        qWarning() << "Failed to load fontello.ttf";

    QUrl appPath(QString("%1").arg(app.applicationDirPath()));
    engine.rootContext()->setContextProperty("appPath", appPath);

    QtWebEngine::initialize();
    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
    VlcQmlVideoPlayer::registerPlugin();

    qmlRegisterType<UIController>("UiControlerModul", 1, 1, "UiControler");
    qmlRegisterType<TextStore>("TextStoreModul", 1, 0, "TextStore");
    qmlRegisterType<SoundStore>("SoundStoreModul", 1, 1, "SoundStore");
    qmlRegisterType<QML_Settings>("QML_SettingsModul", 1, 0, "QML_Settings");
    engine.load(QUrl(QStringLiteral("qrc:/qml/PC_READ_main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
