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
    PersistentObject(const QString &table, int id);
    ~PersistentObject();
    void addAttribute(const QString &name, QVariant::Type type, void* data);
    int save();

protected:
    std::vector<AttributePtr> mAttributes;
    QString mTable;
    int mId;
};

#endif
