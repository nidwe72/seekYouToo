#include "statisticutil.h"

StatisticUtil::StatisticUtil()
{

}

double StatisticUtil::getArithmeticMean(QVector<double> values)
{
    double result=0;
    for(double value:values){
        result+=value;
    }
    result/=(double)values.length();
    return result;
}

double StatisticUtil::getStandardDeviation(QVector<double> values)
{
    double result=0;
    double w=0;
    double wsq=0;

    for(double value:values){
        w+=value;
        wsq += value*value;
    }

    int n=values.length();
    result=std::sqrt(wsq/n-(w/n)*(w/n));

    return result;
}
