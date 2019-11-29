#include "persistentattribute.h"


PersistentAttribute::PersistentAttribute(const QString &name, QVariant::Type type, void* data)
    :mName(name)
    ,mType(type)
    ,mData(data)

{

}
