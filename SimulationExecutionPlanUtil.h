#ifndef SIMULATIONEXECUTIONPLANUTIL_H
#define SIMULATIONEXECUTIONPLANUTIL_H

#include <QPair>
#include "SimulationExecutionPlan.h"
#include "SimulationExecutionPlanEntry.h"

#include <cmath>

class SimulationExecutionPlanUtil
{
public:    
    static SimulationExecutionPlan* createFastExecutionPlan();
    static QPair<int,int>* getExecutionPlanRange(SimulationExecutionPlan* simulationExecutionPlan);

private:
    SimulationExecutionPlanUtil();

};

#endif // SIMULATIONEXECUTIONPLANUTIL_H
