#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include <memory>
#include "persistentattribute.h"

class PersistentObject
{
private:
    QList<std::unique_ptr<PersistentAttribute>> mAttributes;
    QString mTable;
    int mId ;

public:
    PersistentObject(const QString &className);
    void addAttribute(PersistentAttribute &attribute);
    int save ();
};

#endif
