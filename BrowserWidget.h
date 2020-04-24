#ifndef BROWSERWIDGET_H
#define BROWSERWIDGET_H

#include <QWidget>
#include <QUrl>

#include <QQmlProperty>

#include <QtQuickWidgets/QQuickWidget>




class BrowserWidget : public QQuickWidget
{
    Q_OBJECT
public:
    explicit BrowserWidget(QWidget *parent = nullptr);
    void init();

signals:

};

#endif // BROWSERWIDGET_H
