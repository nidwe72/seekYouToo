#include "simulationmeasurementsignal.h"

SimulationMeasurementSignal::SimulationMeasurementSignal()
{

}

QVector<double> SimulationMeasurementSignal::getPlaquettes()
{
    return this->plaquettes;
}

void SimulationMeasurementSignal::setPlaquettes(QVector<double> plaquettes)
{
    this->plaquettes=plaquettes;
}

QVector<double> SimulationMeasurementSignal::getPlaquettesStdDevs()
{
    return this->plaquettesStdDevs;
}

void SimulationMeasurementSignal::setPlaquettesStdDevs(QVector<double> plaquettesStdDevs)
{
    this->plaquettesStdDevs=plaquettesStdDevs;
}

QVector<double> SimulationMeasurementSignal::getPlaquettesMeans()
{
    return this->plaquettesMeans;
}

void SimulationMeasurementSignal::setPlaquettesMeans(QVector<double> plaquettesMeans)
{
    this->plaquettesMeans=plaquettesMeans;
}
