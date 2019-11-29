#ifndef BOOK_H
#define BOOK_H

#include "persistentobject.h"

class Book : public PersistentObject
{
public:
    Book(const QString &table, QString &author, QString &title, int ISBN, int year);


};

#endif // BOOK_H
