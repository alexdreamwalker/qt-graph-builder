#include "graph.h"
#include <QDebug>

Graph::Graph(QGraphicsItem *parent) :
    QGraphicsObject(parent)
{
    nodes.clear();
    relations.clear();
    setFlag(QGraphicsItem::ItemHasNoContents,true);
}

QRectF Graph::boundingRect() const
{
    return childrenBoundingRect();
}

void Graph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Graph::calculateTrn(int index)
{
    float result=0;
    Node *node = nodeAt(index);
    int number=node->number();
    if(number==0) result=0;
    else
    {
       float max=0;
       for(int i=0;i<relations.count();i++)
           if(relations.at(i)->_to->number()==number) {
               float trn = relations.at(i)->_from->trn()+relations.at(i)->Length();
               if(trn>max) max=trn;
           }
       result=max;
    }

    qDebug() <<"trn" <<number <<result;
    node->setTrn(result);
}

void Graph::calculateTpo(int index)
{
    float result=0;
    Node *node = nodeAt(index);
    int number=node->number();
    if(number==nodes.count()-1) result=node->trn();
    else
    {
       float min=999;
       for(int i=0;i<relations.count();i++)
           if(relations.at(i)->_from->number()==number) {
               float tpo = relations.at(i)->_to->tpo()-relations.at(i)->Length();
               if(tpo<min) min=tpo;
           }
       result=min;
    }

    if(result<0) result=0;
    qDebug() <<"tpo" <<index <<result;
    node->setTpo(result);
}

void Graph::calculateTpn(int index)
{
   float result=0;
   Relation *relation = relations.at(index);

   result=relation->_to->tpo()-relation->Length();

   relation->setTpn(result);
}

void Graph::calculateTro(int index)
{
    float result=0;
    Relation *relation = relations.at(index);

    result=relation->_from->trn()+relation->Length();

    relation->setTro(result);
}

void Graph::calculateRp(int index)
{
    float result=0;
    Relation *relation = relations.at(index);

    result=relation->_to->tpo()-relation->Length()-relation->_from->trn();

    relation->setRp(result);
}

void Graph::calculateRsv(int index)
{
    float result=0;
    Relation *relation = relations.at(index);

    result=relation->_to->trn()-relation->Length()-relation->_from->trn();

    relation->setRsv(result);
}

void Graph::findCritical()
{
    _minLength = 0;

    for(int i=0;i<nodes.count();i++) {
        calculateTrn(i);
    }

    for(int i=nodes.count()-1;i>-1;i--) {
        calculateTpo(i);
    }

    for(int i=0;i<relations.count();i++)
    {
        bool okay = true;
        if(relations.at(i)->_from->trn()!=relations.at(i)->_from->tpo()) okay=false;
        if(relations.at(i)->_to->trn()!=relations.at(i)->_to->tpo()) okay=false;
        if((relations.at(i)->_to->trn()-relations.at(i)->_from->trn())!=relations.at(i)->Length()) okay=false;

        relations.at(i)->setCritical(okay);
        if(okay) _minLength=_minLength+relations.at(i)->Length();
    }
}

QTableWidget* Graph::makeTable()
{
    for(int i=0;i<relations.count();i++) calculateTpn(i);
    for(int i=0;i<relations.count();i++) calculateTro(i);
    for(int i=0;i<relations.count();i++) calculateRp(i);
    for(int i=0;i<relations.count();i++) calculateRsv(i);

    QTableWidget * table = new QTableWidget(relations.count(),9);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Работа"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Время t[i][j]"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Начало t[i][рн]"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Окончание t[ij][po]"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Начало t[ij][пн]"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("Окончание t[j][по]"));
    table->setHorizontalHeaderItem(6, new QTableWidgetItem("Полный резерв R[ij][п]"));
    table->setHorizontalHeaderItem(7, new QTableWidgetItem("Свободный резерв R[ij][св]"));
    table->setHorizontalHeaderItem(8, new QTableWidgetItem("Принадл. крит. пути"));

    for(int i=0;i<relations.count();i++)
        for(int j=0;j<9;j++)
            table->setItem(i,j,new QTableWidgetItem());

    for(int i=0;i<relations.count();i++)
    {
        Relation *relation = relations.at(i);
        TimeLine line;
        char c = 'A'+relation->number();
        table->item(i,0)->setText(QString(c));
        table->item(i,1)->setText(QString::number(relation->Length()));
        line.length=relation->Length();
        table->item(i,2)->setText(QString::number(relation->_from->trn()));
        line.trn=relation->_from->trn();
        table->item(i,3)->setText(QString::number(relation->tro()));
        line.tro=relation->tro();
        table->item(i,4)->setText(QString::number(relation->tpn()));
        line.tpn=relation->tpn();
        table->item(i,5)->setText(QString::number(relation->_to->tpo()));
        line.tpo=relation->_to->tpo();
        table->item(i,6)->setText(QString::number(relation->Rp()));
        line.rp=relation->Rp();
        table->item(i,7)->setText(QString::number(relation->Rsv()));
        line.rsv=relation->Rsv();
        if(relation->critical()) table->item(i,8)->setText("+");
        else table->item(i,8)->setText("-");
        line.critical=relation->critical();
        line.number=i;
        timetable->addLine(line);
    }

    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    return table;

}
