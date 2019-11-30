#include "persistentattribute.h"


PersistentAttribute::PersistentAttribute(const QString &name, QVariant::Type type, void* data)
    :mName(name)
    ,mType(type)
    ,mData(data)

{
}

QString PersistentAttribute::dataToString()
{
    switch (static_cast<QMetaType::Type>(mType)) {
    case QMetaType::Int:
        return QString::number(*static_cast<int*>(mData));
    case QMetaType::QString:
        return *static_cast<QString*>(mData);
    case QMetaType::QStringList:
        return (*static_cast<QStringList*>(mData)).join(", ");
    default:
        throw std::invalid_argument("type of attribute not in Int, Float, QString, QStringList");
    }
}
