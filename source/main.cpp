#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineCore>
#include <QtWebEngine/qtwebengineglobal.h>
#include <QTextCodec>
#include "textstore.h"
#include "soundstore.h"
#include "uicontroller.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForHtml("unicode"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForUtfText("unicode"));

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

#ifdef QT_WIDGETS_LIB
    QApplication app(argc, argv);
    QApplication::setApplicationName("eduEnReader");
#else
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("eduEnReader");
#endif

    QFontDatabase fontDatabase;
    if (fontDatabase.addApplicationFont(":/fonts/fontello.ttf") == -1)
        qWarning() << "Failed to load fontello.ttf";

    QStringList selectors;
#ifdef QT_EXTRA_FILE_SELECTOR
    selectors += QT_EXTRA_FILE_SELECTOR;
#else
    if (app.arguments().contains("-touch"))
        selectors += "touch";
#endif

    QQmlApplicationEngine engine;
    QQmlFileSelector::get(&engine)->setExtraSelectors(selectors);

    QUrl appPath(QString("%1").arg(app.applicationDirPath()));
    engine.rootContext()->setContextProperty("appPath", appPath);
    QtWebEngine::initialize();
    qmlRegisterType<UIController>("UiControlerModul", 1, 1, "UiControler");
    qmlRegisterType<TextStore>("TextStoreModul", 1, 0, "TextStore");
    qmlRegisterType<SoundStore>("SoundStoreModul", 1, 1, "SoundStore");
    engine.load(QUrl(QStringLiteral("qrc:/main_Read.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
