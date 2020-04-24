#include "SimulationExecutionPlanWidget.h"

SimulationExecutionPlanWidget::SimulationExecutionPlanWidget(QWidget *parent) : DefaultPanel(parent)
{
    this->setFixedHeight(128);
    //this->setStyleSheet("SimulationExecutionPlanWidget {background-color : #001a00; color : #76EE00; border-width: 2px; border-style: solid;border-color: black;}");

}

SimulationExecutionPlan *SimulationExecutionPlanWidget::getExecutionPlan()
{
    return this->executionPlan;
}

void SimulationExecutionPlanWidget::setExecutionPlan(SimulationExecutionPlan *executionPlan)
{
    this->executionPlan=executionPlan;
}

void SimulationExecutionPlanWidget::update(SimulationExecutionPlanEntry *simulationExecutionPlanEntry)
{
    this->betaLcdNumber->display(simulationExecutionPlanEntry->getBeta());

    QCategoryAxis *yAxis = this->getYAxis();

    SimulationExecutionPlan *executionPlan = this->getExecutionPlan();
    QPair<int, int> *executionPlanRange = SimulationExecutionPlanUtil::getExecutionPlanRange(executionPlan);
    yAxis->setRange(executionPlanRange->first, executionPlanRange->second);

    for (int i=executionPlanRange->first;i<=executionPlanRange->second;i++) {
        yAxis->append(QString::number(i),i);
    }

}

QCategoryAxis *SimulationExecutionPlanWidget::getXAxis()
{
    if(this->xAxis==nullptr){
        this->xAxis=new QCategoryAxis(this);

        QPen axisPen(Qt::green);
        axisPen.setWidth(2);
        this->xAxis->setLinePen(axisPen);
        QFont font;
        font.setPixelSize(10);
        this->xAxis->setLabelsFont(font);
        QBrush axisBrush(Qt::green);
        this->xAxis->setLabelsBrush(axisBrush);
        this->xAxis->setTitleBrush(axisBrush);

    }
    return this->xAxis;
}

QCategoryAxis *SimulationExecutionPlanWidget::getYAxis()
{
    if(this->yAxis==nullptr){
        this->yAxis=new QCategoryAxis(this);

        QPen axisPen(Qt::green);
        axisPen.setWidth(2);
        this->yAxis->setLinePen(axisPen);
        QFont font;
        font.setPixelSize(6);
        this->yAxis->setLabelsFont(font);
        QBrush axisBrush(Qt::green);
        this->yAxis->setLabelsBrush(axisBrush);
        this->yAxis->setTitleBrush(axisBrush);

    }
    return this->yAxis;
}

QLCDNumber *SimulationExecutionPlanWidget::getBetaLcdNumber()
{
    if(this->betaLcdNumber==nullptr){
        this->betaLcdNumber=new QLCDNumber();
        this->betaLcdNumber->setStyleSheet("QLCDNumber { background-color : black; color : #76EE00; }");
        this->betaLcdNumber->setSegmentStyle(QLCDNumber::Flat);

        this->betaLcdNumber->display(2.1);
        this->betaLcdNumber->setDigitCount(3);        
        this->betaLcdNumber->setFixedWidth(110);
    }
    return this->betaLcdNumber;
}

QChartView *SimulationExecutionPlanWidget::getChartView()
{

    if(this->chartView==nullptr){
        this->chartView=new QChartView();
        this->chartView->setStyleSheet("background-color:black:");
        this->chartView->setContentsMargins(0,0,0,0);
        this->chartView->setBackgroundBrush(Qt::black);

        QChart* chart=new QChart();
        chart->setBackgroundBrush(Qt::black);
        chart->setBackgroundRoundness(0);
        chart->setMargins(QMargins(0,0,0,0));
        chart->setContentsMargins(0,0,0,0);

        this->chartView->setChart(chart);
        chart->addAxis(this->getXAxis(),Qt::AlignBottom);
        chart->addAxis(this->getYAxis(),Qt::AlignLeft);

        this->chartView->setRenderHint(QPainter::Antialiasing);
        this->chartView->setStyleSheet("QChartView { background-color : #ff0000; color : #76EE00; }");
    }

    return this->chartView;

}

void SimulationExecutionPlanWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QWidget* SimulationExecutionPlanWidget::getContentWidget(){


    this->contentWidget=new QWidget();

    QGridLayout *layout=new QGridLayout();
    layout->setContentsMargins(0,0,0,0);
    this->contentWidget->setLayout(layout);

    DefaultPanel* beta=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    beta->getHeaderLabel()->setText(QString("<center>beta</center>"));
    beta->setContentWidget(this->getBetaLcdNumber());
    beta->init();
    layout->addWidget(beta,0,0);


    DefaultPanel* chartPanel=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    chartPanel->setContentWidget(this->getChartView());
    chartPanel->getHeaderLabel()->setText(QString("<center>beta values</center>"));
    chartPanel->init();
    layout->addWidget(chartPanel,0,1);

    return this->contentWidget;

}

DefaultPanel::Orientation SimulationExecutionPlanWidget::getOrientation()
{
    return DefaultPanel::Orientation::Landscape;
}

SimulationExecutionPlanWidget *SimulationExecutionPlanWidget::createInstance()
{
    SimulationExecutionPlanWidget* result=new SimulationExecutionPlanWidget();
    return result;
}



