#include "wilsonloopwidget.h"

WilsonLoopWidget::WilsonLoopWidget(QWidget *parent) : QWidget(parent)
{    
    QGridLayout* layout=new QGridLayout();
    layout->setContentsMargins(0,0,0,0);

    this->setLayout(layout);

    this->setStyleSheet("QWidget { padding: 0px;}");


    this->plaquetteMeanLcdNumber=new QLCDNumber(this);
    this->plaquetteMeanLcdNumber->setStyleSheet("QLCDNumber { background-color : black; color : #76EE00; }");
    this->plaquetteMeanLcdNumber->setDigitCount(8);
    this->plaquetteMeanLcdNumber->setSegmentStyle(QLCDNumber::Flat);
    layout->addWidget(this->plaquetteMeanLcdNumber,0,0);

    this->plaquetteStdDevLcdNumber=new QLCDNumber(this);
    this->plaquetteStdDevLcdNumber->setStyleSheet("QLCDNumber { background-color : black; color : #76EE00; }");
    this->plaquetteStdDevLcdNumber->setDigitCount(8);
    this->plaquetteStdDevLcdNumber->setSegmentStyle(QLCDNumber::Flat);
    layout->addWidget(this->plaquetteStdDevLcdNumber,0,1);

    this->plaquetteLcdNumber=new QLCDNumber(this);
    this->plaquetteLcdNumber->setStyleSheet("QLCDNumber { background-color : black; color : #76EE00; }");
    this->plaquetteLcdNumber->setDigitCount(8);
    this->plaquetteLcdNumber->setSegmentStyle(QLCDNumber::Flat);
    layout->addWidget(this->plaquetteLcdNumber,0,2);

}

void WilsonLoopWidget::updatePlaquetteLcdNumber(double value)
{
    double rounded = (int)(value * 10000000.0)/10000000.0;
    this->plaquetteLcdNumber->display(rounded);
}

void WilsonLoopWidget::updatePlaquetteMeanLcdNumber(double value)
{
    double rounded = (int)(value * 10000000.0)/10000000.0;
    this->plaquetteMeanLcdNumber->display(rounded);
}

void WilsonLoopWidget::updateplaquetteStdDevLcdNumber(double value)
{
    double rounded = (int)(value * 10000000.0)/10000000.0;
    this->plaquetteStdDevLcdNumber->display(rounded);
}
