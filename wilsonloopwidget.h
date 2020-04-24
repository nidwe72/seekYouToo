#ifndef WILSONLOOPWIDGET_H
#define WILSONLOOPWIDGET_H

#include <QWidget>
#include <QLCDNumber>
#include <QGridLayout>

class WilsonLoopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WilsonLoopWidget(QWidget *parent = nullptr);
    void updatePlaquetteLcdNumber(double value);
    void updatePlaquetteMeanLcdNumber(double value);
    void updateplaquetteStdDevLcdNumber(double value);
private:
    QLCDNumber* plaquetteLcdNumber;
    QLCDNumber* plaquetteMeanLcdNumber;
    QLCDNumber* plaquetteStdDevLcdNumber;

signals:

};

#endif // WILSONLOOPWIDGET_H
