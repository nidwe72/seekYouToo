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

    DefaultPanel* defaultPanelProgressBeta=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    defaultPanelProgressBeta->getHeaderLabel()->setText(QString("<center>measure</center>"));
    defaultPanelProgressBeta->setContentWidget(new ProgressCircle);
    defaultPanelProgressBeta->init();
    layout->addWidget(defaultPanelProgressBeta,0,1);

    DefaultPanel* defaultPanelProgressLatticeSweep=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    this->progressCircleLatticeSweep=new ProgressCircle();
    this->progressCircleLatticeSweep->setMaximum(100);
    this->progressCircleLatticeSweep->setColor(QColor(Qt::green));
    defaultPanelProgressLatticeSweep->getHeaderLabel()->setText(QString("<center>cycles</center>"));
    defaultPanelProgressLatticeSweep->setContentWidget(progressCircleLatticeSweep);
    defaultPanelProgressLatticeSweep->init();
    layout->addWidget(defaultPanelProgressLatticeSweep,0,2);

    layout->addWidget(new ProgressCircle,0,3);
    DefaultPanel* defaultPanelProgressTotal=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    defaultPanelProgressTotal->getHeaderLabel()->setText(QString("<center>betas</center>"));
    defaultPanelProgressTotal->setContentWidget(new ProgressCircle);
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
