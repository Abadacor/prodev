#include <iostream>
#include "library.h"

Library::Library(const QString& name)
    :mName(name)
    ,mDatabase(QSqlDatabase::addDatabase("QSQLITE"))
{
    mDatabase.setDatabaseName(mName + ".db");

    // Nom du fichier SQLite
    if(!mDatabase.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }

    mDatabase.close ();
}

void Library::addBook(QString &author, QString &title, int ISBN, int year)
{
    mBooks.push_back(Book(mName, mBooks.size(), author, title, ISBN, year));
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
