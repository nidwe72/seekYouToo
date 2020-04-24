#include "SimulationExecutionPlan.h"

SimulationExecutionPlan::SimulationExecutionPlan()
{

}

QVector<SimulationExecutionPlanEntry *> *SimulationExecutionPlan::getEntries()
{
    return this->entries;
}


