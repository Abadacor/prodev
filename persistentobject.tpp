#include "persistentobject.h"
#include <iostream>

using namespace std;

PersistentObject::PersistentObject(const QString &className)
    :mTable(className)
{
    auto test = PersistentAttribute("test");
    auto test2 = PersistentAttribute(12);

    cout << test.mData->get() << endl;
    cout << test2.mData->get() << endl;
}
