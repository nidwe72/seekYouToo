#ifndef DOCUMENTATIONWIDGET_H
#define DOCUMENTATIONWIDGET_H

#include <QPushButton>
#include <QGridLayout>
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
