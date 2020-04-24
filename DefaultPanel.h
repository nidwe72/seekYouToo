#ifndef DEFAULTPANEL_H
#define DEFAULTPANEL_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QStyleOption>

#include "VerticalLabel.h"

class DefaultPanel : public QWidget
{
    Q_OBJECT
public:
    enum Orientation { Portrait, Landscape };
    explicit DefaultPanel(QWidget *parent = nullptr);

    virtual QLabel* getHeaderLabel();

    DefaultPanel* setOrientation(Orientation orientation);
    virtual Orientation getOrientation();

    DefaultPanel* setContentWidget(QWidget* contentWidget);
    virtual QWidget* getContentWidget();

    static DefaultPanel* createInstance();

    virtual void init();

signals:

protected:
    QWidget* contentWidget;
    QLabel* headerLabel=nullptr;

private:

    Orientation orientation=Orientation::Portrait;


protected:
    void paintEvent(QPaintEvent *event) override;

};



#endif // DEFAULTPANEL_H
