#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <QSharedPointer>

template <typename T>
class SmartPointer: public QSharedPointer<T>
{
public:
    SmartPointer(T* ptr);
    SmartPointer& operator+=(const SmartPointer& rhs);
};

#endif // SMARTPOINTER_H
