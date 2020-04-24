#include "simulationbetaresult.h"

SimulationBetaResult::SimulationBetaResult(double beta)
{
    this->beta=beta;
}

double SimulationBetaResult::getBeta()
{
    return this->beta;
}
