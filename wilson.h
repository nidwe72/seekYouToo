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

    double average(Lattice* lattice, int height, int width);

signals:

    void on_SimulationProgressSignal(SimulationProgressSignal* simulationProgressSignal);

private:    
    double wilsonSubset(Lattice* lattice,LatticeSubset latticeSubset);
    double wilsonLoop(Lattice* lattice, int id, int mu, int nu, int height, int width);
};

#endif // WILSON_H
