#include "SimulationExecutionPlan.h"

SimulationExecutionPlan::SimulationExecutionPlan()
{

}

QVector<SimulationExecutionPlanEntry *> *SimulationExecutionPlan::getEntries()
{
    return this->entries;
}

double SimulationExecutionPlan::getLatticeSize()
{
    return this->latticeSize;
}

void SimulationExecutionPlan::setLatticeSize(int latticeSize)
{
    this->latticeSize=latticeSize;
}


