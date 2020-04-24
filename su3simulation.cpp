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
        int nth = executionPlanEntry->totalCyclesCount;
        int lsz = 8; // Lattice size

        SimulationProgressSignal* simulationProgressSignalBeta=new SimulationProgressSignal();
        simulationProgressSignalBeta->setType(SimulationProgressSignal::Type::Beta);
        simulationProgressSignalBeta->setValue(beta);
        simulationProgressSignalBeta->setExecutionPlanEntry(executionPlanEntry);
        emit on_SimulationProgressSignal(simulationProgressSignalBeta);

        Lattice* l = new Lattice(lsz, beta);
        l->reset(1.0, 0.0, 0.0, 0.0);
        l->calculate_neighbors();

        for (int i = 0; i < nth; i++) {

            this->update(l);

            QVector<double> plaquettes;
            for (int wilsonLoopSize = 1; wilsonLoopSize <= 6; wilsonLoopSize++) {
                double avr_wilson = Wilson::average(l,wilsonLoopSize,wilsonLoopSize);
                plaquettes.append(avr_wilson);
            }

            qDebug() << "avr_wilson: " <<plaquettes;


            SimulationResult* simulationResult=this->getSimulationResult();
            SimulationBetaResult* betaResult = simulationResult->getBetaResult(beta);
            betaResult->plaquettes=plaquettes;

            SimulationMeasurementSignal* simulationMeasurementSignal=new SimulationMeasurementSignal();
            simulationMeasurementSignal->setPlaquettes(plaquettes);
            simulationMeasurementSignal->setPlaquettesMeans(plaquettes);
            simulationMeasurementSignal->setPlaquettesStdDevs(plaquettes);

            emit on_SimulationMeasurementSignal(simulationMeasurementSignal);

            //QThread::currentThread()->msleep(100);

            SimulationProgressSignal* simulationProgressSignal=new SimulationProgressSignal();
            simulationProgressSignal->setType(SimulationProgressSignal::Type::LatticeSweep);
            double lsp=((double)(i+1))/((double)nth)*100.0;
            simulationProgressSignal->setValue(lsp);
            emit on_SimulationProgressSignal(simulationProgressSignal);


        }


        //qDebug() << iter.key() << " : " << iter.value();
    }


}


void SU3Simulation::stop()
{
    simulationStarted=false;
}

void SU3Simulation::updateLink(Lattice* lattice,int id, int mu) {


    //qDebug() << "running...";


    double x;
    double a;
    double sq;

    SuN staple = Staples::staples(lattice,id, mu);

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

void SU3Simulation::updateSubset(Lattice* lattice,LatticeSubset* latticeSubset) {

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
            SimulationProgressSignal* simulationSignal=new SimulationProgressSignal();
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

void SU3Simulation::update(Lattice* lattice) {
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


