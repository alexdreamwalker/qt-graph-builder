#include "structtable.h"
#include "ui_structtable.h"
#include <QDebug>

StructTable::StructTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StructTable)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(makeTable()));
    QObject::connect(ui->commandLinkButton,SIGNAL(clicked()),this,SLOT(sortTable()));
}

StructTable::~StructTable()
{
    delete ui;
}

void StructTable::makeTable()
{
    int n = ui->spinBox->value();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<4;j++)
            ui->tableWidget->setItem(i,j, new QTableWidgetItem());
        ui->tableWidget->item(i,0)->setText(QString::number(i+1));
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void StructTable::table2Graph()
{
    QList<Work> works;
    works.clear();
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        Work work;
        work.number=ui->tableWidget->item(i,0)->text().toInt()-1;
        QStringList list = ui->tableWidget->item(i,1)->text().split(" ",QString::SkipEmptyParts);
        for(int j=0;j<list.count();j++) work.works.append(list.at(j).toInt()-1);
        work.time=ui->tableWidget->item(i,2)->text().toInt();
        work.rank=ui->tableWidget->item(i,3)->text().toInt();
        works.append(work);
    }

    emit toGraph(works);

}

void StructTable::sortTable()
{
    int n = ui->tableWidget->rowCount();
    Work works[n];
    for(int i=0;i<n;i++)
    {
        Work work;
        work.number=ui->tableWidget->item(i,0)->text().toInt();
        QStringList list = ui->tableWidget->item(i,1)->text().split(" ",QString::SkipEmptyParts);
        for(int j=0;j<list.count();j++) work.works.append(list.at(j).toInt());
        work.time=ui->tableWidget->item(i,2)->text().toInt();
        work.rank=1;
        works[i]=work;

    }

    int maxrank=0;

    for(int i=0;i<n;i++)
    {
        int max=0;
        for(int j=0;j<works[i].works.count();j++)
        {
            int number = works[i].works.at(j);
            if(works[number-1].rank>max) max=works[number-1].rank;
        }
        works[i].rank=max+1;
        if(max+1>maxrank) maxrank=max+1;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int currentRow=0;

    for(int i=1;i<maxrank+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(works[j].rank==i)
            {
                ui->tableWidget->insertRow(currentRow);
                ui->tableWidget->setItem(currentRow,0,new QTableWidgetItem(QString::number(currentRow+1)));
                QString items="";
                for(int z=0;z<works[j].works.count();z++) items = items+QString::number(works[j].works.at(z))+" ";
                ui->tableWidget->setItem(currentRow,1,new QTableWidgetItem(items));
                ui->tableWidget->setItem(currentRow,2,new QTableWidgetItem(QString::number(works[j].time)));
                ui->tableWidget->setItem(currentRow,3,new QTableWidgetItem(QString::number(works[j].rank)));
                currentRow++;
            }
        }
    }

    table2Graph();

}
