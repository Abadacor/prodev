#include <QApplication>
#include <QtSql>
#include <QDebug>
#include<QWidget>
#include<QSpinBox>
#include<QSlider>
#include<QHBoxLayout>
#include <iostream>

int main(int argc, char * argv[]) {
    qDebug() << QT_VERSION_STR;

    //Test SQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");

    // Nom du fichier SQLite
    if(!db.open()){
        std::cout <<"Unable to open the database."<< endl;
    }

    db.close ();

    return 0;
}