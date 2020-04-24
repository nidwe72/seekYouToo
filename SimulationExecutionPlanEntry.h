#ifndef SIMULATIONEXECUTIONPLANENTRY_H
#define SIMULATIONEXECUTIONPLANENTRY_H



class SimulationExecutionPlanEntry
{
public:
    SimulationExecutionPlanEntry(double beta);
    double getBeta();
    int totalCyclesCount;
    int thermalizationCyclesCount;


private:
    double beta;

};

#endif // SIMULATIONEXECUTIONPLANENTRY_H
