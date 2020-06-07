#include "SimulationExecutionPlanWidget.h"

SimulationExecutionPlanWidget::SimulationExecutionPlanWidget(QWidget *parent) : DefaultPanel(parent)
{
    //this->setFixedHeight(128);
    this->setFixedHeight(200);
    //this->setStyleSheet("SimulationExecutionPlanWidget {background-color : #001a00; color : #76EE00; border-width: 2px; border-style: solid;border-color: black;}");

}

SimulationExecutionPlan *SimulationExecutionPlanWidget::getExecutionPlan()
{
    return this->executionPlan;
}

void SimulationExecutionPlanWidget::setExecutionPlan(SimulationExecutionPlan *executionPlan)
{
    this->executionPlan=executionPlan;    
    this->getTotalCountLcdNumber()->display(executionPlan->getEntries()->first()->totalCyclesCount);
    this->getThermalizationCountLcdNumber()->display(executionPlan->getEntries()->first()->thermalizationCyclesCount);
    this->getLatticeSizeLcdNumberLcdNumber()->display(executionPlan->getLatticeSize());
}

void SimulationExecutionPlanWidget::update(SimulationExecutionPlanEntry *simulationExecutionPlanEntry)
{
    double beta=simulationExecutionPlanEntry->getBeta();
    this->betaLcdNumber->display(beta);

    QCategoryAxis *yAxis = this->getYAxis();

    SimulationExecutionPlan *executionPlan = this->getExecutionPlan();
    QPair<int, int> *executionPlanRange = SimulationExecutionPlanUtil::getExecutionPlanRange(executionPlan);
    yAxis->setRange(executionPlanRange->first, executionPlanRange->second);

    for (int i=executionPlanRange->first;i<=executionPlanRange->second;i++) {
        yAxis->append(QString::number(i),i);
    }

    QChart* chart=this->getChartView()->chart();


    if(chart->series().empty()){

        QBarSeries* series=new QBarSeries();
        QBarSet* barSet=new QBarSet("");

        for (SimulationExecutionPlanEntry* executionPlanEntry :*executionPlan->getEntries()) {
            barSet->append(executionPlanEntry->getBeta());
        }

        series->append(barSet);
        chart->addSeries(series);
        chart->legend()->hide();
    }


    QList<QGraphicsRectItem *> rect_items;
    for(QGraphicsItem * it : this->getChartView()->items()){
        if(QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(it)){
            if(rect->parentItem() != chart && rect->parentItem()->parentItem() == chart){
                rect_items << rect;
            }
        }
    }

    int executionPlanEntryIndex=SimulationExecutionPlanUtil::getExecutionPlanEntryIndex(executionPlan,simulationExecutionPlanEntry);

    for(QGraphicsRectItem * rect : rect_items){
        rect->setBrush(QColor(QString("#009933")));
    }

    int rectIndexSelected=+executionPlan->getEntries()->size()-executionPlanEntryIndex-1;
    rect_items.at(rectIndexSelected)->setBrush(QColor(QString("#76EE00")));




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


        this->betaLcdNumber->setDigitCount(3);        
        this->betaLcdNumber->setFixedWidth(120);
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

QLCDNumber *SimulationExecutionPlanWidget::getTotalCountLcdNumber()
{

    if(this->totalCountLcdNumber==nullptr){
        this->totalCountLcdNumber=new QLCDNumber();
        this->totalCountLcdNumber->setStyleSheet("QLCDNumber { background-color : black; color : #76EE00; }");
        this->totalCountLcdNumber->setSegmentStyle(QLCDNumber::Flat);
        this->totalCountLcdNumber->setDigitCount(2);
        this->totalCountLcdNumber->setFixedWidth(80);
    }
    return this->totalCountLcdNumber;
}

QLCDNumber *SimulationExecutionPlanWidget::getThermalizationCountLcdNumber()
{
    if(this->thermalizationCountLcdNumber==nullptr){
        this->thermalizationCountLcdNumber=new QLCDNumber();
        this->thermalizationCountLcdNumber->setStyleSheet("QLCDNumber { background-color : black; color : #76EE00; }");
        this->thermalizationCountLcdNumber->setSegmentStyle(QLCDNumber::Flat);
        this->thermalizationCountLcdNumber->setDigitCount(2);
        this->thermalizationCountLcdNumber->setFixedWidth(80);
    }
    return this->thermalizationCountLcdNumber;

}

QLCDNumber *SimulationExecutionPlanWidget::getLatticeSizeLcdNumberLcdNumber()
{
    if(this->latticeSizeLcdNumber==nullptr){
        this->latticeSizeLcdNumber=new QLCDNumber();
        this->latticeSizeLcdNumber->setStyleSheet("QLCDNumber { background-color : black; color : #76EE00; }");
        this->latticeSizeLcdNumber->setSegmentStyle(QLCDNumber::Flat);
        this->latticeSizeLcdNumber->setDigitCount(2);
        this->latticeSizeLcdNumber->setFixedWidth(80);
    }
    return this->latticeSizeLcdNumber;


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



    QWidget* widgetRight=new QWidget();
    widgetRight->setFixedWidth(80);
    QGridLayout* layoutWidgetRight=new QGridLayout();
    layoutWidgetRight->setContentsMargins(0,0,0,0);
    widgetRight->setLayout(layoutWidgetRight);
    layout->addWidget(widgetRight,0,2);



    DefaultPanel* totalCountWidget=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    totalCountWidget->getHeaderLabel()->setText(QString("<center>total count</center>"));
    totalCountWidget->setContentWidget(this->getTotalCountLcdNumber());
    totalCountWidget->init();
    layoutWidgetRight->addWidget(totalCountWidget,0,0);

    DefaultPanel* thermalizationCountWidget=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    thermalizationCountWidget->getHeaderLabel()->setText(QString("<center>therm. count</center>"));
    thermalizationCountWidget->setContentWidget(this->getThermalizationCountLcdNumber());
    thermalizationCountWidget->init();
    layoutWidgetRight->addWidget(thermalizationCountWidget,1,0);

    DefaultPanel* latticeSizeWidget=DefaultPanel::createInstance()->setOrientation(DefaultPanel::Orientation::Portrait);
    latticeSizeWidget->getHeaderLabel()->setText(QString("<center>lattice size</center>"));
    latticeSizeWidget->setContentWidget(this->getLatticeSizeLcdNumberLcdNumber());
    latticeSizeWidget->init();
    layoutWidgetRight->addWidget(latticeSizeWidget,2,0);



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



