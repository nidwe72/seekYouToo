#include "SimulationWidget.h"

SimulationWidget::SimulationWidget(QWidget *parent) : QWidget(parent)
{    
    for (int i=0;i<6;i++) {
        this->wilsonLoopWidgets.append(new WilsonLoopWidget(this));
    }

    QGridLayout* layout=new QGridLayout();
    this->setLayout(layout);

    this->executionPlanWidget= SimulationExecutionPlanWidget::createInstance();
    this->executionPlanWidget->getHeaderLabel()->setText(QString("execution plan"));
    this->executionPlanWidget->init();
    layout->addWidget(this->executionPlanWidget,0,0);

    this->simulationProgressWidget=SimulationProgressWidget::createInstance();
    this->simulationProgressWidget->init();
    layout->addWidget(this->simulationProgressWidget,1,0);

    layout->addWidget(this->createWilsonLoopsContainerWidget(),2,0);

}

void SimulationWidget::handleSimulationProgressSignal(SimulationProgressSignal* simulationProgressSignal)
{
    double value=simulationProgressSignal->getValue();
    SimulationProgressSignal::Type simulationSignalType=simulationProgressSignal->getType();

    switch (simulationSignalType) {
        case SimulationProgressSignal::Type::LatticeSite:
            this->simulationProgressWidget->progressCircleLatticeSite->setValue(value);
            break;
        case SimulationProgressSignal::Type::LatticeSweep:
            this->simulationProgressWidget->progressCircleLatticeSweep->setValue(value);
            this->simulationProgressWidget->progressCircleLatticeSweep->setMaximum(simulationProgressSignal->getMaximumValue());
            break;
        case SimulationProgressSignal::Type::Beta:
            this->executionPlanWidget->update(simulationProgressSignal->getExecutionPlanEntry());
            this->simulationProgressWidget->progressCircleBeta->setMaximum(simulationProgressSignal->getMaximumValue());
            this->simulationProgressWidget->progressCircleBeta->setValue(simulationProgressSignal->getValue2());
            break;
        case SimulationProgressSignal::Type::MeasurementLatticeSite:
            this->simulationProgressWidget->progressCircleLatticeMeasure->setValue(simulationProgressSignal->getValue());
            this->simulationProgressWidget->progressCircleLatticeMeasure->setMaximum(simulationProgressSignal->getMaximumValue()                                                                                     );
            break;
    }

}

void SimulationWidget::handleSimulationMeasurementSignal(SimulationMeasurementSignal *simulationMeasurementSignal)
{
    QVector<double> plaquettes=simulationMeasurementSignal->getPlaquettes();
    QVector<double> plaquettesStdDevs=simulationMeasurementSignal->getPlaquettesStdDevs();
    QVector<double> plaquettesMeans=simulationMeasurementSignal->getPlaquettesMeans();

    for (int i=0;i<6;i++) {
        (this->wilsonLoopWidgets)[i]->updatePlaquetteMeanLcdNumber(plaquettesMeans[i]);
        (this->wilsonLoopWidgets)[i]->updateplaquetteStdDevLcdNumber(plaquettesStdDevs[i]);
        (this->wilsonLoopWidgets)[i]->updatePlaquetteLcdNumber(plaquettes[i]);
    }
}

void SimulationWidget::setExecutionPlan(SimulationExecutionPlan *simulationExecutionPlan)
{
    this->executionPlan=simulationExecutionPlan;
    this->executionPlanWidget->setExecutionPlan(this->executionPlan);
}

SimulationExecutionPlan *SimulationWidget::getExecutionPlan()
{
    return this->executionPlan;
}

QWidget *SimulationWidget::createWilsonLoopsContainerWidget()
{

    DefaultPanel* resultPanel=DefaultPanel::createInstance();
    resultPanel->setOrientation(DefaultPanel::Orientation::Landscape);
    resultPanel->getHeaderLabel()->setText(QString("Wilson loops"));


    QFont font;
    font.setPixelSize(11);

    QWidget* result=new QWidget();

    QGridLayout* layout=new QGridLayout();
    layout->setContentsMargins(0,0,0,0);
    result->setLayout(layout);

    QLabel* labelWilsonSize = new QLabel();
    labelWilsonSize->setStyleSheet("QLabel { background-color : #282828; color : #76EE00; }");
    labelWilsonSize->setTextFormat(Qt::RichText);
    labelWilsonSize->setText("<center>size(w)</center>");
    labelWilsonSize->setFont(font);
    labelWilsonSize->setFixedHeight(20);
    layout->addWidget(labelWilsonSize,0,0);

    QLabel* labelWilsonMean = new QLabel();
    labelWilsonMean->setStyleSheet("QLabel { background-color : #282828; color : #76EE00; }");
    labelWilsonMean->setTextFormat(Qt::RichText);
    labelWilsonMean->setText("<center>tot_avg(w)</center>");
    labelWilsonMean->setFont(font);
    labelWilsonMean->setFixedHeight(20);
    layout->addWidget(labelWilsonMean,0,1);

    QLabel* labelWilsonStdDev = new QLabel();
    labelWilsonStdDev->setStyleSheet("QLabel { background-color : #282828; color : #76EE00; }");
    labelWilsonStdDev->setTextFormat(Qt::RichText);
    labelWilsonStdDev->setText("<center>std_dev(avg(w))</center>");
    labelWilsonStdDev->setFont(font);
    labelWilsonStdDev->setFixedHeight(20);
    layout->addWidget(labelWilsonStdDev,0,2);

    QLabel* labelWilson= new QLabel();
    labelWilson->setStyleSheet("QLabel { background-color : #282828; color : #76EE00; }");
    labelWilson->setTextFormat(Qt::RichText);
    labelWilson->setText("<center>avg(w)</center>");
    labelWilson->setFont(font);
    labelWilson->setFixedHeight(20);
    layout->addWidget(labelWilson,0,3);


    for (int i=0;i<6;i++) {

        QLabel* labelWilsonSizeValue= new QLabel();
        labelWilsonSizeValue->setStyleSheet("QLabel { background-color : black; color : #76EE00; }");
        labelWilsonSizeValue->setTextFormat(Qt::RichText);

        QString wilsonSizeValue("");
        wilsonSizeValue+=QString("<center>");
        wilsonSizeValue+=QString::number(i+1);
        wilsonSizeValue+=QString("x");
        wilsonSizeValue+=QString::number(i+1);
        wilsonSizeValue+=QString("</center>");
        labelWilsonSizeValue->setText(wilsonSizeValue);

        labelWilsonSizeValue->setFont(font);
        layout->addWidget(labelWilsonSizeValue,i+1,0,1,1);

        layout->addWidget(this->wilsonLoopWidgets[i],i+1,1,1,3);
    }

    resultPanel->setContentWidget(result);
    resultPanel->init();

    return resultPanel;

}
