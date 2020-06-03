#include "simulationprogresswidget.h"

SimulationProgressWidget::SimulationProgressWidget(QWidget *parent) : DefaultPanel(parent)
{

}

QWidget *SimulationProgressWidget::getContentWidget()
{

    QWidget *result=new QWidget();

    QGridLayout* layout=new QGridLayout();
    layout->setContentsMargins(0,0,0,0);
    result->setLayout(layout);

    DefaultPanel* defaultPanelProgressLatticeSite=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    this->progressCircleLatticeSite=new ProgressCircle();    
    this->progressCircleLatticeSite->setMaximum(100);
    this->progressCircleLatticeSite->setColor(QColor(Qt::green));        
    defaultPanelProgressLatticeSite->getHeaderLabel()->setText(QString("<center>sweep</center>"));
    defaultPanelProgressLatticeSite->setContentWidget(this->progressCircleLatticeSite);
    defaultPanelProgressLatticeSite->init();
    layout->addWidget(defaultPanelProgressLatticeSite,0,0);

    DefaultPanel* defaultPanelProgressMeasure=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    this->progressCircleLatticeMeasure=new ProgressCircle();
    this->progressCircleLatticeMeasure->setMaximum(100);
    this->progressCircleLatticeMeasure->setColor(QColor(Qt::green));
    defaultPanelProgressMeasure->getHeaderLabel()->setText(QString("<center>measure</center>"));
    defaultPanelProgressMeasure->setContentWidget(this->progressCircleLatticeMeasure);
    defaultPanelProgressMeasure->init();
    layout->addWidget(defaultPanelProgressMeasure,0,1);

    DefaultPanel* defaultPanelProgressLatticeSweep=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    this->progressCircleLatticeSweep=new ProgressCircle();    
    this->progressCircleLatticeSweep->setMaximum(100);
    this->progressCircleLatticeSweep->setColor(QColor(Qt::green));
    defaultPanelProgressLatticeSweep->getHeaderLabel()->setText(QString("<center>cycles</center>"));
    defaultPanelProgressLatticeSweep->setContentWidget(this->progressCircleLatticeSweep);
    defaultPanelProgressLatticeSweep->init();
    layout->addWidget(defaultPanelProgressLatticeSweep,0,2);

    layout->addWidget(new ProgressCircle,0,3);
    DefaultPanel* defaultPanelProgressTotal=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    defaultPanelProgressTotal->getHeaderLabel()->setText(QString("<center>betas</center>"));
    this->progressCircleBeta=new ProgressCircle();
    this->progressCircleBeta->setMaximum(6);
    this->progressCircleBeta->setColor(QColor(Qt::green));
    defaultPanelProgressTotal->setContentWidget(this->progressCircleBeta);
    defaultPanelProgressTotal->init();
    layout->addWidget(defaultPanelProgressTotal,0,3);

    return result;
}

DefaultPanel::Orientation SimulationProgressWidget::getOrientation()
{
    return DefaultPanel::Orientation::Landscape;
}

SimulationProgressWidget *SimulationProgressWidget::createInstance()
{
    SimulationProgressWidget* result=new SimulationProgressWidget();
    return  result;
}


QLabel* SimulationProgressWidget::getHeaderLabel(){
    this->headerLabel=DefaultPanel::getHeaderLabel();
    this->headerLabel->setText(QString("progress"));
    return this->headerLabel;
}
