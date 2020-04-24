#include "BrowserWidget.h"

BrowserWidget::BrowserWidget(QWidget *parent) : QQuickWidget(parent)
{
    this->init();
}

void BrowserWidget::init()
{           
    //this->setSource(QUrl(QString(":/browserWidget/browserWidget.qml")));


    this->setSource(QUrl(QString(":/docs/docs/browserWidget.qml")));



    //QQuickItem *localRootObject = this->rootObject();
    //QQmlProperty::write(localRootObject, QString("url"),QString("http://www.google.com"));
    //QQmlProperty::write(localRootObject,QString("url"),QString("http://www.google.com"));



}
