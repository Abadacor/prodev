#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <QtSql>
#include "book.h"

class Library
{
public:
    Library(const QString &name);
    void    createDatabase();
    void    addBook(QStringList authors, QString title, int ISBN, int year);
    void    loadBooks();
    void    deleteBook(int id);
    void    saveBooks();
    void    printBooks();
    std::vector<Book> getBooks();

private:
    QString             mName;
    std::vector<Book>   mBooks;
};

#endif // LIBRARY_H

