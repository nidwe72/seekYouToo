#include "simulationresult.h"

SimulationResult::SimulationResult()
{
}

SimulationBetaResult* SimulationResult::getBetaResult(double beta)
{
    SimulationBetaResult* result;
    if(this->betaResults.contains(beta)){
        result=this->betaResults.value(beta);
    }else{
        result=new SimulationBetaResult(beta);
        this->betaResults.insert(beta,result);
    }
    return result;
}
