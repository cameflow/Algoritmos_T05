#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "poligono.h"
#include "arco.h"
#include "cubo.h"
#include "prismatriangular.h"
#include "prismarectangular.h"
#include "cono.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    printf("botón1\n");
    poligono poli;
    poli.setModal(true);
    poli.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    printf("botón2\n");
    arco arc;
    arc.setModal(true);
    arc.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    printf("botón3\n");
    cubo cu;
    cu.setModal(true);
    cu.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    printf("botón4\n");
    prismaTriangular prismaT;
    prismaT.setModal(true);
    prismaT.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    printf("botón5\n");
    PrismaRectangular prismaR;
    prismaR.setModal(true);
    prismaR.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    printf("botón6\n");
    cono co;
    co.setModal(true);
    co.exec();
}
