#ifndef SIMULATIONRESULT_H
#define SIMULATIONRESULT_H

#include <QMap>
#include <QVector>

#include "simulationbetaresult.h"

class SimulationResult
{
public:
    SimulationResult();            
    SimulationBetaResult* getBetaResult(double beta);

private:
    QMap<double,SimulationBetaResult*> betaResults;
};

#endif // SIMULATIONRESULT_H
