#include "cono.h"
#include "ui_cono.h"
#include <QMessageBox>
#include <math.h>


bool dibujaCono = false;
cono::cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cono)
{
    centerX = width()/2;
    centerY = height()/2;
    QTransform center;
    center.translate(centerX,centerY);
    transforms.push_back(center);
    ui->setupUi(this);
}


cono::~cono()
{
    delete ui;
}

void cono::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    //DibujaCubo
    if (dibujaCono)
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            drawcone(painter);
        }
    }
}

void cono::drawcone(QPainter &painter)
{
    painter.drawEllipse(-25,-17,50,25);

    int x1 = 0;
    int y1 = 40;

    painter.drawLine(x1,y1,-25,0);
    painter.drawLine(x1,y1,25,0);
}

void cono::on_pushButton_clicked()
{
    dibujaCono = !dibujaCono;
    transforms.clear();
    QTransform center;
    center.translate(centerX,centerY);
    transforms.push_back(center);
    update();
}

void cono::on_pushButton_5_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void cono::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void cono::on_pushButton_3_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);
    update();
}

void cono::on_pushButton_2_clicked()
{
    QString xStr = ui->transX->toPlainText();
    QString yStr = ui->transY->toPlainText();

    if(!xStr.isEmpty() && !yStr.isEmpty())
    {
        int _xStr = xStr.toInt();
        int _yStr = yStr.toInt();
        QTransform translate;
        translate.translate(_xStr, _yStr);
        transforms.push_back(translate);

    }
    update();
}

void cono::on_pushButton_7_clicked()
{
    QTransform reflect;
    reflect.scale(1,-1);
    transforms.push_back(reflect);
    update();
}

void cono::on_pushButton_6_clicked()
{
    QTransform reflect;
    reflect.scale(-1,1);
    transforms.push_back(reflect);
    update();
}
