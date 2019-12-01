#include "book.h"

Book::Book(const QString &table, const QString &dbName, int id, QStringList &authors, QString &title, int ISBN, int year)
    :PersistentObject(table, dbName, id)
    ,mAuthors(authors)
    ,mTitle(title)
    ,mISBN(ISBN)
    ,mYear(year)
{
    addAttribute("Authors", QVariant::StringList, &mAuthors);
    addAttribute("Title", QVariant::String, &mTitle);
    addAttribute("ISBN", QVariant::Int, &mISBN);
    addAttribute("Year", QVariant::Int, &mYear);
}

QString Book::getTitle() const
{
    return mTitle;
}

QString Book::to_string()
{
    return mTitle + ", " + mAuthors[0] + ", " + QString::number(mYear) + ", " + QString::number(mISBN) + "\n";
}
