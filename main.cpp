#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

#include <QtWebView/QtWebView>

int main(int argc, char *argv[])
{
    qputenv("QT_STYLE_OVERRIDE","");

    QtWebView::initialize();

    QApplication::setDesktopSettingsAware(false);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QApplication a(argc, argv);

    //qRegisterMetaType<SimulationSignal>();



    MainWindow w;
    w.show();
    return a.exec();
}

//(1)Method formal parameter is QSharedPointer<T>& fooPointer. For accessing the method parameter declare a local variable T& foo=*fooPointer
//and being a reference simple use dot member access operator as for instance fooPointer.fooMethod()

//(2)All class member variables are to be QSharedPointer objects, the descructor has to clear them.
//use const QSharedPointer<T>& for as method formal paramter if changing the supplied object is to be prohibited.

//(3)If a method returns a new object return it as QSharedPointer<T>
//Exceptions of course the copy constructur, also operator overloading and function action as operators (such as SuN SuN::dagger(SuN& suN)).

//(4) For local variables being not passed to other methods declare as: QScopedPointer<T> localVariable(new T()).
//Being a pointer access members via the -> operator: localVariable->someMethod();

// The . member access is used for references, stack varaiables and for members of the class itself
// The -> member access is used for pointers


