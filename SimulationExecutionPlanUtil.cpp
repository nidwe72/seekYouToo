#include "SimulationExecutionPlanUtil.h"

SimulationExecutionPlanUtil::SimulationExecutionPlanUtil()
{

}

SimulationExecutionPlan* SimulationExecutionPlanUtil::createFastExecutionPlan()
{
    //QVector<double> betas{0.2,1.0,2.0,3.0,4.0,5.0};
    QVector<double> betas{2.0,3.0,4.0,5.0,0.2,1.0};

    int totalCyclesCount=1;
    int thermalizationCyclesCount=1;

    SimulationExecutionPlan* result=new SimulationExecutionPlan();

    QVector<SimulationExecutionPlanEntry *> *entries = new QVector<SimulationExecutionPlanEntry *>();
    for(double beta:betas){
        SimulationExecutionPlanEntry* entry = new SimulationExecutionPlanEntry(beta);
        entry->totalCyclesCount=totalCyclesCount;
        entry->thermalizationCyclesCount=thermalizationCyclesCount;
        entries->append(entry);
    }
    result->entries=entries;
    return result;
}

QPair<int, int> *SimulationExecutionPlanUtil::getExecutionPlanRange(SimulationExecutionPlan *simulationExecutionPlan)
{
    QPair<int,int>* result=new QPair<int,int>();
    double betaLower=0;
    double betaUpper=0;
    //QVector<SimulationExecutionPlanEntry *> foo=*simulationExecutionPlan->getEntries();
    for (SimulationExecutionPlanEntry* executionPlanEntry :*simulationExecutionPlan->getEntries()) {
        double beta=executionPlanEntry->getBeta();
        if(beta>betaUpper){
            betaUpper=beta;
        }
        if(beta<betaLower){
            betaLower=beta;
        }
    }

    result->first=std::floor(betaLower);
    result->second=std::ceil(betaUpper);

    return result;
}

int SimulationExecutionPlanUtil::getExecutionPlanEntryIndex(SimulationExecutionPlan *simulationExecutionPlan, SimulationExecutionPlanEntry *simulationExecutionPlanEntry)
{
    int result=-1;
    int index=0;
    double beta=simulationExecutionPlanEntry->getBeta();
    for (SimulationExecutionPlanEntry* executionPlanEntry :*simulationExecutionPlan->getEntries()) {
        double someBeta=executionPlanEntry->getBeta();
        if(someBeta==beta){
            result=index;
            break;
        }
        index++;
    }
    return result;
}
