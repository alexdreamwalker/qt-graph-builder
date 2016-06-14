#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "node.h"
#include "relation.h"
#include "graph.h"
#include "structtable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Graph *graph;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void makeNodeOrder();

public slots:
    void addNode();
    void addRelation();
    void addRelationCustom(int from,int to);
    void makeAction();
    void makeSmile();
    void deleteNode();
    void findCritical();
    void showTable();
    void showStructMenu();
    void fromStructTable(QList<Work> works);
    void makeTimeTable();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
