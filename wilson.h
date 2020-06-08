#ifndef WILSON_H
#define WILSON_H

#include <cmath>

#include "lattice.h"
#include "latticesubset.h"
#include "simulationprogresssignal.h"

class Wilson: public QObject
{
    Q_OBJECT

public:    
    explicit Wilson(QObject *parent = 0);
    ~Wilson();

    double average(QSharedPointer<Lattice> lattice, int height, int width);

signals:

    void on_SimulationProgressSignal(QSharedPointer<SimulationProgressSignal> simulationProgressSignal);

private:    
    double wilsonSubset(QSharedPointer<Lattice> lattice,LatticeSubset latticeSubset);
    double wilsonLoop(QSharedPointer<Lattice> lattice, int id, int mu, int nu, int height, int width);
};

#endif // WILSON_H
