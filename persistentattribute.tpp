#include "persistentattribute.h"
#include <sstream>

template<typename T>
PersistentAttributeModel<T>::PersistentAttributeModel(const T& t)
    :data(t)
{
}

template<typename T>
PersistentAttributeModel<T>::~PersistentAttributeModel()
{

}

PersistentAttributeVirt::~PersistentAttributeVirt()
{

}

std::string PersistentAttributeVirt::get()
{
    return "Virtual";
}

template<typename T>
std::string PersistentAttributeModel<T>::get()
{
     std::stringstream ss;
     ss << data;
     return ss.str();
}

template<typename T>
PersistentAttribute::PersistentAttribute(T data )
    :mData(new PersistentAttributeModel<T>(data))
{

}
