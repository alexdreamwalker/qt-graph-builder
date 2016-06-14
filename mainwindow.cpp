#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include "timetable.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    graph = new Graph();
    scene->addItem(graph);
    QObject::connect(ui->btn_newnode,SIGNAL(clicked()),this,SLOT(addNode()));
    QObject::connect(ui->btn_addrelation,SIGNAL(clicked()),this,SLOT(addRelation()));
    QObject::connect(ui->btn_delete,SIGNAL(clicked()),this,SLOT(deleteNode()));
    QObject::connect(ui->btn_findCritical,SIGNAL(clicked()),this,SLOT(findCritical()));
    QObject::connect(ui->btn_makeTable,SIGNAL(clicked()),this,SLOT(showTable()));
    QObject::connect(ui->readmenu,SIGNAL(triggered()),this,SLOT(showStructMenu()));
    QObject::connect(ui->btn_makePlot,SIGNAL(clicked()),this,SLOT(makeTimeTable()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{
    Node *node = new Node(graph);
    node->setNumber(graph->nodes.size());
    graph->nodes.append(node);
}

void MainWindow::addRelation()
{
    int from = ui->sb_from->value();
    int to = ui->sb_to->value();
    Relation *relation = new Relation(graph);
    relation->setRelation(graph->nodes.at(from),graph->nodes.at(to));
    relation->setLength(ui->le_length->text().toFloat());
    relation->setNumber(graph->relations.size());
    relation->setFake(ui->chb_isFake->isChecked());
    graph->nodeAt(from)->outItems.append(graph->nodeAt(to));
    graph->nodeAt(to)->inItems.append(graph->nodeAt(from));
    //graph->nodeAt(to)->setPos(graph->nodeAt(from)->pos().x()+30,graph->nodeAt(from)->pos().y()+30);
    graph->relations.append(relation);
    ui->graphicsView->update();
}

void MainWindow::addRelationCustom(int from, int to)
{
    Relation *relation = new Relation(graph);
    relation->setRelation(graph->nodes.at(from),graph->nodes.at(to));
    relation->setLength(ui->le_length->text().toFloat());
    relation->setNumber(graph->relations.size());
    relation->setFake(ui->chb_isFake->isChecked());
    graph->nodeAt(from)->outItems.append(graph->nodeAt(to));
    graph->nodeAt(to)->inItems.append(graph->nodeAt(from));
    graph->relations.append(relation);
    ui->graphicsView->update();
}

void MainWindow::makeAction()
{

}

void MainWindow::makeSmile()
{

}

void MainWindow::deleteNode()
{
    int index = ui->sb_delete->value();
    graph->nodeAt(index)->setDeleted(true);
    ui->graphicsView->update();
}

void MainWindow::findCritical()
{
    graph->findCritical();
    ui->le_minlength->setText(QString::number(graph->_minLength));
    ui->graphicsView->update();
}

void MainWindow::showTable()
{
    TimeTable *ttable = new TimeTable();
    graph->timetable=ttable;
    QTableWidget *table = graph->makeTable();
    view = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene();
    view->setScene(scene);
    view->scene()->addItem(ttable);
    //view->scale(1.0,-1.0);
    view->hide();
    table->show();
}

void MainWindow::showStructMenu()
{
    StructTable *table = new StructTable();
    table->show();
    QObject::connect(table,SIGNAL(toGraph(QList<Work>)),this,SLOT(fromStructTable(QList<Work>)));
}

void MainWindow::makeNodeOrder()
{

}

void MainWindow::fromStructTable(QList<Work> works)
{
    addNode();

    for(int i=0;i<works.count();i++)
    {
        Work work = works.at(i);

        if(work.rank==1)
        {
            addNode();
            int to = graph->nodes.count()-1;
            graph->nodeAt(to)->setShortTime(work.time);
            graph->nodeAt(to)->setPos(work.time*10,qrand()%300);
            addRelationCustom(0,to);
            graph->relations.at(graph->relations.count()-1)->setLength(work.time);
        }
        else
        {
            int lastime=0;
            int lastwork=0;
            for(int z=0;z<work.works.count();z++)
                if(works.at(work.works.at(z)).rank==work.rank-1)
                {
                    if(works.at(work.works.at(z)).time>lastime) {
                        lastime = works.at(work.works.at(z)).time;
                        lastwork = work.works.at(z);
                    }
                }
            addNode();
            int to = graph->nodes.count()-1;
            addRelationCustom(graph->relations.at(lastwork)->_to->number(),to);
            graph->nodeAt(to)->setShortTime(graph->nodeAt(graph->relations.at(lastwork)->_to->number())->shortTime()+work.time);
            graph->nodeAt(to)->setPos(graph->nodeAt(graph->relations.at(lastwork)->_to->number())->shortTime()*10,qrand()%300);
            graph->relations.at(graph->relations.count()-1)->setLength(work.time);
            for(int z=0;z<work.works.count();z++)
                if(work.works.at(z)!=lastwork) {
                    int from = work.works.at(z);
                    addRelationCustom(graph->relations.at(from)->_to->number(),graph->relations.at(lastwork)->_to->number());
                    graph->relations.at(graph->relations.count()-1)->setLength(work.time);
                    graph->relations.at(graph->relations.count()-1)->setFake(true);
                }

        }
        graph->nodeAt(graph->nodes.count()-1)->setRank(work.rank);
    }

    //makeNodeOrder();
}


void MainWindow::makeTimeTable()
{
    view->show();
}
