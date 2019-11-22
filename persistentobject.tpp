#include "persistentobject.h"

template<class T>
PersistentObject<T>::PersistentObject(const QString &className)
    :mTable(className)
{

}

template<class T>
void PersistentObject<T>::addAttribute(PersistentAttribute<T> &attribute)
{
    mAttributes.push_back(attribute);
}

template<class T>
int PersistentObject<T>::save()
{

}
