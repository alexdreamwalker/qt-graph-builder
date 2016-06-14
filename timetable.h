#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QGraphicsObject>


struct TimeLine
{
    int length;
    int number;
    int from;
    int height;
    float trn;
    float tro;
    float tpn;
    float tpo;
    float rp;
    float rsv;
    bool critical;
};

class TimeTable : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit TimeTable(QGraphicsObject *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void addLine(TimeLine line);
    void setSize(QSizeF size) { _size = size; }


private:
    QList<TimeLine> _lines;
    QSizeF _size;


signals:
    
public slots:
    
};

#endif // TIMETABLE_H
