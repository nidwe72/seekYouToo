#ifndef SIMULATIONMEASUREMENTSIGNAL_H
#define SIMULATIONMEASUREMENTSIGNAL_H

#include<QVector>
#include <QObject>

class SimulationMeasurementSignal: public QObject
{
    public:
        SimulationMeasurementSignal();
        QVector<double> getPlaquettes();
        void setPlaquettes(QVector<double> plaquettes);

        QVector<double> getPlaquettesStdDevs();
        void setPlaquettesStdDevs(QVector<double> plaquettesStdDevs);

        QVector<double> getPlaquettesMeans();
        void setPlaquettesMeans(QVector<double> plaquettesMeans);


    private:
        QVector<double> plaquettes;
        QVector<double> plaquettesMeans;
        QVector<double> plaquettesStdDevs;
};

#endif // SIMULATIONMEASUREMENTSIGNAL_H
