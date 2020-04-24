#ifndef SIMULATIONEXECUTIONPLAN_H
#define SIMULATIONEXECUTIONPLAN_H

#include <QVector>
#include "SimulationExecutionPlanEntry.h"

class SimulationExecutionPlan
{
public:
    SimulationExecutionPlan();    
    QVector<SimulationExecutionPlanEntry*>* entries;
    QVector<SimulationExecutionPlanEntry*>* getEntries();
private:

};

#endif // SIMULATIONEXECUTIONPLAN_H
