#ifndef DOCUMENTATIONWIDGET_H
#define DOCUMENTATIONWIDGET_H

#include<QTabWidget>
#include<QQuickView>
#include <QQuickView>
#include <QQmlContext>
#include <QTimer>

#include "qquickitem.h"

#include "BrowserWidget.h"


class DocumentationWidget : public QTabWidget
{
    Q_OBJECT

public:    
    explicit DocumentationWidget(QWidget *parent = 0);

public slots:
    void selectStartTabSlot();


private:
    QQuickView* getDocVideoView();
    QQuickView *getWorkmanDocView();
    QQuickView *getAboutDocView();

    void selectStartTab();
};

#endif // DOCUMENTATIONWIDGET_H
