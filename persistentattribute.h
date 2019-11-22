#ifndef PERSISTENTATTR_H
#define PERSISTENTATTR_H

#include <QVariant>

template<class T>
class PersistentAttribute
{
public:
    QString mName;
    QVariant::Type mType;
    T mData;
    PersistentAttribute(const QString &name, QVariant::Type type);
};

#include "persistentattribute.tpp"

#endif
