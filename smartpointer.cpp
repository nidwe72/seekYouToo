#include "smartpointer.h"


template<typename T>
SmartPointer<T>::SmartPointer(T* ptr):QSharedPointer<T>(ptr)
{

}

template<typename T>
SmartPointer<T>& SmartPointer<T>::operator+=(const SmartPointer<T>& rhs)
{
    (*this->data())+=rhs.data();
    return *this;

}
