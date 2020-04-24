#ifndef WILSONLOOPBYBETACHART_H
#define WILSONLOOPBYBETACHART_H

#include <QObject>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>
#include <QPointF>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QLegendMarker>

#include<cmath>

using namespace QtCharts;

class WilsonLoopByBetaChart : public QChartView
{
    Q_OBJECT
public:
    explicit WilsonLoopByBetaChart();
    void addSeries(QAbstractSeries *series);

private:
    QCategoryAxis* xAxis=nullptr;
    QCategoryAxis* yAxis=nullptr;

    QScatterSeries* getSeries1x1();
    QScatterSeries* getSeries2x2();
    QScatterSeries* getSeries3x3();
    QScatterSeries* getSeries4x4();
    QScatterSeries* getSeries5x5();
    QScatterSeries* getSeries6x6();

    QLineSeries* getSeriesStrongCouplingLimit();
    QLineSeries* getSeriesStrongCouplingLimit2x2();
    QLineSeries* getSeriesWeakCouplingLimit();


    QCategoryAxis* getXAxis();
    QCategoryAxis* getYAxis();

signals:

};

#endif // WILSONLOOPBYBETACHART_H
