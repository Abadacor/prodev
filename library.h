#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"

class Library
{
public:
    Library();
    void    addBook(QString &author, QString &title, int ISBN, int year);

private:
    std::vector<Book>   mBooks;
};

#endif // LIBRARY_H
