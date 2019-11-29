#include "book.h"

Book::Book(const QString &table, int id, QStringList &authors, QString &title, int ISBN, int year)
    :PersistentObject(table, id)
    ,mAuthors(authors)
    ,mTitle(title)
    ,mISBN(ISBN)
    ,mYear(year)
{
    addAttribute("Author", QVariant::StringList, &authors);
    addAttribute("Title", QVariant::String, &title);
    addAttribute("ISBN", QVariant::Int, &ISBN);
    addAttribute("Year", QVariant::Int, &year);
}

QString Book::getTitle() const
{
    return mTitle;
}
