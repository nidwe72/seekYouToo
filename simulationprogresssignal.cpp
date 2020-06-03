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

double SimulationProgressSignal::getValue2()
{
    return this->value2;

}

void SimulationProgressSignal::setValue2(double value2)
{
    this->value2=value2;
}


double SimulationProgressSignal::getMaximumValue()
{
    return this->maximumValue;

}

void SimulationProgressSignal::setMaximumValue(double maximumValue)
{
    this->maximumValue=maximumValue;
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


