#include <QtSql>
#include <iostream>
#include <memory>
#include "persistentobject.h"

PersistentObject::PersistentObject(const QString &table, const QString &dbName, QString primaryKeyField)
    :mTable(table)
    ,mDbName(dbName)
    ,mPrimaryKeyField(primaryKeyField)
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

int PersistentObject::save(int primaryKeyValue)
{
    QString queryString;

    if(!isInDb(primaryKeyValue))
    {
        queryString = "insert into " + mDbName + "(";
        QString insertStatement(") values(");

        for (auto attribute : mAttributes)
        {
            auto attributeType(static_cast<QMetaType::Type>(attribute->mType));
            QString attributeString(attributeType == QMetaType::QString
                                    || attributeType == QMetaType::QStringList ?
                                        "'" + attribute->dataToString() + "'" : attribute->dataToString());
            queryString = queryString + attribute->mName + ",";
            insertStatement = insertStatement + attributeString + ", ";
        }
        queryString.chop(1);
        insertStatement.chop(2);
        queryString = queryString + insertStatement + ");";
    }
    else {
        queryString = "update " + mDbName + " ";
        for (auto attribute : mAttributes)
        {
            auto attributeType(static_cast<QMetaType::Type>(attribute->mType));
            QString attributeString(attributeType == QMetaType::QString
                                    || attributeType == QMetaType::QStringList ?
                                        "'" + attribute->dataToString() + "'" : attribute->dataToString());
            queryString = queryString +attribute->mName + " = " + attributeString + ", ";
        }
        queryString.chop(2);
        queryString += " where " + mPrimaryKeyField + " = " + QString::number(primaryKeyValue) + ";";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(mTable + ".db");

    if(!db.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }
    QSqlQuery query(db);
    query.prepare(queryString);

    if (!query.exec())
    {
        std::cout << "Error executing query" << std::endl;
        qDebug() << query.lastError();
    }

    db.close();
    return 0;
}


bool PersistentObject::isInDb(int primaryKeyValue)
{
    // DB stuff
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(mTable + ".db");

    if(!db.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }
    QString queryString("select * from " + mDbName + " where " + mPrimaryKeyField + " = " + QString::number(primaryKeyValue));
    QSqlQuery query(db);
    query.prepare(queryString);
    if (!query.exec())
    {
        std::cout << "Error executing query" << std::endl;
        qDebug() << query.lastError();
    }
    db.close();
    if (query.next())
        return true;
    else
        return false;
}

void PersistentObject::deleteBook(int primaryKeyValue)
{
    // DB stuff
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(mTable + ".db");

    if(!db.open()){
        std::cout <<"Unable to open the database."<< std::endl;
    }
    QString queryString("delete from " + mDbName + " where " + mPrimaryKeyField + " = " + QString::number(primaryKeyValue));
    QSqlQuery query(db);
    query.prepare(queryString);
    if (!query.exec())
    {
        std::cout << "Error executing query" << std::endl;
        qDebug() << query.lastError();
    }
    db.close();
}
