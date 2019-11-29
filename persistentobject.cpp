#include <QtSql>
#include <iostream>
#include "persistentobject.h"

PersistentObject::PersistentObject(const QString &table)
    :mTable(table)
{
}

void PersistentObject::addAttribute(std::unique_ptr<PersistentAttribute> attribute)
{
    mAttributes.push_back(std::move(attribute));
}

int PersistentObject::save()
{
    // DB stuff
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");

    if(!db.open()){
        std::cout <<"Unable to open the database."<< endl;
    }

    db.close ();*/
    return 0;
}
