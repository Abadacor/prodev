#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <QtSql>
#include <memory>
#include "book.h"

class Library
{
public:
    Library(const QString &name);
    void    createDatabase();
    void    addBook(QStringList authors, QString title, QString ISBN, int year);
    void    loadBooks();
    void    deleteBook(QString isbn);
    void    saveBooks();
    void    printBooks();
    std::vector<std::unique_ptr<Book>>& getBooks();

private:
    QString             mName;
    std::vector<std::unique_ptr<Book>>   mBooks;
};

#endif // LIBRARY_H

