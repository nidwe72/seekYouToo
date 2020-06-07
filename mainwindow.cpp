#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow.h"

#include "DocumentationWidget.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    setGeometry(0,0,400,600);

    QWidget* window=new QWidget;
    window->setStyleSheet("QWidget { background-color : #001a00; color : #76EE00; }");

    QGridLayout* layout=new QGridLayout;
    window->setLayout(layout);

    lineEdit=new QLineEdit;




    SimulationExecutionPlan* executionPlan = SimulationExecutionPlanUtil::createFastExecutionPlan();

    SimulationWidget* simulationWidget=new SimulationWidget(this);
    layout->addWidget(simulationWidget,3,0,2,2);
    simulationWidget->setExecutionPlan(executionPlan);

    window->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QTabWidget* mainWidget=new QTabWidget();
    mainWidget->setStyleSheet("QTabWidget { background-color : #001a00; color : #76EE00; }");


    mainWidget->addTab(window,QString("Simulation"));

    WilsonLoopByBetaChart* wilsonLoopByBetaChart = new WilsonLoopByBetaChart();

    mainWidget->addTab(wilsonLoopByBetaChart ,QString("Results"));

    setCentralWidget(mainWidget);
    setStyleSheet("QWidget { background-color : #001a00; color : #76EE00; }");

    su3Simulation=new SU3Simulation(this);
    su3Simulation->setExecutionPlan(executionPlan);

    QObject::connect(
        su3Simulation,
        &SU3Simulation::on_SimulationProgressSignal,
        simulationWidget,
        &SimulationWidget::handleSimulationProgressSignal,Qt::QueuedConnection);

    QObject::connect(
        su3Simulation,
        &SU3Simulation::on_SimulationMeasurementSignal,
        simulationWidget,
        &SimulationWidget::handleSimulationMeasurementSignal,Qt::QueuedConnection);

    DocumentationWidget* documentationWidget=new DocumentationWidget(window);
    mainWidget->addTab(documentationWidget,QString("Documentation"));

    mainWidget->setCurrentIndex(2);

    simulationFuture=QtConcurrent::run(this->su3Simulation,&SU3Simulation::start);


}

MainWindow::~MainWindow()
{

}




