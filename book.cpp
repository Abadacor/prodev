#include "book.h"

Book::Book(const QString &table, const QString &dbName, int id, QStringList &authors, QString &title, int ISBN, int year)
    :PersistentObject(table, dbName, id)
    ,mAuthors(authors)
    ,mTitle(title)
    ,mISBN(ISBN)
    ,mYear(year)
{
    addAttribute("Authors", QVariant::StringList, &authors);
    addAttribute("Title", QVariant::String, &title);
    addAttribute("ISBN", QVariant::Int, &ISBN);
    addAttribute("Year", QVariant::Int, &year);
}

QString Book::getTitle() const
{
    return mTitle;
}
