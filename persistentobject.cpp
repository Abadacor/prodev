#include <QtSql>
#include <iostream>
#include <memory>
#include "persistentobject.h"

PersistentObject::PersistentObject(const QString &table, int id)
    :mTable(table)
    ,mId(id)
{
}

PersistentObject::~PersistentObject()
{
    mAttributes.clear();
}

void PersistentObject::addAttribute(const QString &name, QVariant::Type type, void* data)
{
    mAttributes.push_back(new PersistentAttribute(name, type, data));
}

int PersistentObject::save()
{
    // DB stuff
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(mTable + ".db");

    if(!db.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }

    db.close ();
    return 0;
}
