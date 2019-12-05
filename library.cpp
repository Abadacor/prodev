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
              "(Title varchar(255), "
              "Authors varchar(1023), "
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

void Library::addBook(QStringList authors, QString title, QString ISBN, int year)
{
    std::unique_ptr<Book> bookPtr(new Book(mName, "Books", authors, title, ISBN, year));
    mBooks.push_back(std::move(bookPtr));
}

void Library::deleteBook(QString isbn)
{
    for (auto ite = mBooks.begin(); ite != mBooks.end(); ite++)
    {
        if ((*ite)->getISBN() == isbn)
        {
            (*ite)->deleteBook(isbn);
            mBooks.erase(ite);
        }
    }
}

void Library::loadBooks()
{
    mBooks = std::vector<std::unique_ptr<Book>>();
    auto database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(mName + ".db");

    // Nom du fichier SQLite
    if(!database.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }
    QString initQuery("select * from books order by isbn asc");
    QSqlQuery query(database);
    query.prepare(initQuery);

    if (!query.exec())
    {
        std::cout << "Error executing query" << std::endl;
        qDebug() << query.lastError();
    }
    while(query.next())
    {
        QString title = query.value(0).toString();
        QStringList authors = query.value(1).toStringList();
        QString isnb = query.value(2).toString();
        int year = query.value(3).toInt();
        addBook(authors, title, isnb, year);
    }

    database.close();
}

void Library::saveBooks()
{
    for(auto ite = mBooks.begin(); ite != mBooks.end(); ite++)
        (*ite)->save((*ite)->getISBN());
}

void Library::printBooks()
{
    for(auto ite = mBooks.begin(); ite != mBooks.end(); ite++)
        std::cout << (*ite)->getTitle().toStdString() << std::endl;
}

std::vector<std::unique_ptr<Book>>& Library::getBooks()
{
    return mBooks;
}

