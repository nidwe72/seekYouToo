#ifndef VERTICALLABEL_H
#define VERTICALLABEL_H

#include <QObject>

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QFont>
#include <QFontMetrics>
#include <QStyleOption>


class VerticalLabel : public QLabel
{
    Q_OBJECT

public:
    explicit VerticalLabel(QWidget *parent=0);
    explicit VerticalLabel(const QString &text, QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent*);
    QSize sizeHint() const ;
    QSize minimumSizeHint() const;
};

#endif // VERTICALLABEL_H
