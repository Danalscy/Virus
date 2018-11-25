#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m = new Matrix;
    m->row=15;
    m->col=20;
    m->generuj(m,m->row,m->col);
    ui->setupUi(this);
    tableWcreate(m->row,m->col);
    tableWrefresh();
    setStyleSheet("MainWindow {background-image: url(\"leather-texture-cream.jpg\");}#widget{background-image: url(\"Untitled.jpg\");}");


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::tableWcreate(int r, int c){
    ui->tableWidget->setColumnCount(c);
    ui->tableWidget->setRowCount(r);
    for(int j=0;j<ui->tableWidget->columnCount();j++){
        for(int i=0;i<ui->tableWidget->rowCount();i++){
           ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }
}

void MainWindow::tableWrefresh(){
    int player=0, comp=0;
    for(int j=0;j<ui->tableWidget->columnCount();j++){
        for(int i=0;i<ui->tableWidget->rowCount();i++){

           switch(m->tab[i][j]){
           case 0:
           ui->tableWidget->item(i, j)->setBackground(QColor(170, 0, 0));
           break;
           case 1:
           ui->tableWidget->item(i, j)->setBackground(QColor(0, 85, 255));
           break;
           case 2:
           ui->tableWidget->item(i, j)->setBackground(QColor(0, 165, 0));
           break;
           case 3:
           ui->tableWidget->item(i, j)->setBackground(QColor(212, 171, 24));
           break;
           case 4:
           ui->tableWidget->item(i, j)->setBackground(QColor(132, 87, 131));
           break;
           }

           switch(m->visited[i][j]){
           case 0:
           break;
           case 1:
           ui->tableWidget->item(i, j)->setBackground(Qt::black);
           player++;
           break;
           case 2:
                ui->tableWidget->item(i, j)->setBackground(Qt::gray);
                comp++;
           break;
           }
}
    }
    ui->lcdNumber->display(player);
    ui->lcdNumber_2->display(comp);
}

void MainWindow::on_pushButton_clicked()
{
    if(m->tab[0][0]!=0){
    play(m, 0,1);
    tableWrefresh();
    play(m,m->compLogic(),2);
    tableWrefresh();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(m->tab[0][0]!=1){
    play(m, 1,1);
    tableWrefresh();
    play(m,m->compLogic(),2);
    tableWrefresh();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(m->tab[0][0]!=2){
    play(m, 2,1);
    tableWrefresh();
    play(m,m->compLogic(),2);
    tableWrefresh();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(m->tab[0][0]!=3){
    play(m, 3,1);
    tableWrefresh();
    play(m,m->compLogic(),2);
    tableWrefresh();
    }
}



void MainWindow::on_pushButton_5_clicked()
{
    if(m->tab[0][0]!=4){
    play(m, 4,1);
    tableWrefresh();
    play(m,m->compLogic(),2);
    tableWrefresh();
    }
}



void MainWindow::on_pushButton_6_clicked()
{
    m->deleteM(m);
    m->generuj(m,m->row,m->col);
    tableWrefresh();
}
