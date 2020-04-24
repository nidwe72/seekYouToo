#ifndef SU3SIMULATION_H
#define SU3SIMULATION_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include <QSharedPointer>
#include <QScopedPointer>

#include "smartpointer.h"

#include "sun.h"
#include "lattice.h"
#include "staples.h"
#include "random.h"
#include "wilson.h"
#include "simulationprogresssignal.h"
#include "simulationmeasurementsignal.h"

#include "simulationresult.h"
#include "simulationbetaresult.h"

#include "SimulationExecutionPlan.h"
#include "SimulationExecutionPlanEntry.h"

class SU3Simulation : public QObject
{
    Q_OBJECT

public:

    explicit SU3Simulation(QObject *parent = 0);
    ~SU3Simulation();
    QSharedPointer<SuN> test();
    void test2(QSharedPointer<SuN>& sun);
    void update(Lattice* lattice);
    void setExecutionPlan(SimulationExecutionPlan* simulationExecutionPlan);
    SimulationExecutionPlan* getExecutionPlan();


signals:
    void on_SimulationProgressSignal(SimulationProgressSignal* simulationSignal);
    void on_SimulationMeasurementSignal(SimulationMeasurementSignal* simulationMeasurementSignal);

public slots:
    void start();
    void stop();

private:
    bool simulationStarted;
    float currentNumber=0.42516528;
    void updateLink(Lattice* lattice,int id, int mu);
    void updateSubset(Lattice* lattice, LatticeSubset* latticeSubset);    
    SimulationResult* simulationResult=nullptr;
    SimulationResult* getSimulationResult();
    SimulationExecutionPlan* executionPlan;
};


#endif // SU3SIMULATION_H
