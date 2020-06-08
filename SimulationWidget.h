#ifndef SIMULATIONWIDGET_H
#define SIMULATIONWIDGET_H

#include <QWidget>
#include <QSharedPointer>
#include <QLabel>
#include "wilsonloopwidget.h"
#include "simulationprogresssignal.h"
#include "simulationmeasurementsignal.h"
#include "simulationprogresswidget.h"

#include "SimulationExecutionPlan.h"
#include "SimulationExecutionPlanWidget.h"

class SimulationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWidget(QWidget *parent = nullptr);
    void handleSimulationProgressSignal(QSharedPointer<SimulationProgressSignal> simulationProgressSignal);
    void handleSimulationMeasurementSignal(QSharedPointer<SimulationMeasurementSignal> simulationMeasurementSignal);
    void setExecutionPlan(SimulationExecutionPlan* simulationExecutionPlan);
    SimulationExecutionPlan* getExecutionPlan();



signals:

    void on_SimulationProgressSignal(SimulationProgressSignal *simulationProgressSignal);
    void on_SimulationMeasurementSignal(SimulationMeasurementSignal *simulationMeasurementSignal);

private:
    QVector<WilsonLoopWidget*> wilsonLoopWidgets;
    SimulationProgressWidget* simulationProgressWidget;
    SimulationExecutionPlanWidget* executionPlanWidget;
    SimulationExecutionPlan* executionPlan;
    QWidget* createWilsonLoopsContainerWidget();

};

#endif // SIMULATIONWIDGET_H
