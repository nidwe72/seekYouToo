#ifndef BROWSERWIDGET_H
#define BROWSERWIDGET_H

#include <QWidget>
#include <QQuickView>

#include <QUrl>

#include <QQmlProperty>

#include <QGridLayout>

#include <QtQuickWidgets/QQuickWidget>

#include "qquickitem.h"


class BrowserWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BrowserWidget(QWidget *parent = nullptr);    
    void loadUrl(QString url);

private:
    QQuickView* container=nullptr;
    QQuickView* getContainer();

signals:

};

#endif // BROWSERWIDGET_H
