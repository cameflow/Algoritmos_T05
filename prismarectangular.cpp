#include "prismarectangular.h"
#include "ui_prismarectangular.h"
#include <QMessageBox>
#include <math.h>

PrismaRectangular::PrismaRectangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaRectangular)
{
  //Se hace el setup de los valores en el constructor
  //Se mueve el canvas al centro de la pantalla y se guarda esa transformación
  centerX = width()/2;
  centerY = height()/2;
  QTransform center;
  center.translate(centerX,centerY);
  transforms.push_back(center);
  ui->setupUi(this);
}

PrismaRectangular::~PrismaRectangular()
{
  delete ui;
}

void PrismaRectangular::paintEvent(QPaintEvent *e)
{
  //Setup del painter
  QPainter painter(this);
  QPen pointPen(Qt::black);
  pointPen.setWidth(2);
  painter.setPen(pointPen);

  if(dibujaPrismaRectangular)
  {
    //Ciclo que se ejecuta el número de veces que hay transformaciones
    for(int i= 0;i<transforms.size();++i)
    {
      //Se le aplica una transformación al painter y luego se dibuja
      painter.setTransform(transforms[i],true);
      drawPrismRect(painter);
    }
  }
}

void PrismaRectangular::drawPrismRect(QPainter &painter)
{
 //Se ponen los puntos de las esquinas de un rectángulo
 int x0 = 0;
 int y0 = 50;
 int x1 = 50;
 int y1 = 50;
 int x2 = 0;
 int y2 = -100;
 int x3 = 50;
 int y3 = -100;
 //Se ponen los puntos de las esquinas de el otro rectángulo
 int x4 = x0+30;
 int y4 = y0-50;
 int x5 = x1+30;
 int y5 = y1-50;
 int x6 = x2+30;
 int y6 = y2-50;
 int x7 = x3+30;
 int y7 = y3-50;

 //Se dibujan los rectángulos
 painter.drawLine(x0,y0,x1,y1);
 painter.drawLine(x2,y2,x3,y3);
 painter.drawLine(x2,y2,x0,y0);
 painter.drawLine(x3,y3,x1,y1);
 painter.drawLine(x4,y4,x5,y5);
 painter.drawLine(x6,y6,x7,y7);
 painter.drawLine(x6,y6,x4,y4);
 painter.drawLine(x7,y7,x5,y5);
 //Se unen los rectángulos
 painter.drawLine(x0,y0,x4,y4);
 painter.drawLine(x1,y1,x5,y5);
 painter.drawLine(x2,y2,x6,y6);
 painter.drawLine(x3,y3,x7,y7);
}

void PrismaRectangular::on_pushButton_clicked()
{
  //Borra todo el vector de transformaciones
  //Es para darle reset al poligono
  //Vuelve a ajustar el centro
  dibujaPrismaRectangular = !dibujaPrismaRectangular;
  transforms.clear();
  QTransform center;
  center.translate(centerX,centerY);
  transforms.push_back(center);
  update();
}

void PrismaRectangular::on_pushButton_5_clicked()
{
  //Hace una rotación de 30 grados cada vez que se da click
  QTransform rotate;
  rotate.rotate(30);
  transforms.push_back(rotate);
  update();
}

void PrismaRectangular::on_pushButton_4_clicked()
{
  //Hace un Zoom In del doble del tamaño
  QTransform zoomIn;
  zoomIn.scale(2,2);
  transforms.push_back(zoomIn);
  update();
}

void PrismaRectangular::on_pushButton_3_clicked()
{
  //Hace un Zoom out de la mitad del tamaño
  QTransform zoomOut;
  zoomOut.scale(0.5,0.5);
  transforms.push_back(zoomOut);
  update();
}

void PrismaRectangular::on_pushButton_2_clicked()
{
  //Saca los valores de traslación de las textBox
  QString xStr = ui->transX->toPlainText();
  QString yStr = ui->transY->toPlainText();

  //checa si las textBox tenía datos
  if(!xStr.isEmpty() && !yStr.isEmpty())
  {
    //convierte los datos a int
    int _xStr = xStr.toInt();
    int _yStr = yStr.toInt();
    //Aplica la traslación
    QTransform translate;
    translate.translate(_xStr, _yStr);
    transforms.push_back(translate);;
  }
  else
  {
    QMessageBox msgBox;
    msgBox.setText("Ingrsa unos valores para la traslación");
    msgBox.exec();
  }
  update();
}

void PrismaRectangular::on_pushButton_6_clicked()
{
  //Aplica una reflección con respecto al eje horizontal
  QTransform reflect;
  reflect.scale(-1,1);
  transforms.push_back(reflect);
  update();
}

void PrismaRectangular::on_pushButton_7_clicked()
{
  //Aplica una reflección con respecto al eje vertical
  QTransform reflect;
  reflect.scale(1,-1);
  transforms.push_back(reflect);
  update();
}
