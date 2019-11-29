#include "library.h"

Library::Library()
{

}

void Library::addBook(QString &author, QString &title, int ISBN, int year)
{
    mBooks.push_back(Book("Book", author, title, ISBN, year));
}
