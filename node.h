#ifndef NODE_H
#define NODE_H

#include <QGraphicsObject>

class Node : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Node(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Deleted() { return _isdelete; }
    void setDeleted(bool deleted) { _isdelete = deleted; }
    QList<Node*> inItems;
    QList<Node*> outItems;
    float trn() { return _trn; }
    float tpo() { return _tpo; }
    void setTrn(float trn) { _trn = trn; }
    void setTpo(float tpo) { _tpo = tpo; }
    int number() { return _number; }
    void setNumber(int number) { _number=number; }\
    void setRank(int rank) { _rank = rank; }
    int rank() { return _rank; }
    float shortTime() { return _shortTime; }
    void setShortTime(float shortTime) { _shortTime = shortTime; }
    void setText(QString text) { _text=text; }
    QString text() { return _text; }

private:
    int _number;
    bool _isdelete;
    float _trn;
    float _tpo;
    int _rank;
    float _shortTime;
    QString _text;
    
signals:
    
public slots:
    
};

#endif // NODE_H
