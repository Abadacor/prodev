#ifndef PERSISTENTATTR_H
#define PERSISTENTATTR_H

#include <QVariant>

class PersistentAttribute
{
public:
    QString mName;
    QVariant::Type mType;
    QString mData;
    PersistentAttribute(const QString &name, QVariant::Type type);
};

#endif
