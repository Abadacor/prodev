#include <QApplication>
#include <QtSql>
#include <QDebug>
#include<QWidget>
#include<QSpinBox>
#include<QSlider>
#include<QHBoxLayout>
#include <iostream>

#include "mainwindow.hpp"
#include "library.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
