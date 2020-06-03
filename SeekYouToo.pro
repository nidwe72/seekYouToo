QT       += core gui 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quick charts svg quickwidgets webview

#webenginewidgets
#texttospeech

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BrowserWidget.cpp \
    DefaultPanel.cpp \
    DocumentationWidget.cpp \
    SimulationExecutionPlan.cpp \
    SimulationExecutionPlanEntry.cpp \
    SimulationExecutionPlanUtil.cpp \
    SimulationExecutionPlanWidget.cpp \
    SimulationWidget.cpp \
    TestWidget.cpp \
    VerticalLabel.cpp \
    lattice.cpp \
    latticeneighbor.cpp \
    latticesite.cpp \
    latticesubset.cpp \
    main.cpp \
    mainwindow.cpp \
    progresscircle.cpp \
    random.cpp \
    simulationbetaresult.cpp \
    simulationmeasurementsignal.cpp \
    simulationprogresssignal.cpp \
    simulationprogresswidget.cpp \
    simulationresult.cpp \
    smartpointer.cpp \
    staples.cpp \
    statisticutil.cpp \
    su3simulation.cpp \
    sun.cpp \
    wilson.cpp \
    wilsonloopbybetachart.cpp \
    wilsonloopwidget.cpp

HEADERS += \
    BrowserWidget.h \
    DefaultPanel.h \
    DocumentationWidget.h \
    SimulationExecutionPlan.h \
    SimulationExecutionPlanEntry.h \
    SimulationExecutionPlanUtil.h \
    SimulationExecutionPlanWidget.h \
    SimulationWidget.h \
    TestWidget.h \
    VerticalLabel.h \
    lattice.h \
    latticeneighbor.h \
    latticesite.h \
    latticesubset.h \
    mainwindow.h \
    progresscircle.h \
    random.h \
    simulationbetaresult.h \
    simulationmeasurementsignal.h \
    simulationprogresssignal.h \
    simulationprogresswidget.h \
    simulationresult.h \
    smartpointer.h \
    staples.h \
    statisticutil.h \
    su3simulation.h \
    sun.h \
    wilson.h \
    wilsonloopbybetachart.h \
    wilsonloopwidget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    doc.qrc \
    resources/browserWidget.qrc

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

    DISTFILES += \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/res/values/libs.xml
}

