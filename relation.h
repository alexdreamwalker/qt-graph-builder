#ifndef RELATION_H
#define RELATION_H

#include <QGraphicsObject>
#include "node.h"

class Relation : public QGraphicsObject
{
    Q_OBJECT
public:
    Node *_from;
    Node *_to;
    explicit Relation(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    QPointF centerOfLine(QLineF line);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setRelation(Node *first, Node *second) { _from=first; _to=second; }
    float Length() { return _length; }
    void setLength(float length) { _length=length; }
    bool Fake() { return _fake; }
    void setFake(bool fake) { _fake=fake; if(fake) _length=0; }
    int number() { return _number; }
    void setNumber(int number) { _number = number; }
    bool critical() { return _critical; }
    void setCritical(bool critical) { _critical=critical; }
    float tpn() { return _tpn; }
    float tro() { return _tro; }
    void setTpn(float tpn) { _tpn = tpn; }
    void setTro(float tro) { _tro = tro; }
    float Rp() { return _Rp; }
    float Rsv() { return _Rsv; }
    void setRp(float Rp) { _Rp =Rp; }
    void setRsv(float Rsv) { _Rsv = Rsv; }

private:
    float _length;
    int _number;
    bool _fake;
    bool _critical;
    float _tpn;
    float _tro;
    float _Rp;
    float _Rsv;


    
signals:
    
public slots:
    
};

#endif // RELATION_H
