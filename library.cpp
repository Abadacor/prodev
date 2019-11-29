#include <iostream>
#include "library.h"

Library::Library(const QString& name)
    :mName(name)
    ,mDatabase(QSqlDatabase::addDatabase("QSQLITE"))
{
}

void Library::createDatabase()
{
    mDatabase.setDatabaseName(mName + ".db");

    // Nom du fichier SQLite
    if(!mDatabase.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }

    mDatabase.close ();
}

void Library::addBook(QStringList authors, QString title, int ISBN, int year)
{
    mBooks.push_back(Book(mName, static_cast<int>(mBooks.size()), authors, title, ISBN, year));
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

