#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include <memory>
#include "persistentattribute.h"

class PersistentObject
{
public:
    PersistentObject(const QString &table, int id);
    ~PersistentObject();
    void addAttribute(const QString &name, QVariant::Type type, void* data);
    int save();

protected:
    std::vector<PersistentAttribute*> mAttributes;
    QString mTable;
    int mId;
};

#endif
