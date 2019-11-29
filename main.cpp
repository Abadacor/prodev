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

int main() {
    qDebug() << QT_VERSION_STR;

    Library lib("Library");
    lib.addBook(QStringList("Moi"), "ezkn", 12, 12);
    lib.printBooks();
    //lib.saveBooks(); crashes

    /*
    QApplication a(argc, argv);
    MainWindow w;

//    w.show();


    //Test SQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");

    // Nom du fichier SQLite
    if(!db.open()){
        std::cout <<"Unable to open the database."<< endl;
    }

    db.close ();
*/
    //return a.exec();
    return 0;
}
