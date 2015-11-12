#include "prismatriangular.h"
#include "ui_prismatriangular.h"
#include <QMessageBox>
#include <math.h>

bool dibujaPrismaTriangular = false;

prismaTriangular::prismaTriangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prismaTriangular)
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


prismaTriangular::~prismaTriangular()
{
  delete ui;
}

void prismaTriangular::paintEvent(QPaintEvent *e)
{
  //Setup del painter
  QPainter painter(this);
  QPen pointPen(Qt::black);
  pointPen.setWidth(2);
  painter.setPen(pointPen);

  if(dibujaPrismaTriangular)
  {
    //Ciclo que se ejecuta el número de veces que hay transformaciones
    for(int i=0; i<transforms.size(); ++i)
    {
      //Se le aplica una transformación al painter y luego se dibuja
      painter.setTransform(transforms[i],true);
      drawPrismTriangle(painter);
    }
  }
}
void prismaTriangular::drawPrismTriangle(QPainter &painter)
{
  //Se ubican los puntos de los dos triángulos que son las bases
  int x1 = 0;
  int y1 = -50;
  int x2 = -25;
  int y2 = -70;
  int x3 = 25;
  int y3 = -70;
  int _x1 = 0;
  int _y1 = -50+50;
  int _x2 = -25;
  int _y2 = -70+50;
  int _x3 = 25;
  int _y3 = -70+50;

  //Se unen los triángulos con lineas
  painter.drawLine(x1,y1,x2,y2);
  painter.drawLine(x1,y1,x3,y3);
  painter.drawLine(x2,y2,x3,y3);
  painter.drawLine(_x1,_y1,_x2,_y2);
  painter.drawLine(_x1,_y1,_x3,_y3);
  painter.drawLine(_x2,_y2,_x3,_y3);
  painter.drawLine(x1,y1,_x1,_y1);
  painter.drawLine(x2,y2,_x2,_y2);
  painter.drawLine(_x3,_y3,x3,y3);
}

void prismaTriangular::on_pushButton_clicked()
{
  //Borra todo el vector de transformaciones
  //Es para darle reset al poligono
  //Vuelve a ajustar el centro
  dibujaPrismaTriangular = !dibujaPrismaTriangular;
  transforms.clear();
  QTransform center;
  center.translate(centerX,centerY);
  transforms.push_back(center);
  update();
}

void prismaTriangular::on_pushButton_5_clicked()
{
  //Hace una rotación de 30 grados cada vez que se da click
  QTransform rotate;
  rotate.rotate(30);
  transforms.push_back(rotate);
  update();
}

void prismaTriangular::on_pushButton_4_clicked()
{
  //Hace un Zoom out de la mitad del tamaño
  QTransform zoomIn;
  zoomIn.scale(2,2);
  transforms.push_back(zoomIn);
  update();
}

void prismaTriangular::on_pushButton_3_clicked()
{
  //Hace un Zoom In del doble del tamaño
  QTransform zoomOut;
  zoomOut.scale(0.5,0.5);
  transforms.push_back(zoomOut);
  update();
}

void prismaTriangular::on_pushButton_2_clicked()
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

void prismaTriangular::on_pushButton_6_clicked()
{
  //Aplica una reflección con respecto al eje horizontal
  QTransform reflect;
  reflect.scale(-1,1);
  transforms.push_back(reflect);
  update();
}

void prismaTriangular::on_pushButton_7_clicked()
{
  //Aplica una reflección con respecto al eje vertical
  QTransform reflect;
  reflect.scale(1,-1);
  transforms.push_back(reflect);
  update();
}
