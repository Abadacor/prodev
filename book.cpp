#include "book.h"

Book::Book(const QString &table, const QString &dbName, QStringList &authors, QString &title, int ISBN, int year)
    :PersistentObject(table, dbName, "ISBN")
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

int Book::getISBN() const
{
    return mISBN;
}

QString Book::to_string()
{
    return mTitle + "\t" + mAuthors[0] + "\t" + QString::number(mISBN) + "\t" + QString::number(mYear) + "\n";
}
