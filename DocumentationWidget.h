#ifndef DOCUMENTATIONWIDGET_H
#define DOCUMENTATIONWIDGET_H

#include<QTabWidget>
#include<QQuickView>
#include <QQuickView>
#include <QQmlContext>
#include <QPushButton>
#include <QTimer>

#include "qquickitem.h"

#include "BrowserWidget.h"


class DocumentationWidget : public QWidget
{
    Q_OBJECT

public:    
    explicit DocumentationWidget(QWidget *parent = 0);
    BrowserWidget* getBrowserWidget();

public slots:
    void on_button_clicked();


private:
    BrowserWidget* browserWidget=nullptr;

};

#endif // DOCUMENTATIONWIDGET_H
