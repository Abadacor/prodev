#ifndef BOOK_H
#define BOOK_H

#include "persistentobject.h"

class Book : public PersistentObject
{
public:
    Book(const QString &table, const QString &dbName, QStringList &authors, QString &title, int ISBN, int year);
    QString getTitle() const;
    int getISBN() const;
    QString to_string();

private:
    QStringList mAuthors;
    QString mTitle;
    int mISBN;
    int mYear;
};

#endif // BOOK_H
