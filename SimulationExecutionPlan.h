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
    double getLatticeSize();
    void setLatticeSize(int latticeSize);

private:
       int latticeSize;

};

#endif // SIMULATIONEXECUTIONPLAN_H
