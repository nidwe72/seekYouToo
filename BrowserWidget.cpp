#include "BrowserWidget.h"

BrowserWidget::BrowserWidget(QWidget *parent) : QWidget(parent)
{    
    QGridLayout* layout=new QGridLayout();
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);
    layout->addWidget(QWidget::createWindowContainer(this->getContainer(),this));
}

void BrowserWidget::loadUrl(QString url)
{
    QMetaObject::invokeMethod(this->getContainer()->rootObject(), "setUrl",
            Q_ARG(QString, url));
}

QQuickView *BrowserWidget::getContainer()
{
    if(this->container==nullptr){
        this->container=new QQuickView();
        this->container->setVisible(true);
        this->container->setSource(QUrl("qrc:docs/docs/browserWidget.qml"));
        this->container->setProperty("foo",QString("http://www.google.com"));
        this->container->setResizeMode(QQuickView::SizeRootObjectToView);
    }
    return this->container;

}



