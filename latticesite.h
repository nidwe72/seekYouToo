#ifndef LATTICESITE_H
#define LATTICESITE_H

#include <QObject>
#include "sun.h"

class LatticeSite : public QObject
{
    Q_OBJECT
public:
    explicit LatticeSite(QObject *parent = nullptr);    
    SuN* at;
    SuN* ax;
    SuN* ay;
    SuN* az;

signals:

};

#endif // LATTICESITE_H
