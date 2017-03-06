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
    QTextCodec::setCodecForLocale(QTextCodec::codecForHtml("utf-16"));
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QtWebEngine::initialize();
    qmlRegisterType<UIController>("UiControlerModul", 1, 1, "UiControler");
    qmlRegisterType<TextStore>("TextStoreModul", 1, 0, "TextStore");
    qmlRegisterType<SoundStore>("SoundStoreModul", 1, 1, "SoundStore");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
