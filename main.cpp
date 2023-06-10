#include <iostream>

#include "mainwindow.h"
#include <travelagency.h>
//#include <QtTest/QtTest>

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TravelAgency travelAgentur;
    MainWindow w(travelAgentur);

    w.show();
    return a.exec();

}
