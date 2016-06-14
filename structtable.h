#ifndef STRUCTTABLE_H
#define STRUCTTABLE_H

#include <QWidget>

namespace Ui {
class StructTable;
}

struct Work {
    int number;
    QList<int> works;
    int time;
    int rank;
    QString text;
};

class StructTable : public QWidget
{
    Q_OBJECT
    
public:
    explicit StructTable(QWidget *parent = 0);
    ~StructTable();
    void table2Graph();

public slots:
    void makeTable();
    void sortTable();

signals:
    void toGraph(QList<Work>);
    
private:
    Ui::StructTable *ui;
};

#endif // STRUCTTABLE_H
