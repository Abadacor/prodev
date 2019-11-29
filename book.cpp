#include "book.h"

Book::Book(const QString &table, QString &author, QString &title, int ISBN, int year)
    :PersistentObject(table)
{
    addAttribute(new PersistentAttribute("Author", QVariant::String, &author));
    addAttribute(new PersistentAttribute("Title", QVariant::String, &title));
    addAttribute(new PersistentAttribute("ISBN", QVariant::String, &ISBN));
    addAttribute(new PersistentAttribute("Year", QVariant::String, &year));
}
