#include <QApplication>
#include "MainVisu_mainwindow.h"

int main(int argc, char *argv[])
{
    //set dark palette
    Application a(argc, argv);

    MainWindow w;
    //w.installEventFilter(new MouseClickEater());
    w.showFullScreen();
    //w.show();
    return a.exec();
}

