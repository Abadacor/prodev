#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include <memory>
#include "persistentattribute.h"

class PersistentObject
{
public:
    using AttributePtr = std::shared_ptr<PersistentAttribute>;

public:
    PersistentObject(const QString &table, const QString &dbName, QString primaryKeyField);
    ~PersistentObject();
    void addAttribute(const QString &name, QVariant::Type type, void* data);
    int save(QString primaryKeyValue);
    bool isInDb(QString primaryKeyValue);
    void deleteBook(QString primaryKeyValue);

protected:
    std::vector<AttributePtr> mAttributes;
    QString mTable;
    QString mDbName;
    QString mPrimaryKeyField;
};

#endif
