#ifndef LATTICESITE_H
#define LATTICESITE_H

#include <QObject>
#include <QSharedPointer>
#include "sun.h"

class LatticeSite : public QObject
{
    Q_OBJECT
public:
    explicit LatticeSite(QObject *parent = nullptr);        
    ~LatticeSite();

    QSharedPointer<SuN> at;
    QSharedPointer<SuN> ax;
    QSharedPointer<SuN> ay;
    QSharedPointer<SuN> az;

signals:

};

#endif // LATTICESITE_H
