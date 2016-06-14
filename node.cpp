#include "node.h"
#include <QGraphicsItem>
#include <QPainter>

Node::Node(QGraphicsItem *parent) :
    QGraphicsObject(parent), _isdelete(false)
{
    setFlag(QGraphicsItem::ItemIsMovable,true);
}

QRectF Node::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(_isdelete) return;
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setBrush(QBrush(Qt::green));
    painter->drawEllipse(0,0,20,20);
    painter->drawText(boundingRect(),Qt::AlignCenter,QString::number(_number));
    setZValue(2);
}

