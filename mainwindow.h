#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLCDNumber>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QTabWidget>
#include <QTextEdit>
#include <QTextBrowser>

#include <QtWebView/QtWebView>

#include <QDesktopServices>
#include <QUrl>

//#include <QtWebEngineWidgets>


#include <QtSvg/QSvgWidget>

#include <QtCharts/QLineSeries>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>
#include <QPointF>

#include <QQuickView>
#include <QQmlContext>

#include "su3simulation.h"
#include "wilsonloopbybetachart.h"

#include "lattice.h"
#include "sun.h"
#include "simulationprogresssignal.h"
#include "simulationmeasurementsignal.h"
#include "progresscircle.h"

#include "SimulationWidget.h"
#include "SimulationExecutionPlanUtil.h"

#include "BrowserWidget.h"


#include "qquickitem.h"


using namespace QtWebView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signal_stopSimulation();

public slots:
    void on_buttonStart_clicked();

private:
    SU3Simulation* su3Simulation;
    QPushButton* buttonStart;
    QLineEdit* lineEdit;
    QFuture<void> simulationFuture;
    ProgressCircle* progressCircle;
    //QWebEngineView* test();
    SimulationWidget* simulationWidget;
    QString getDoc1();

    QQuickView* testWeb();



};


#endif // MAINWINDOW_H
