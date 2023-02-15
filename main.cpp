#include "mainwindow.h"
#include <QApplication>
#include <add.h>
//#include "mainwindow.cpp"



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Authorization");
    w.show();


    return a.exec();
}
