#include "DocumentationWidget.h"


DocumentationWidget::DocumentationWidget(QWidget *parent):QTabWidget(parent)
{
    this->setTabPosition(QTabWidget::South);

    BrowserWidget* foo=new BrowserWidget();
    this->addTab(foo,QString("Layman"));
    QString url = "https://www.youtube.com/embed/x9r9fzIHpBs";
    foo->loadUrl(url);


    //QTimer::singleShot(3000,this,&DocumentationWidget::selectStartTabSlot);

//    QTimer *timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &DocumentationWidget::selectStartTabSlot);
//    timer->start(1000);

}

void DocumentationWidget::selectStartTabSlot()
{
    this->addTab(QWidget::createWindowContainer(this->getWorkmanDocView(),this),QString("Workman"));
    this->addTab(QWidget::createWindowContainer(this->getDocVideoView(),this),QString("Layman"));
    this->addTab(QWidget::createWindowContainer(this->getAboutDocView(),this),QString("About"));

    //this->setCurrentIndex(1);
}

QQuickView *DocumentationWidget::getDocVideoView()
{
    QQuickView* result=new QQuickView();
    result->setVisible(true);
    result->setSource(QUrl("qrc:docs/docs/browserWidget.qml"));
    result->setProperty("foo",QString("http://www.google.com"));

    QQmlContext *localRootContext = result->rootContext();
    localRootContext->setContextProperty(QStringLiteral("url"),QStringLiteral("http://www.google.com"));

    QString msg = "https://www.youtube.com/embed/x9r9fzIHpBs";
//    QString msg = "https://www.youtube.com/embed/x9r9fzIHpBs?autoplay=1";

    QMetaObject::invokeMethod(result->rootObject(), "setUrl",Q_ARG(QString, msg));

    result->setResizeMode(QQuickView::SizeRootObjectToView);
    return result;

}

QQuickView *DocumentationWidget::getWorkmanDocView()
{
    QQuickView* result=new QQuickView();
    result->setVisible(true);
    result->setSource(QUrl("qrc:docs/docs/browserWidget.qml"));
    result->setProperty("foo",QString("http://www.google.com"));

    QQmlContext *localRootContext = result->rootContext();
    localRootContext->setContextProperty(QStringLiteral("url"),QStringLiteral("http://www.google.com"));

//    QQmlProperty foo(localRootContext,"url");
//    QVariant localRead = foo.read();
//    foo.write(QVariant::fromValue(QString("http://google.com")));

    //result->setProperty("url",QString("http://google.com"));

    QString msg = "http://edwin-roth.at/downloads/seekYouToo/docs/workman/workmanGuide.html";
    QMetaObject::invokeMethod(result->rootObject(), "setUrl",
            Q_ARG(QString, msg));


    result->setResizeMode(QQuickView::SizeRootObjectToView);
    return result;
}

QQuickView *DocumentationWidget::getAboutDocView()
{
    QQuickView* result=new QQuickView();
    result->setVisible(true);
    result->setSource(QUrl("qrc:docs/docs/browserWidget.qml"));
    result->setProperty("foo",QString("http://www.google.com"));

    QQmlContext *localRootContext = result->rootContext();
    localRootContext->setContextProperty(QStringLiteral("url"),QStringLiteral("http://www.google.com"));

    QString msg = "http://edwin-roth.at/downloads/seekYouToo/docs/about/about.html";
    QMetaObject::invokeMethod(result->rootObject(), "setUrl",
            Q_ARG(QString, msg));


    result->setResizeMode(QQuickView::SizeRootObjectToView);
    return result;
}

void DocumentationWidget::selectStartTab()
{
    this->setCurrentIndex(0);
}


