#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include <memory>
#include "persistentattribute.h"

class PersistentObject
{
private:
    std::vector<std::unique_ptr<PersistentAttribute>> mAttributes;
    QString mTable;
    int mId ;

public:
    PersistentObject(const QString &table);
    void addAttribute(std::unique_ptr<PersistentAttribute> attribute);
    int save();
};

#endif
