#include "persistentattribute.h"

template<class T>
PersistentAttribute<T>::PersistentAttribute(const QString &name, QVariant::Type type)
    :mName(name)
    ,mType(type)
{

}
