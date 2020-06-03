#ifndef SIMULATIONPROGRESSWIDGET_H
#define SIMULATIONPROGRESSWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "progresscircle.h"
#include "DefaultPanel.h"

class SimulationProgressWidget : public DefaultPanel
{
    Q_OBJECT
public:
    explicit SimulationProgressWidget(QWidget *parent = nullptr);
    ProgressCircle* progressCircleLatticeSite;    
    ProgressCircle* progressCircleLatticeMeasure;
    ProgressCircle* progressCircleLatticeSweep;
    ProgressCircle* progressCircleBeta;

    QWidget* getContentWidget() override;
    DefaultPanel::Orientation getOrientation() override;

    static SimulationProgressWidget* createInstance();
    QLabel *getHeaderLabel() override;
signals:

};

#endif // SIMULATIONPROGRESSWIDGET_H
