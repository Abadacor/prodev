#ifndef PERSISTENTATTR_H
#define PERSISTENTATTR_H

#include <QVariant>
#include <memory>

struct PersistentAttributeVirt {
    virtual ~PersistentAttributeVirt() = 0;
    virtual std::string get() = 0;
};

template< typename T >
struct PersistentAttributeModel : PersistentAttributeVirt {
    PersistentAttributeModel(const T& t);
    virtual ~PersistentAttributeModel();
    virtual std::string get();
    T data;
};


class PersistentAttribute
{
public:
    std::shared_ptr<PersistentAttributeVirt> mData;
    QString mName;
    QVariant::Type mType;

    template<typename T>
    PersistentAttribute(T data);
};

#include "persistentattribute.tpp"

#endif
