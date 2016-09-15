#include <QGuiApplication>
#include <QtQml>
#include <QObject>
#include <QQuickView>
#include <QQmlExtensionInterface>
#include <QQmlExtensionPlugin>
#include "textstore.h"
#include "soundstore.h"
#include "uicontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<TextStore>("TextStoreModul", 1, 0, "TextStore");
    qmlRegisterType<SoundStore>("SoundStoreModul", 1, 0, "SoundStore");
    qmlRegisterType<UIController>("UiControlerModul", 1, 0, "UiControler");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
