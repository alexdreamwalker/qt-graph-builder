#include "relation.h"
#include <QPainter>
#include <QDebug>

Relation::Relation(QGraphicsItem *parent) :
    QGraphicsObject(parent),_fake(false),_critical(false)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    _from=NULL;
    _to=NULL;
}

QRectF Relation::boundingRect() const
{
    if(_from==NULL||_to==NULL) return QRectF();
    else return _from->sceneBoundingRect().unite(_to->sceneBoundingRect());
}

QPointF Relation::centerOfLine(QLineF line)
{
    QPointF point((line.x1()+line.x2())/2,(line.y1()+line.y2())/2);
    return point;
}

void Relation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing,true);
    if(!_from->Deleted()&&!_to->Deleted()) {
        Qt::GlobalColor color;
        Qt::PenStyle penstyle;
        if(_critical) color=Qt::red; else color=Qt::black;
        if(_fake) penstyle=Qt::DashLine; else penstyle=Qt::SolidLine;
        painter->setPen(QPen(QBrush(color),1,penstyle));
        QLineF line(_from->scenePos().x()+10,_from->scenePos().y()+10,_to->scenePos().x()+10,_to->scenePos().y()+10);
        painter->drawLine(line);
        char c = 'A'+_number;
        painter->drawText(boundingRect(),Qt::AlignCenter,(QString)c+" = "+QString::number(_length));
        painter->setBrush(QBrush(Qt::red));
        painter->drawLine(centerOfLine(line),QPointF(_to->scenePos().x()+10,_to->scenePos().y()+10));
    }
    setZValue(1);
}

