#include <iostream>
#include "library.h"

Library::Library(const QString& name)
    :mName(name)
{
    createDatabase();
}

void Library::createDatabase()
{
    auto database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(mName + ".db");

    // Nom du fichier SQLite
    if(!database.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }
    QString initQuery("create table if not exists Books "
              "(id integer primary key, "
              "Authors varchar(1023), "
              "Title varchar(255), "
              "Isbn integer, "
              "Year integer)");
    QSqlQuery query(database);
    query.prepare(initQuery);

    if (!query.exec())
    {
        std::cout << "Error executing query" << std::endl;
        qDebug() << query.lastError();
    }

    database.close();
}

void Library::addBook(QStringList authors, QString title, int ISBN, int year)
{
    mBooks.push_back(Book(mName, "Books", static_cast<int>(mBooks.size()), authors, title, ISBN, year));
}

void Library::loadBooks()
{
    /// Load books from database
}

void Library::saveBooks()
{
    for(auto ite: mBooks)
        ite.save();
}

void Library::printBooks()
{
    for(auto ite: mBooks)
        std::cout << ite.getTitle().toStdString() << std::endl;
}

