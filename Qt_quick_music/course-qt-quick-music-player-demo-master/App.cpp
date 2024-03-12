#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>
#include <QPushButton>
#include "httputils.h"
#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/music.png"));

    MainWindow w;
    w.show();
    return a.exec();



//    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("mainWindow", &mainWindow);
//    engine.load(QUrl(QStringLiteral("qrc:/App.qml")));


}
