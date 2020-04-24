#include "SimulationExecutionPlanEntry.h"

SimulationExecutionPlanEntry::SimulationExecutionPlanEntry(double beta):totalCyclesCount(40),thermalizationCyclesCount(20)
{
    this->beta=beta;
}

double SimulationExecutionPlanEntry::getBeta()
{
    return this->beta;
}
