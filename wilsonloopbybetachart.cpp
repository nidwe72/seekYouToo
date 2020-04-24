#include "wilsonloopbybetachart.h"

WilsonLoopByBetaChart::WilsonLoopByBetaChart() : QChartView()
{
    QChart* chart = new QChart();
    setChart(chart);

    chart->legend()->setAlignment(Qt::AlignBottom);
    QFont font;
    font.setPixelSize(9);
    chart->legend()->setFont(font);


    chart->addAxis(this->getXAxis(),Qt::AlignBottom);
    chart->addAxis(this->getYAxis(),Qt::AlignLeft);

    this->addSeries(this->getSeriesStrongCouplingLimit());    
    QLineSeries* seriesStrongCouplingLimit2x2=this->getSeriesStrongCouplingLimit2x2();
    this->addSeries(seriesStrongCouplingLimit2x2);

    this->addSeries(this->getSeriesWeakCouplingLimit());
    this->addSeries(this->getSeries1x1());
    this->addSeries(this->getSeries2x2());
    this->addSeries(this->getSeries3x3());
    this->addSeries(this->getSeries4x4());
    this->addSeries(this->getSeries5x5());
    this->addSeries(this->getSeries6x6());

    chart->setTitleBrush(Qt::green);
    chart->setTitle("<center><b>Wilson loops</b> vs. beta values.<br/><font size='smallest'><font color='#ff0000'>s.c.:strong coupling analytical values</font><br/><font color='#0000ff'>w.c.:weak coupling analytical values</font></font></center>");
    chart->setBackgroundBrush(Qt::black);

    QLegendMarker* foo=chart->legend()->markers(seriesStrongCouplingLimit2x2).first();
    foo->setVisible(false);


    const auto markers = chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
        marker->setLabelBrush(QBrush(Qt::green));
    }


    setRenderHint(QPainter::Antialiasing);
    setStyleSheet("QWidget { background-color : #001a00; color : #76EE00; }");

}

QScatterSeries* WilsonLoopByBetaChart::getSeries1x1(){

    QScatterSeries *series = new QScatterSeries();
    series->setName("1x1");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(5.0);

    series->append(0.2f, 0.04988385f);
    series->append(0.4f, 0.09940182f);
    series->append(0.6f, 0.14810840f);
    series->append(0.8f, 0.19593741f);
    series->append(1.0f, 0.24316616f);
    series->append(1.2f, 0.29023868f);
    series->append(1.4f, 0.33794474f);
    series->append(1.6f, 0.38755996f);
    series->append(1.8f, 0.44095345f);
    series->append(2.0f, 0.50109321f);
    series->append(2.2f, 0.56927076f);
    series->append(2.4f, 0.62997832f);
    series->append(2.6f, 0.67001005f);
    series->append(2.8f,0.69942333f);
    series->append(3.0f, 0.72316685f);
    series->append(3.2f, 0.74303420f);
    series->append(3.4f, 0.76017138f);
    series->append(3.6f, 0.77503146f);
    series->append(3.8f, 0.78809569f);
    series->append(4.0f, 0.79964833f);
    series->append(4.2f, 0.80998789f);
    series->append(4.4f, 0.81931562f);
    series->append(4.6f, 0.82769958f);
    series->append(4.8f, 0.83539570f);
    series->append(5.0f, 0.84237704f);
    series->append(5.2f, 0.84877810f);
    series->append(5.4f, 0.85471779f);
    series->append(5.6f, 0.86017991f);
    series->append(5.8f, 0.86523833f);
    series->append(6.0f, 0.86994497f);
    series->append(6.2f, 0.87433599f);
    series->append(6.4f, 0.87841589f);
    series->append(6.8f, 0.88587690f);
    series->append(7.0f, 0.88924390f);
    series->append(7.2f, 0.89243999f);
    series->append(7.4f, 0.89546128f);
    series->append(7.6f, 0.89830124f);
    series->append(7.8f, 0.90098400f);
    series->append(8.0f, 0.90354502f);
    series->append(8.2f, 0.90597998f);
    series->append(8.4f, 0.90828116f);
    series->append(8.6f, 0.91046784f);
    series->append(8.8f, 0.91257251f);
    series->append(9.0f, 0.91455525f);
    series->append(9.2f, 0.91647150f);
    series->append(9.4f, 0.91829734f);
    series->append(9.6f, 0.92004241f);
    series->append(9.8f, 0.92171625f);
    series->append(10.0f, 0.92332227f);

    series->setPen(QPen(Qt::green));
    series->setBrush(QBrush(Qt::green));

    return series;
}


QScatterSeries* WilsonLoopByBetaChart::getSeries2x2(){

    QScatterSeries *series = new QScatterSeries(this);
    series->setName("2x2");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(5.0);

    series->append(0.2f,0.00000645 );
    series->append(0.4f,0.00010939 );
    series->append(0.6f,0.00049472 );
    series->append(0.8f,0.00149903 );
    series->append(1.0f,0.00344072 );
    series->append(1.2f,0.00714675 );
    series->append(1.4f,0.01329569 );
    series->append(1.6f,0.02350167 );
    series->append(1.8f,0.04099483 );
    series->append(1.9f,0.05462539 );
    series->append(2.0f,0.07342626 );
    series->append(2.2f,0.13652927 );
    series->append(2.4f,0.22262284 );
    series->append(2.6f,0.28791859 );
    series->append(2.8f,0.33714110 );
    series->append(3.0f,0.37844545 );
    series->append(3.2f,0.41423357 );
    series->append(3.4f,0.44630346 );
    series->append(3.6f,0.47482829 );
    series->append(3.8f,0.50044943 );
    series->append(4.0f,0.52360682 );
    series->append(4.2f,0.54476527 );
    series->append(4.4f,0.56415022 );
    series->append(4.6f,0.58181069 );
    series->append(4.8f,0.59826162 );
    series->append(5.0f,0.61335467 );
    series->append(5.2f,0.62726354 );
    series->append(5.4f,0.64039853 );
    series->append(5.6f,0.65256941 );
    series->append(5.8f,0.66397022 );
    series->append(6.0f,0.67452750 );
    series->append(6.2f,0.68455332 );
    series->append(6.4f,0.69390144 );
    series->append(6.6f,0.70278222 );
    series->append(6.8f,0.71118483 );
    series->append(7.0f,0.71898940 );
    series->append(7.2f,0.72649792 );
    series->append(7.4f,0.73364467 );
    series->append(7.6f,0.74035011 );
    series->append(7.8f,0.74669660 );
    series->append(8.0f,0.75278030 );
    series->append(8.2f,0.75864273 );
    series->append(8.4f,0.76416059 );
    series->append(8.6f,0.76940692 );
    series->append(8.8f,0.77452552 );
    series->append(9.0f,0.77934944 );
    series->append(9.2f,0.78398509 );
    series->append(9.4f,0.78843587 );
    series->append(9.6f,0.79268634 );
    series->append(9.8f,0.79680557 );
    series->append(10.0f,0.80073097 );

    series->setPen(QPen(QPen(Qt::green)));
    series->setBrush(QBrush(Qt::green));

    return series;
}



QScatterSeries* WilsonLoopByBetaChart::getSeries3x3(){

    QScatterSeries *series = new QScatterSeries(this);
    series->setName("3x3");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(5.0);

    series->append(0.2f,0.00006958 );
    series->append(0.4f,-0.00004491 );
    series->append(0.6f,0.00004843 );
    series->append(0.8f,0.00005436 );
    series->append(1.0f,0.00001727 );
    series->append(1.2f,0.00001723 );
    series->append(1.4f,0.00004329 );
    series->append(1.6f,0.00023874 );
    series->append(1.8f,0.00082335 );
    series->append(1.9f,0.00170725 );
    series->append(2.0f,0.00359359 );
    series->append(2.1f,0.00786283 );
    series->append(2.2f,0.01739938 );
    series->append(2.3f,0.03520637 );
    series->append(2.4f,0.05931279 );
    series->append(2.5f,0.08339100 );
    series->append(2.6f,0.10548127 );
    series->append(2.7f,0.12558863 );
    series->append(2.8f,0.14467034 );
    series->append(3.0f,0.18056703 );
    series->append(3.2f,0.21350515 );
    series->append(3.4f,0.24506228 );
    series->append(3.6f,0.27436947 );
    series->append(3.8f,0.30154204 );
    series->append(4.0f,0.32694328 );
    series->append(4.2f,0.35085569 );
    series->append(4.4f,0.37334514 );
    series->append(4.6f,0.39421011 );
    series->append(4.8f,0.41405158 );
    series->append(5.0f,0.43260468 );
    series->append(5.2f,0.44975832 );
    series->append(5.4f,0.46646313 );
    series->append(5.6f,0.48201775 );
    series->append(5.8f,0.49681526 );
    series->append(6.0f,0.51046870 );
    series->append(6.2f,0.52372222 );
    series->append(6.4f,0.53613747 );
    series->append(6.6f,0.54811812 );
    series->append(6.8f,0.55957183 );
    series->append(7.0f,0.57013384 );
    series->append(7.2f,0.58046735 );
    series->append(7.4f,0.59038962 );
    series->append(7.6f,0.59968064 );
    series->append(7.8f,0.60850760 );
    series->append(8.0f,0.61703663 );
    series->append(8.2f,0.62533617 );
    series->append(8.4f,0.63318130 );
    series->append(8.6f,0.64061914 );
    series->append(8.8f,0.64795016 );
    series->append(9.0f,0.65495473 );
    series->append(9.2f,0.66161532 );
    series->append(9.4f,0.66801329 );
    series->append(9.6f,0.67419565 );
    series->append(9.8f,0.68020016 );
    series->append(10.0f,0.68595809);

    series->setPen(QPen(QPen(Qt::green)));
    series->setBrush(QBrush(Qt::green));

    return series;
}

QScatterSeries* WilsonLoopByBetaChart::getSeries4x4(){

    QScatterSeries *series = new QScatterSeries(this);
    series->setName("4x4");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(5.0);

    series->append(0.2f,-0.00000576 );
    series->append(0.4f,0.00001046 );
    series->append(0.6f,0.00002080 );
    series->append(0.8f,-0.00005524 );
    series->append(1.0f,-0.00000811 );
    series->append(1.2f,-0.00000842 );
    series->append(1.4f,-0.00003046 );
    series->append(1.6f,-0.00000994 );
    series->append(1.8f,0.00002394 );
    series->append(1.9f,-0.00000628 );
    series->append(2.0f,0.00008219 );
    series->append(2.1f,0.00027863 );
    series->append(2.2f,0.00131126 );
    series->append(2.3f,0.00500653 );
    series->append(2.4f,0.01319692 );
    series->append(2.5f,0.02416978 );
    series->append(2.6f,0.03592334 );
    series->append(2.7f,0.04764684 );
    series->append(2.8f,0.05926635 );
    series->append(3.0f,0.08327347 );
    series->append(3.2f,0.10698863 );
    series->append(3.4f,0.13150514 );
    series->append(3.6f,0.15545428 );
    series->append(3.8f,0.17856327 );
    series->append(4.0f,0.20098226 );
    series->append(4.2f,0.22286461 );
    series->append(4.4f,0.24391764 );
    series->append(4.6f,0.26397382 );
    series->append(4.8f,0.28358793 );
    series->append(5.0f,0.30211850 );
    series->append(5.2f,0.31939839 );
    series->append(5.4f,0.33675284 );
    series->append(5.6f,0.35307605 );
    series->append(5.8f,0.36882442 );
    series->append(6.0f,0.38335460 );
    series->append(6.2f,0.39777173 );
    series->append(6.4f,0.41138116 );
    series->append(6.6f,0.42474568 );
    series->append(6.8f,0.43755464 );
    series->append(7.0f,0.44941770 );
    series->append(7.2f,0.46113345 );
    series->append(7.4f,0.47247702 );
    series->append(7.6f,0.48315538 );
    series->append(7.8f,0.49326652 );
    series->append(8.0f,0.50326074 );
    series->append(8.2f,0.51292001 );
    series->append(8.4f,0.52220685 );
    series->append(8.6f,0.53089508 );
    series->append(8.8f,0.53967062 );
    series->append(9.0f,0.54814493 );
    series->append(9.2f,0.55600429 );
    series->append(9.4f,0.56366102 );
    series->append(9.6f,0.57114137 );
    series->append(9.8f,0.57843527 );
    series->append(10.0f,0.58545812 );

    series->setPen(QPen(QPen(Qt::green)));
    series->setBrush(QBrush(Qt::green));

    return series;
}


QScatterSeries* WilsonLoopByBetaChart::getSeries5x5(){

    QScatterSeries *series = new QScatterSeries(this);
    series->setName("5x5");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(5.0);

    series->append(0.2f,0.00001376 );
    series->append(0.4f,0.00001655 );
    series->append(0.6f,-0.00003249 );
    series->append(0.8f,-0.00000213 );
    series->append(1.0f,0.00003957 );
    series->append(1.2f,0.00002470 );
    series->append(1.4f,0.00004568 );
    series->append(1.6f,0.00001010 );
    series->append(1.8f,-0.00000484 );
    series->append(1.9f,0.00002008 );
    series->append(2.0f,-0.00002874 );
    series->append(2.1f,0.00000876 );
    series->append(2.2f,0.00006322 );
    series->append(2.3f,0.00049490 );
    series->append(2.4f,0.00250982 );
    series->append(2.5f,0.00643866 );
    series->append(2.6f,0.01159599 );
    series->append(2.7f,0.01749954 );
    series->append(2.8f,0.02360225 );
    series->append(3.0f,0.03766689 );
    series->append(3.2f,0.05276176 );
    series->append(3.4f,0.06965838 );
    series->append(3.6f,0.08702581 );
    series->append(3.8f,0.10468036 );
    series->append(4.0f,0.12253432 );
    series->append(4.2f,0.14043205 );
    series->append(4.4f,0.15828728 );
    series->append(4.6f,0.17562298 );
    series->append(4.8f,0.19306037 );
    series->append(5.0f,0.20988100 );
    series->append(5.2f,0.22563236 );
    series->append(5.4f,0.24194438 );
    series->append(5.6f,0.25746343 );
    series->append(5.8f,0.27264138 );
    series->append(6.0f,0.28671418 );
    series->append(6.2f,0.30092038 );
    series->append(6.4f,0.31441084 );
    series->append(6.6f,0.32801298 );
    series->append(6.8f,0.34100681 );
    series->append(7.0f,0.35315458 );
    series->append(7.2f,0.36518768 );
    series->append(7.4f,0.37698860 );
    series->append(7.6f,0.38815701 );
    series->append(7.8f,0.39870813 );
    series->append(8.0f,0.40942948 );
    series->append(8.2f,0.41959675 );
    series->append(8.4f,0.42955812 );
    series->append(8.6f,0.43881672 );
    series->append(8.8f,0.44845387 );
    series->append(9.0f,0.45772954 );
    series->append(9.2f,0.46625307 );
    series->append(9.4f,0.47457372 );
    series->append(9.6f,0.48278467 );
    series->append(9.8f,0.49090346 );
    series->append(10.0f,0.49865720 );

    series->setPen(QPen(QPen(Qt::green)));
    series->setBrush(QBrush(Qt::green));

    return series;
}



QScatterSeries* WilsonLoopByBetaChart::getSeries6x6(){

    QScatterSeries *series = new QScatterSeries(this);
    series->setName("6x6");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(5.0);

    series->append(0.2f,-0.00000852 );
    series->append(0.4f,-0.00000530 );
    series->append(0.6f,-0.00000195 );
    series->append(0.8f,0.00000513 );
    series->append(1.0f,0.00001930 );
    series->append(1.2f,0.00002785 );
    series->append(1.4f,0.00001976 );
    series->append(1.6f,0.00001270 );
    series->append(1.8f,-0.00002796 );
    series->append(1.9f,0.00000983 );
    series->append(2.0f,-0.00005490 );
    series->append(2.1f,-0.00002639 );
    series->append(2.2f,-0.00002017 );
    series->append(2.3f,0.00006674 );
    series->append(2.4f,0.00038597 );
    series->append(2.5f,0.00160326 );
    series->append(2.6f,0.00360116 );
    series->append(2.7f,0.00620825 );
    series->append(2.8f,0.00918771 );
    series->append(3.0f,0.01677325 );
    series->append(3.2f,0.02573245 );
    series->append(3.4f,0.03662861 );
    series->append(3.6f,0.04830300 );
    series->append(3.8f,0.06097644 );
    series->append(4.0f,0.07423148 );
    series->append(4.2f,0.08809417 );
    series->append(4.4f,0.10227927 );
    series->append(4.6f,0.11635929 );
    series->append(4.8f,0.13094903 );
    series->append(5.0f,0.14529832 );
    series->append(5.2f,0.15882351 );
    series->append(5.4f,0.17323627 );
    series->append(5.6f,0.18731070 );
    series->append(5.8f,0.20098873 );
    series->append(6.0f,0.21387561 );
    series->append(6.2f,0.22701864 );
    series->append(6.4f,0.23968462 );
    series->append(6.6f,0.25276890 );
    series->append(6.8f,0.26524492 );
    series->append(7.0f,0.27696220 );
    series->append(7.2f,0.28867608 );
    series->append(7.4f,0.30017335 );
    series->append(7.6f,0.31120889 );
    series->append(7.8f,0.32175264 );
    series->append(8.0f,0.33254960 );
    series->append(8.2f,0.34266125 );
    series->append(8.4f,0.35272071 );
    series->append(8.6f,0.36210205 );
    series->append(8.8f,0.37206267 );
    series->append(9.0f,0.38173699 );
    series->append(9.2f,0.39035078 );
    series->append(9.4f,0.39897542 );
    series->append(9.6f,0.40747184 );
    series->append(9.8f,0.41609734 );
    series->append(10.0f,0.42414025 );

    series->setPen(QPen(QPen(Qt::green)));
    series->setBrush(QBrush(Qt::green));

    return series;
}




QCategoryAxis* WilsonLoopByBetaChart::getXAxis(){

    if(!this->xAxis){

        this->xAxis = new QCategoryAxis(this);
        //this->xAxis->setGridLineVisible(false);

        this->xAxis->setTitleText("beta");

        QPen axisPen(Qt::green);
        axisPen.setWidth(2);
        this->xAxis->setLinePen(axisPen);
        QFont font;
        font.setPixelSize(10);
        this->xAxis->setLabelsFont(font);
        QBrush axisBrush(Qt::green);
        this->xAxis->setLabelsBrush(axisBrush);        
        this->xAxis->setTitleBrush(axisBrush);

        this->xAxis->append("0", 0.0f);
        this->xAxis->append("1", 1.0f);
        this->xAxis->append("2", 2.0f);
        this->xAxis->append("3", 3.0f);
        this->xAxis->append("4", 4.0f);
        this->xAxis->append("5", 5.0f);
        this->xAxis->append("6", 6.0f);
        this->xAxis->append("7", 7.0f);
        this->xAxis->append("8", 8.0f);
        this->xAxis->append("9", 9.0f);
        this->xAxis->append("10", 10.0f);

        this->xAxis->setRange(0.0f, 5.0f);

    }

    return this->xAxis;
}

QCategoryAxis* WilsonLoopByBetaChart::getYAxis(){

    if(!this->yAxis){
        this->yAxis = new QCategoryAxis(this);

        //this->yAxis->setGridLineVisible(false);

        this->yAxis->setTitleText("Wilson loop");

        QPen axisPen(Qt::green);
        axisPen.setWidth(2);
        this->yAxis->setLinePen(axisPen);
        QFont font;
        font.setPixelSize(10);
        this->yAxis->setLabelsFont(font);
        QBrush axisBrush(Qt::green);
        this->yAxis->setLabelsBrush(axisBrush);
        this->yAxis->setTitleBrush(axisBrush);


        this->yAxis->append("0.0", 0.0f);
        this->yAxis->append("0.1", 0.1f);
        this->yAxis->append("0.2", 0.2f);
        this->yAxis->append("0.3", 0.3f);
        this->yAxis->append("0.4", 0.4f);
        this->yAxis->append("0.5", 0.5f);
        this->yAxis->append("0.6", 0.6f);
        this->yAxis->append("0.7", 0.7f);
        this->yAxis->append("0.8", 0.8f);
        this->yAxis->append("0.9", 0.9f);
        this->yAxis->append("1.0", 1.0f);

        this->yAxis->setRange(0.0f, 1.0f);
    }

    return this->yAxis;
}

QLineSeries* WilsonLoopByBetaChart::getSeriesStrongCouplingLimit(){

    QLineSeries* result=new QLineSeries(this);
    result->setName("s.c.");

    QPen pen=QPen(Qt::red);
    pen.setWidth(3);
    result->setPen(pen);

    for (float beta = 0.0f; beta <= 2.0f; beta=beta+0.1f) {
      float value=beta*0.25f;
      result->append(beta,value);
    }

    return result;
}


QLineSeries* WilsonLoopByBetaChart::getSeriesStrongCouplingLimit2x2(){

    QLineSeries* result=new QLineSeries(this);
    result->setName("s.c.2x2");

    QPen pen=QPen(Qt::red);
    pen.setWidth(3);
    result->setPen(pen);

    for (float beta = 0.0f; beta <= 2.0f; beta=beta+0.1f) {
      float value=std::pow(beta*0.25f,4.0f);
      result->append(beta,value);
    }

    return result;
}


QLineSeries* WilsonLoopByBetaChart::getSeriesWeakCouplingLimit(){

    QLineSeries* result=new QLineSeries(this);
    result->setName("w.c.");

    QPen pen=QPen(Qt::blue);
    pen.setWidth(3);
    result->setPen(pen);

    for (float beta = 2.0f; beta <= 10.0f; beta=beta+0.1f) {
      float value=1.0f-(3.0f/(4.0f*beta));
      result->append(beta,value);
    }

    return result;
}


void WilsonLoopByBetaChart::addSeries(QAbstractSeries *series){
    this->chart()->addSeries(series);
    series->attachAxis(this->getXAxis());
    series->attachAxis(this->getYAxis());
}

