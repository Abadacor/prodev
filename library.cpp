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
              "(Authors varchar(1023), "
              "Title varchar(255), "
              "Isbn integer primary key, "
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
    mBooks.push_back(Book(mName, "Books", authors, title, ISBN, year));
}

void Library::deleteBook(int isbn)
{
    for (auto ite = mBooks.begin(); ite != mBooks.end(); ite++)
    {
        if (ite->getISBN() == isbn)
        {
            ite->deleteBook(isbn);
            mBooks.erase(ite);
        }
    }

}

void Library::loadBooks()
{
    auto database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(mName + ".db");

    // Nom du fichier SQLite
    if(!database.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }
    QString initQuery("select * from books order by id asc");
    QSqlQuery query(database);
    query.prepare(initQuery);

    if (!query.exec())
    {
        std::cout << "Error executing query" << std::endl;
        qDebug() << query.lastError();
    }
    while(query.next())
    {
        QStringList authors = query.value(1).toStringList();
        QString title = query.value(2).toString();
        int isnb = query.value(3).toInt();
        int year = query.value(4).toInt();
        addBook(authors, title, isnb, year);
    }

    database.close();
}

void Library::saveBooks()
{
    for(auto book: mBooks)
        book.save(book.getISBN());
}

void Library::printBooks()
{
    for(auto ite: mBooks)
        std::cout << ite.getTitle().toStdString() << std::endl;
}

std::vector<Book>& Library::getBooks()
{
    return mBooks;
}

