#ifndef BOOK_H
#define BOOK_H

#include "persistentobject.h"

class Book : public PersistentObject
{
public:
    Book(const QString &table, const QString &dbName, QStringList authors, QString &title, QString ISBN, int year);
    QString getTitle() const;
    QString getISBN() const;
    QString to_string();

private:
    QStringList mAuthors;
    QString mTitle;
    QString mISBN;
    int mYear;
};

#endif // BOOK_H
