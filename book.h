#ifndef BOOK_H
#define BOOK_H

#include "persistentobject.h"

class Book : public PersistentObject
{
public:
    Book(const QString &table, int id, QString &author, QString &title, int ISBN, int year);
    QString getAuthor() const;

private:
    QString mAuthor;
    QString mTitle;
    int mISBN;
    int mYear;
};

#endif // BOOK_H
