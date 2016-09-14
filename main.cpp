#include <QGuiApplication>
#include <QtQml>
#include <QObject>
#include <QQuickView>
#include <QQmlExtensionInterface>
#include <QQmlExtensionPlugin>
#include "textstore.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<TextStore>("TextStoreModul", 1, 0, "TextStore");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
