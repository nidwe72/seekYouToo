#include "su3simulation.h"

SU3Simulation::SU3Simulation(QObject *parent) : QObject(parent)
{
    simulationStarted=false;
}

SU3Simulation::~SU3Simulation(){
}


void SU3Simulation::start()
{
    simulationStarted=true;

    QVector<SimulationExecutionPlanEntry*> entries=*this->getExecutionPlan()->getEntries();


    for(SimulationExecutionPlanEntry* executionPlanEntry  : entries)
    {
        double beta=executionPlanEntry->getBeta();
        int totalCyclesCount = executionPlanEntry->totalCyclesCount;

        int thermalizationCyclesCount = executionPlanEntry->thermalizationCyclesCount;

        int lsz =executionPlan->getLatticeSize();

        QSharedPointer<SimulationProgressSignal> simulationProgressSignalBeta(new SimulationProgressSignal());
        simulationProgressSignalBeta->setType(SimulationProgressSignal::Type::Beta);
        simulationProgressSignalBeta->setMaximumValue(executionPlan->getEntries()->size());
        simulationProgressSignalBeta->setValue2(SimulationExecutionPlanUtil::getExecutionPlanEntryIndex(executionPlan,executionPlanEntry));
        simulationProgressSignalBeta->setValue(beta);
        simulationProgressSignalBeta->setExecutionPlanEntry(executionPlanEntry);
        emit on_SimulationProgressSignal(simulationProgressSignalBeta);

        QSharedPointer<Lattice> l(new Lattice(lsz, beta));

        l->reset(1.0, 0.0, 0.0, 0.0);
        l->calculate_neighbors();

        Wilson* wilson=new Wilson();


        QObject::connect(
            wilson,
            &Wilson::on_SimulationProgressSignal,
            this,
            &SU3Simulation::handleSimulationProgressSignal,Qt::QueuedConnection);


        for (int i = 0; i < totalCyclesCount; i++) {

            QSharedPointer<SimulationProgressSignal> simulationProgressSignalMeasurementLatticeSite(new SimulationProgressSignal());
            simulationProgressSignalMeasurementLatticeSite->setType(SimulationProgressSignal::Type::MeasurementLatticeSite);
            simulationProgressSignalMeasurementLatticeSite->setValue(0);
            simulationProgressSignalMeasurementLatticeSite->setMaximumValue(l->hypervolume*6);
            emit on_SimulationProgressSignal(simulationProgressSignalMeasurementLatticeSite);

            this->update(l);

            QSharedPointer<SimulationProgressSignal> simulationProgressSignalLatticeSweep(new SimulationProgressSignal());
            simulationProgressSignalLatticeSweep->setType(SimulationProgressSignal::Type::LatticeSweep);
            simulationProgressSignalLatticeSweep->setValue(i);
            simulationProgressSignalLatticeSweep->setMaximumValue(totalCyclesCount);
            emit on_SimulationProgressSignal(simulationProgressSignalLatticeSweep);

            if(i>=thermalizationCyclesCount){
                QVector<double> plaquettes;
                for (int wilsonLoopSize = 1; wilsonLoopSize <= 6; wilsonLoopSize++) {
                    double avr_wilson = wilson->average(l,wilsonLoopSize,wilsonLoopSize);
                    plaquettes.append(avr_wilson);
                }

                SimulationResult* simulationResult=this->getSimulationResult();
                SimulationBetaResult* betaResult = simulationResult->getBetaResult(beta);
                betaResult->plaquettes=plaquettes;

                QSharedPointer<SimulationMeasurementSignal> simulationMeasurementSignal(new SimulationMeasurementSignal());
                simulationMeasurementSignal->setPlaquettes(plaquettes);
                simulationMeasurementSignal->setPlaquettesMeans(plaquettes);
                simulationMeasurementSignal->setPlaquettesStdDevs(plaquettes);
                emit on_SimulationMeasurementSignal(simulationMeasurementSignal);

            }


            emit on_SimulationProgressSignal(simulationProgressSignalMeasurementLatticeSite);

            //qDebug() << "avr_wilson: " <<plaquettes;

        }

        QSharedPointer<SimulationProgressSignal> simulationProgressSignal(new SimulationProgressSignal());
        simulationProgressSignal->setType(SimulationProgressSignal::Type::LatticeSweep);
        simulationProgressSignal->setValue(totalCyclesCount);
        simulationProgressSignal->setMaximumValue(totalCyclesCount);
        emit on_SimulationProgressSignal(simulationProgressSignal);


        simulationProgressSignalBeta->setValue2(executionPlan->getEntries()->size());
        simulationProgressSignalBeta->setValue(beta);
        simulationProgressSignalBeta->setExecutionPlanEntry(executionPlanEntry);
        emit on_SimulationProgressSignal(simulationProgressSignalBeta);

    }




}


void SU3Simulation::stop()
{
    simulationStarted=false;
}

void SU3Simulation::updateLink(QSharedPointer<Lattice> lattice,int id, int mu) {


    //qDebug() << "running...";


    double x;
    double a;
    double sq;

    SuN staple = Staples::staples(lattice.data(),id, mu);

    double k = sqrt(SuN::determinant(staple));

    // Normalize staple
    staple.setValue(0,(staple.getValue(0)/k));
    staple.setValue(1,(staple.getValue(1)/k));
    staple.setValue(2,(staple.getValue(2)/k));
    staple.setValue(3,(staple.getValue(3)/k));

    double rn=0.0;
    while (true) {

        x=Random::randx(exp(-2.0 * lattice->beta * k));
        a = 1 + log(x) / (lattice->beta * k);
        sq = sqrt(1 - a * a);
        rn=Random::ranlxd();
        //qDebug() << "rn: " <<rn;
        if (rn < sq) {
            break;
        }
    }

    //qDebug() << "running3...";

    double theta = M_PI * 2.0 * Random::ranlxd();
    double phi = M_PI * Random::ranlxd();

    SuN g;
    g.setValue(0,a);
    g.setValue(1,sq * cos(theta) * sin(phi));
    g.setValue(2,sq * sin(theta) * sin(phi));
    g.setValue(3,sq * cos(phi));

    g*=SuN::dagger(staple);
    lattice->setSiteLink(id, mu,new SuN(g));
}

void SU3Simulation::updateSubset(QSharedPointer<Lattice> lattice,LatticeSubset* latticeSubset) {

    int from = latticeSubset->getFrom();
    int to = latticeSubset->getTo();

    int index=1;

    int previousProgress=0;
    int progress=0;

    for (int id = from; id < to; id++) {
        index++;
        for (int mu = 0; mu < 4; mu++) {
            this->updateLink(lattice,id, mu);
        }
        progress=(int)(index/((double)lattice->hypervolume)*100.0);
        if(previousProgress<progress){
            previousProgress=progress;
            QSharedPointer<SimulationProgressSignal> simulationSignal(new SimulationProgressSignal());
            simulationSignal->setType(SimulationProgressSignal::Type::LatticeSite);
            simulationSignal->setValue(progress);
            emit on_SimulationProgressSignal(simulationSignal);
        }

    }

}

SimulationResult *SU3Simulation::getSimulationResult()
{
    if(this->simulationResult==nullptr){
        this->simulationResult=new SimulationResult();
    }
    return this->simulationResult;
}

void SU3Simulation::update(QSharedPointer<Lattice> lattice) {
    LatticeSubset* latticeSubset = new LatticeSubset(0,lattice->hypervolume);
    this->updateSubset(lattice,latticeSubset);
}

void SU3Simulation::setExecutionPlan(SimulationExecutionPlan* simulationExecutionPlan)
{
    this->executionPlan=simulationExecutionPlan;
}

SimulationExecutionPlan *SU3Simulation::getExecutionPlan()
{
    return this->executionPlan;
}

void SU3Simulation::handleSimulationProgressSignal(QSharedPointer<SimulationProgressSignal>simulationProgressSignal)
{
    emit on_SimulationProgressSignal(simulationProgressSignal);
}


