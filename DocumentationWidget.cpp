#include "DocumentationWidget.h"


DocumentationWidget::DocumentationWidget(QWidget *parent):QWidget(parent)
{

    QGridLayout* layout=new QGridLayout();
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    BrowserWidget *browserWidget = this->getBrowserWidget();

    layout->addWidget(browserWidget,0,0,1,3);

    QPushButton* buttonDocWorkman= new QPushButton("Workman");
    buttonDocWorkman->setObjectName(QString("Workman"));
    layout->addWidget(buttonDocWorkman,1,0);

    QPushButton* buttonDocLayman= new QPushButton("Layman");
    buttonDocLayman->setObjectName(QString("Layman"));
    layout->addWidget(buttonDocLayman,1,1);

    QPushButton* buttonDocAbout= new QPushButton("About");
    buttonDocAbout->setObjectName(QString("About"));
    layout->addWidget(buttonDocAbout,1,2);

    browserWidget->loadUrl(QString("https://www.youtube.com/embed/x9r9fzIHpBs"));

    QObject::connect(buttonDocWorkman,&QPushButton::clicked,this,&DocumentationWidget::on_button_clicked);
    QObject::connect(buttonDocLayman,&QPushButton::clicked,this,&DocumentationWidget::on_button_clicked);
    QObject::connect(buttonDocAbout,&QPushButton::clicked,this,&DocumentationWidget::on_button_clicked);

}

BrowserWidget *DocumentationWidget::getBrowserWidget()
{
    if(this->browserWidget==nullptr){
        this->browserWidget=new BrowserWidget();
    }
    return this->browserWidget;
}

void DocumentationWidget::on_button_clicked()
{
    BrowserWidget *browserWidget = this->getBrowserWidget();

    QObject* sender=QObject::sender();
    if(sender->objectName()==QString("Workman")){
        browserWidget->loadUrl(QString("http://edwin-roth.at/downloads/seekYouToo/docs/workman/workmanGuide.html"));
    } else if(sender->objectName()==QString("Layman")){
        browserWidget->loadUrl(QString("https://www.youtube.com/embed/x9r9fzIHpBs"));
    }else if(sender->objectName()==QString("About")){
        browserWidget->loadUrl(QString("http://edwin-roth.at/downloads/seekYouToo/docs/about/about.html"));
    }

}



