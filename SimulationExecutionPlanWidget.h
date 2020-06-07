#ifndef SIMULATIONEXECUTIONPLANWIDGET_H
#define SIMULATIONEXECUTIONPLANWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLCDNumber>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QCategoryAxis>
#include "SimulationExecutionPlan.h"
#include "SimulationExecutionPlanEntry.h"
#include "SimulationExecutionPlanUtil.h"

#include "VerticalLabel.h"
#include "DefaultPanel.h"

#include <QStyleOption>

#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QGraphicsTextItem>

#include <QBarSeries>
#include <QBarSet>

using namespace QtCharts;

class SimulationExecutionPlanWidget : public DefaultPanel

{
    Q_OBJECT
public:    
    explicit SimulationExecutionPlanWidget(QWidget *parent = nullptr);
    SimulationExecutionPlan* getExecutionPlan();
    void setExecutionPlan(SimulationExecutionPlan* simulationExecutionPlan);
    void update(SimulationExecutionPlanEntry* simulationExecutionPlanEntry);
    QCategoryAxis* getXAxis();
    QCategoryAxis* getYAxis();
    QWidget* getContentWidget() override;
    Orientation getOrientation() override;

    static SimulationExecutionPlanWidget* createInstance();


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    SimulationExecutionPlan* executionPlan;
    QLCDNumber* betaLcdNumber=nullptr;
    QLCDNumber* getBetaLcdNumber();
    QCategoryAxis* xAxis=nullptr;
    QCategoryAxis* yAxis=nullptr;
    QChartView* chartView=nullptr;
    QChartView* getChartView();

    QLCDNumber* totalCountLcdNumber=nullptr;
    QLCDNumber* getTotalCountLcdNumber();

    QLCDNumber* thermalizationCountLcdNumber=nullptr;
    QLCDNumber* getThermalizationCountLcdNumber();

    QLCDNumber* latticeSizeLcdNumber=nullptr;
    QLCDNumber* getLatticeSizeLcdNumberLcdNumber();




signals:

};

#endif // SIMULATIONEXECUTIONPLANWIDGET_H
