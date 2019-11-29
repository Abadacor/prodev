#include <QtSql>
#include <iostream>
#include <memory>
#include "persistentobject.h"

PersistentObject::PersistentObject(const QString &table, const QString &dbName, int id)
    :mTable(table)
    ,mDbName(dbName)
    ,mId(id)
{
}

PersistentObject::~PersistentObject()
{
    mAttributes.clear();
}

void PersistentObject::addAttribute(const QString &name, QVariant::Type type, void* data)
{
    mAttributes.push_back(AttributePtr(new PersistentAttribute(name, type, data)));
}

int PersistentObject::save()
{
    // DB stuff
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(mTable + ".db");

    if(!db.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }
    QString queryString("insert into " + mDbName + "(Id,");
    QString insertStatement(") values(" + QString::number(mId) + ", ");
    QString updateStatement(") on duplicate key update ");
    for (auto attribute : mAttributes)
    {
        auto attributeType(static_cast<QMetaType::Type>(attribute->mType));
        QString attributeString(attributeType == QMetaType::QString
                                || attributeType == QMetaType::QStringList ?
                                    "'" + attribute->dataToString() + "'" : attribute->dataToString());
        updateStatement = updateStatement +attribute->mName + " = " + attributeString + ", ";
        queryString = queryString + attribute->mName + ",";
        insertStatement = insertStatement + attributeString + ", ";
    }
    queryString.chop(1);
    insertStatement.chop(2);
    updateStatement.chop(2);
    queryString = queryString + insertStatement + updateStatement + ";";
    qDebug() << queryString;
    QSqlQuery query(db);
    query.prepare(queryString);

    if (!query.exec())
    {
        std::cout << "Error executing query" << std::endl;
        qDebug() << query.lastError();
    }

    db.close ();
    return 0;
}
