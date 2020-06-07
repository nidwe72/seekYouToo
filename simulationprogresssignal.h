#ifndef SIMULATIONSIGNAL_H
#define SIMULATIONSIGNAL_H

#include <QString>
#include <QObject>

#include "SimulationExecutionPlanEntry.h"


class SimulationProgressSignal : public QObject
{
    Q_ENUMS(Type)

public:
    SimulationProgressSignal();

    enum Type { LatticeSite, LatticeSweep, Beta, MeasurementLatticeSite };

    double getValue();
    void setValue(double value);

    double getValue2();
    void setValue2(double value2);


    double getMaximumValue();
    void setMaximumValue(double value);

    void setType(Type type);
    Type getType() const;

    void setExecutionPlanEntry(SimulationExecutionPlanEntry* executionPlanEntry);
    SimulationExecutionPlanEntry* getExecutionPlanEntry();

private:
    Type type;
    double value;
    double value2;
    double maximumValue;
    SimulationExecutionPlanEntry* executionPlanEntry;

};


#endif // SIMULATIONSIGNAL_H
