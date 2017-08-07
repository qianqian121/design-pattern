#include <QtGui/QGuiApplication>
#include <QtQml>
#include <iostream>
//#include "qtquick2applicationviewer.h"

#include "backend.h"

void *tloop(void *ctx)
{
//    msg = context->messg;
//    struct Context *context = (struct Context *)ctx;
//    while (!context->exit_flag) {
////        cout << "." << endl;
//        sleep(1);
//    }
//    while(1)
//        std::cout << "." << std::endl;
//    joystickloop();
    return(NULL);
//    pthread_exit(NULL);
}

void spawnControl() {
    pthread_t tid;
        pthread_create(&tid, NULL, tloop, (void*)NULL);

}


int main(int argc, char *argv[])
{
//    spawnControl();
    QGuiApplication app(argc, argv);

    qmlRegisterType<BackEnd>("backend", 1, 0, "BackEnd");

//    QtQuick2ApplicationViewer viewer;
//    viewer.setMainQmlFile(QStringLiteral("qml/qt-quick/main.qml"));
//    viewer.showExpanded();
    QQmlApplicationEngine engine;
//   // engine.load(Qurl(QStringLiteral("../qml/qt-quick/main.qml")));
    engine.load(QUrl(QStringLiteral("../qtgui/qml/qt-quick/main.qml")));

    return app.exec();
}
