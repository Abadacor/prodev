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
    Library lib("Library");
    lib.loadBooks();
    lib.addBook(QStringList("Moi"), "ezkn", 12, 12);
    lib.addBook(QStringList("Moi"), "ELELzO", 54, 46554);
    lib.addBook(QStringList("Moi"), "ELEzzLO", 54, 46554);
    lib.addBook(QStringList("Moi"), "zzzELELO", 54, 46554);
    lib.printBooks();
    lib.saveBooks();
    lib.deleteBook(0);
    lib.printBooks();
    lib.saveBooks();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    //Test SQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");

    // Nom du fichier SQLite
    if(!db.open()){
        std::cout <<"Unable to open the database."<< endl;
    }

    db.close ();
    */

    return a.exec();
    //return 0;
}
