#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <string>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cell.h"
#include "compteur.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //
    Cell grid[4][4];
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            engine.rootContext()->setContextProperty(
                QString::fromStdString("vue"+std::to_string(i+1)+"x"+std::to_string(j+1)),
                &(grid[i][j])
            );
        }
    }
    engine.load(url);

    Compteur aCompteur;
    engine.rootContext()->setContextProperty("vueObjetCpt", &aCompteur);




    return app.exec();
}
