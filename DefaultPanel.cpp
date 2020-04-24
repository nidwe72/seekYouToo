#include "DefaultPanel.h"

DefaultPanel::DefaultPanel(QWidget *parent):QWidget(parent)
{

}

void DefaultPanel::init()
{
    QGridLayout* layout=new QGridLayout();
    this->setLayout(layout);
    layout->setContentsMargins(0,0,0,0);

    QLabel *headerLabel = this->getHeaderLabel();
    layout->addWidget(headerLabel,0,0);

    QWidget *contentWidgetToUse = this->getContentWidget();

    Orientation orientationToUse = this->getOrientation();

    if(orientationToUse==Orientation::Landscape){
        layout->addWidget(contentWidgetToUse,0,1);
    }else{
        layout->addWidget(contentWidgetToUse,1,0);
    }

}


QLabel *DefaultPanel::getHeaderLabel()
{
    if(this->headerLabel==nullptr){
        Orientation orientation = this->getOrientation();
        if(orientation==Orientation::Landscape){
            this->headerLabel=new VerticalLabel();
            this->headerLabel->setObjectName(QString("foobar"));
            this->headerLabel->setStyleSheet("background-color:#004d1a;font-size:12px;");
            this->headerLabel->setFixedWidth(20);
        }else{
            this->headerLabel=new QLabel();
            this->headerLabel->setObjectName(QString("foobar"));
            this->headerLabel->setStyleSheet("background-color:#282828;font-size:12px;");
            this->headerLabel->setFixedHeight(20);
        }
    }

    return this->headerLabel;
}

DefaultPanel* DefaultPanel::setContentWidget(QWidget *contentWidget)
{
    this->contentWidget=contentWidget;
    return this;
}

QWidget *DefaultPanel::getContentWidget()
{
    return this->contentWidget;
}

DefaultPanel *DefaultPanel::createInstance()
{
    DefaultPanel* result=new DefaultPanel();
    return result;
}

DefaultPanel* DefaultPanel::setOrientation(DefaultPanel::Orientation orientation)
{
    this->orientation=orientation;
    return  this;
}

DefaultPanel::Orientation DefaultPanel::getOrientation()
{
    return this->orientation;
}


void DefaultPanel::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
