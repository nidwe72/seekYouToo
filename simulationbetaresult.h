#ifndef SIMULATIONBETARESULT_H
#define SIMULATIONBETARESULT_H

#include <QVector>

class SimulationBetaResult
{
public:
    SimulationBetaResult(double beta);
    double getBeta();
    QVector<double> plaquettes;
    QVector<double> plaquettesStdDevs;
    QVector<QVector<double>> plaquettesHistory;
    QVector<QVector<double>> plaquettesStdDevsHistory;

private:
    double beta;

};

#endif // SIMULATIONBETARESULT_H
