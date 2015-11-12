#include "cubo.h"
#include "ui_cubo.h"
#include <QMessageBox>
#include <math.h>



cubo::cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cubo)
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


cubo::~cubo()
{
   delete ui;
}

void cubo::paintEvent(QPaintEvent *e)
{
  //Setup del painter
  QPainter painter(this);
  QPen pointPen(Qt::black);
  pointPen.setWidth(2);
  painter.setPen(pointPen);

  if (dibujacubo)
  {
    //Ciclo que se ejecuta el número de veces que hay transformaciones
    for(int i=0; i<transforms.size(); ++i)
    {
      //Se le aplica una transformación al painter y luego se dibuja
      painter.setTransform(transforms[i],true);
      drawCube(painter);
    }
  }
}

void cubo::drawCube(QPainter &painter)
{
  //Pone los puntos de los dos cuadrados
  int x1 = -25;
  int y1 = 25;
  int x2 = 25;
  int y2 = 25;
  int x3 = -25;
  int y3 = -25;
  int x4 = 25;
  int y4 = -25;
  int distProp = (x2-x1)/2;
  int _x1 = x1+distProp;
  int _y1 = y1-distProp;
  int _x2 = x2+distProp;
  int _y2 = y2-distProp;
  int _x3 = x3+distProp;
  int _y3 = y3-distProp;
  int _x4 = x4+distProp;
  int _y4 = y4-distProp;

  //Pone las lineas entre los dos cuadrados
  painter.drawLine(x1, y1, x2, y2);
  painter.drawLine(x1, y1, x3, y3);
  painter.drawLine(x2, y2, x4, y4);
  painter.drawLine(x3, y3, x4, y4);
  painter.drawLine(_x1, _y1, _x2, _y2);
  painter.drawLine(_x1, _y1, _x3, _y3);
  painter.drawLine(_x2, _y2, _x4, _y4);
  painter.drawLine(_x3, _y3, _x4, _y4);
  painter.drawLine(x1, y1, _x1, _y1);
  painter.drawLine(x2, y2, _x2, _y2);
  painter.drawLine(x3, y3, _x3, _y3);
  painter.drawLine(x4, y4, _x4, _y4);
}

void cubo::on_pushButton_clicked()
{
  //Borra todo el vector de transformaciones
  //Es para darle reset al poligono
  //Vuelve a ajustar el centro
  transforms.clear();
  QTransform center;
  center.translate(centerX,centerY);
  transforms.push_back(center);
  dibujacubo = !dibujacubo;
  update();
}

void cubo::on_pushButton_2_clicked()
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
    transforms.push_back(translate);
  }
  update();
}

void cubo::on_pushButton_3_clicked()
{
  //Hace un Zoom out de la mitad del tamaño
  QTransform zoomOut;
  zoomOut.scale(0.5,0.5);
  transforms.push_back(zoomOut);
  update();
}

void cubo::on_pushButton_4_clicked()
{
  //Hace un Zoom In del doble del tamaño
  QTransform zoomIn;
  zoomIn.scale(2,2);
  transforms.push_back(zoomIn);
  update();
}

void cubo::on_pushButton_5_clicked()
{
  //Hace una rotación de 30 grados cada vez que se da click
  QTransform rotate;
  rotate.rotate(30);
  transforms.push_back(rotate);
  update();

}

void cubo::on_pushButton_6_clicked()
{
  //Aplica una reflección con respecto al eje horizontal
  QTransform reflect;
  reflect.scale(-1,1);
  transforms.push_back(reflect);
  update();
}

void cubo::on_pushButton_7_clicked()
{
  //Aplica una reflección con respecto al eje vertical
  QTransform reflect;
  reflect.scale(1,-1);
  transforms.push_back(reflect);
  update();
}
