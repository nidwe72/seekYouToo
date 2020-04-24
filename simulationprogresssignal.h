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

    enum Type { LatticeSite, LatticeSweep, Beta };

    double getValue();
    void setValue(double value);

    void setType(Type type);
    Type getType() const;

    void setExecutionPlanEntry(SimulationExecutionPlanEntry* executionPlanEntry);
    SimulationExecutionPlanEntry* getExecutionPlanEntry();

private:
    Type type;
    double value;
    SimulationExecutionPlanEntry* executionPlanEntry;

};


#endif // SIMULATIONSIGNAL_H
