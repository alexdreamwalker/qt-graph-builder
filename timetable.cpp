#include "timetable.h"
#include <QPainter>

TimeTable::TimeTable(QGraphicsObject *parent) :
    QGraphicsObject(parent)
{
    _size = QSizeF(500,500);
}

void TimeTable::addLine(TimeLine line)
{
    _lines.append(line);
}

QRectF TimeTable::boundingRect() const
{
    return QRectF(0,0,_size.width(),_size.height());
}

void TimeTable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    Qt::GlobalColor color=Qt::black;
    Qt::PenStyle penstyle=Qt::SolidLine;

    painter->translate(0,_size.height());


    painter->drawLine(0,0,_size.width(),0);
    painter->drawLine(0,0,0,-_size.height());

    int max = 0;
    for(int i=0;i<_lines.count();i++)
        if(_lines.at(i).tro+_lines.at(i).rp>max) max=_lines.at(i).tro+_lines.at(i).rp;

    int step=_size.width()/max;

    //drawing axes

    int levels = _size.width()/step;

    for(int i=0;i<_size.width()/step;i++)
    {
        painter->drawLine(i*step,-5,i*step,5);
        painter->drawText(i*step,15,QString::number(i));
        painter->drawLine(-5,-i*step,5,-i*step);
    }

    //drawing critical

    color=Qt::red;

    painter->setPen(QPen(QBrush(color),2,penstyle));

    int level=levels;


    for(int i=0;i<_lines.count();i++)
        if(_lines.at(i).critical)
        {
            color=Qt::red;
            painter->setPen(QPen(QBrush(color),2,penstyle));
            level--;
            painter->drawLine(_lines.at(i).trn*step,-level*step,_lines.at(i).tro*step,-level*step);
            painter->drawText((_lines.at(i).trn*step+_lines.at(i).tro*step)/2,-level*step+10,"a"+QString::number(_lines.at(i).number));
            painter->setPen(Qt::DashLine);
            painter->drawLine(_lines.at(i).tro*step,-level*step,_lines.at(i).tro*step,0);
        }

    //drawing others

    color=Qt::black;
    penstyle=Qt::SolidLine;
    painter->setPen(QPen(QBrush(color),2,penstyle));

    for(int i=0;i<_lines.count();i++)
        if(!_lines.at(i).critical)
        {
            color=Qt::black;
            penstyle=Qt::SolidLine;
            painter->setPen(QPen(QBrush(color),2,penstyle));
            level--;
            painter->drawLine(_lines.at(i).trn*step,-level*step,_lines.at(i).tro*step,-level*step);
            painter->drawText((_lines.at(i).trn*step+_lines.at(i).tro*step)/2,-level*step+10,"a"+QString::number(_lines.at(i).number));
            if(_lines.at(i).rp>0&&_lines.at(i).rsv==0) color=Qt::red;
            color=Qt::black;
            penstyle=Qt::DashLine;
            painter->setPen(QPen(QBrush(color),2,penstyle));
            painter->drawLine(_lines.at(i).tro*step,-level*step,(_lines.at(i).tro+_lines.at(i).rp)*step,-level*step);
            painter->setPen(Qt::DashLine);
            painter->drawLine(_lines.at(i).tro*step,-level*step,_lines.at(i).tro*step,0);
        }
}
