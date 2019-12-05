#include "book.h"

Book::Book(const QString &table, const QString &dbName, QStringList &authors, QString &title, QString ISBN, int year)
    :PersistentObject(table, dbName, "ISBN")
    ,mAuthors(authors)
    ,mTitle(title)
    ,mISBN(ISBN)
    ,mYear(year)
{
    addAttribute("Title", QVariant::String, &mTitle);
    addAttribute("ISBN", QVariant::String, &mISBN);
    addAttribute("Authors", QVariant::StringList, &mAuthors);
    addAttribute("Year", QVariant::Int, &mYear);
}

QString Book::getTitle() const
{
    return mTitle;
}

QString Book::getISBN() const
{
    return mISBN;
}

QString Book::to_string()
{
    QString authors = "";
    for(auto auth : mAuthors)
        authors += auth + ", ";
    return mTitle + "\t" + authors + "\t" + mISBN + "\t" + QString::number(mYear) + "\n";
}
