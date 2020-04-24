#ifndef STATISTICUTIL_H
#define STATISTICUTIL_H

#include <QVector>

#include <cmath>

class StatisticUtil
{
public:
    StatisticUtil();
    static double getArithmeticMean(QVector<double> values);
    static double getStandardDeviation(QVector<double> values);
};

#endif // STATISTICUTIL_H
