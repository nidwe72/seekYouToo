#include "simulationprogresssignal.h"

SimulationProgressSignal::SimulationProgressSignal()
{

}

double SimulationProgressSignal::getValue()
{
    return this->value;

}

void SimulationProgressSignal::setValue(double value)
{
    this->value=value;
}

void SimulationProgressSignal::setType(SimulationProgressSignal::Type type)
{
    this->type=type;
}

SimulationProgressSignal::Type SimulationProgressSignal::getType() const
{
    return this->type;
}

void SimulationProgressSignal::setExecutionPlanEntry(SimulationExecutionPlanEntry *executionPlanEntry)
{
    this->executionPlanEntry=executionPlanEntry;
}

SimulationExecutionPlanEntry *SimulationProgressSignal::getExecutionPlanEntry()
{
    return this->executionPlanEntry;
}


