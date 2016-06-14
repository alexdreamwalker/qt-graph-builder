#ifndef GRAPH_H
#define GRAPH_H

#include <QGraphicsObject>
#include "node.h"
#include "relation.h"
#include <QTableWidget>
#include "timetable.h"

class Graph : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Graph(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QList<Node*> nodes;
    QList<Relation*> relations;
    Node* nodeAt(int index) { return nodes.at(index); }
    void calculateTpo(int index);
    void calculateTrn(int index);
    void calculateTpn(int index);
    void calculateTro(int index);
    void calculateRp(int index);
    void calculateRsv(int index);
    void findCritical();
    QTableWidget* makeTable();
    float _minLength;
    TimeTable *timetable;
    
signals:
    
public slots:
    
};

#endif // GRAPH_H
