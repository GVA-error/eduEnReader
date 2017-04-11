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

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Application app(argc, argv);
    Application::setApplicationName("eduEnReader");

    QQmlApplicationEngine engine;

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
    engine.load(QUrl(QStringLiteral("qrc:/qml/main_read_desktop.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
