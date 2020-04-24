#include "VerticalLabel.h"

VerticalLabel::VerticalLabel(QWidget *parent)
    : QLabel(parent)
{

}

VerticalLabel::VerticalLabel(const QString &text, QWidget *parent)
: QLabel(text, parent)
{
}

void VerticalLabel::paintEvent(QPaintEvent* e)
{

    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);


    painter.translate( sizeHint().width(), sizeHint().height());
    painter.rotate(270);

    int paintHeight=e->region().boundingRect().height();

    QFontMetrics fm(this->font());
    int ha=fm.horizontalAdvance(this->text());


    painter.drawText(-(paintHeight-sizeHint().height())/2.0,0, text());

}

QSize VerticalLabel::minimumSizeHint() const
{
    QSize s = QLabel::minimumSizeHint();
    return QSize(s.height(), s.width());
}

QSize VerticalLabel::sizeHint() const
{
    QSize s = QLabel::sizeHint();
    return QSize(s.height(), s.width());
}
