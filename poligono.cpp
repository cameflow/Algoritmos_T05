#include "poligono.h"
#include "ui_poligono.h"
#include <QMessageBox>
#include <math.h>



poligono::poligono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::poligono)
{
    centerX = width()/2;
    centerY = height()/2;
    QTransform center;
    center.translate(centerX,centerY);
    transforms.push_back(center);
    ui->setupUi(this);
}

poligono::~poligono()
{
    delete ui;
}


void poligono::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);


    if (dibujaPoli) {

        QString ladosStr = ui->ladosPoliTxt->toPlainText();

        if (!ladosStr.isEmpty())
        {

           lados = ladosStr.toInt();


           for(int i=0; i<transforms.size(); ++i)
           {
               painter.setTransform(transforms[i],true);
               drawPoligono(lados, painter);
          }
        }
    }
}

void poligono::drawPoligono(int lados, QPainter & painter)
{
    double radio = 100;
    double angulo = (double)360.0/(double)lados;
    double xCentro = 0.0;
    double yCentro = 0.0;

    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;

    for(a=1; a<=lados; a++) {
        xi = xCentro + (radio * cos(angulo*a));
        yi = yCentro + (radio * sin(angulo*a));

        xf = xCentro + (radio * cos(angulo*(a+1)));
        yf = yCentro + (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);

    }
}



void poligono::on_pushButton_clicked()
{
    dibujaPoli=!dibujaPoli;
    transforms.clear();
    QTransform center;
    center.translate(centerX,centerY);
    transforms.push_back(center);
    update();
}

void poligono::on_pushButton_2_clicked()
{
    QTransform rotate;
    rotate.rotate(30);
    transforms.push_back(rotate);
    update();
}

void poligono::on_pushButton_3_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    transforms.push_back(zoomOut);
    update();
}

void poligono::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    transforms.push_back(zoomIn);
    update();
}

void poligono::on_pushButton_5_clicked()
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

void poligono::on_pushButton_6_clicked()
{
    QTransform reflect;
    reflect.scale(-1,1);
    transforms.push_back(reflect);
    update();
}

void poligono::on_pushButton_7_clicked()
{
    QTransform reflect;
    reflect.scale(1,-1);
    transforms.push_back(reflect);
    update();
}
