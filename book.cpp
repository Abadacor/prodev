#include "book.h"

Book::Book(const QString &table, int id, QString &author, QString &title, int ISBN, int year)
    :PersistentObject(table, id)
{
    addAttribute("Author", QVariant::String, &author);
    addAttribute("Title", QVariant::String, &title);
    addAttribute("ISBN", QVariant::String, &ISBN);
    addAttribute("Year", QVariant::String, &year);
}
