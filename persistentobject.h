#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include <memory>
#include "persistentattribute.h"

template<class T>
class PersistentObject
{
private:
    QList<std::unique_ptr<PersistentAttribute<T>>> mAttributes;
    QString mTable;
    int mId;

public:
    PersistentObject(const QString &className);
    void addAttribute(PersistentAttribute<T> &attribute);
    int save();
};

#include "persistentobject.tpp"

#endif
