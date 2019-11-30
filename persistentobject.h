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
    PersistentObject(const QString &table, const QString &dbName, int id);
    ~PersistentObject();
    void addAttribute(const QString &name, QVariant::Type type, void* data);
    int save();
    bool isInDb();
    void deleteBook();

protected:
    std::vector<AttributePtr> mAttributes;
    QString mTable;
    QString mDbName;
    int mId;
};

#endif
