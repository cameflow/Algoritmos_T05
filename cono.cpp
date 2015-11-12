#include "cono.h"
#include "ui_cono.h"
#include <QMessageBox>
#include <math.h>


bool dibujaCono = false;
cono::cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cono)
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


cono::~cono()
{
  delete ui;
}

void cono::paintEvent(QPaintEvent *e)
{
  //Setup del painter
  QPainter painter(this);
  QPen pointPen(Qt::black);
  pointPen.setWidth(2);
  painter.setPen(pointPen);

  //DibujaCubo
  if (dibujaCono)
  {
    //Ciclo que se ejecuta el número de veces que hay transformaciones
    for(int i=0; i<transforms.size(); ++i)
    {
      //Se le aplica una transformación al painter y luego se dibuja
      painter.setTransform(transforms[i],true);
      drawcone(painter);
    }
  }
}

void cono::drawcone(QPainter &painter)
{
  //Se pinta la elipse en el centro
  painter.drawEllipse(-25,-17,50,25);
  //Se sacan los puntos para la punta del cono
  int x1 = 0;
  int y1 = 40;
  //Se une los lados de la elipse con el punto del cono
  painter.drawLine(x1,y1,-25,0);
  painter.drawLine(x1,y1,25,0);
}

void cono::on_pushButton_clicked()
{
  //Borra todo el vector de transformaciones
  //Es para darle reset al poligono
  //Vuelve a ajustar el centro
  dibujaCono = !dibujaCono;
  transforms.clear();
  QTransform center;
  center.translate(centerX,centerY);
  transforms.push_back(center);
  update();
}

void cono::on_pushButton_5_clicked()
{
  //Hace una rotación de 30 grados cada vez que se da click
  QTransform rotate;
  rotate.rotate(30);
  transforms.push_back(rotate);
  update();
}

void cono::on_pushButton_4_clicked()
{
  //Hace un Zoom In del doble del tamaño
  QTransform zoomIn;
  zoomIn.scale(2,2);
  transforms.push_back(zoomIn);
  update();
}

void cono::on_pushButton_3_clicked()
{
  //Hace un Zoom out de la mitad del tamaño
  QTransform zoomOut;
  zoomOut.scale(0.5,0.5);
  transforms.push_back(zoomOut);
  update();
}

void cono::on_pushButton_2_clicked()
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
  else
  {
    QMessageBox msgBox;
    msgBox.setText("Ingrsa unos valores para la traslación");
    msgBox.exec();
  }
  update();
}

void cono::on_pushButton_7_clicked()
{
  //Aplica una reflección con respecto al eje vertical
  QTransform reflect;
  reflect.scale(1,-1);
  transforms.push_back(reflect);
  update();
}

void cono::on_pushButton_6_clicked()
{
  //Aplica una reflección con respecto al eje horizontal
  QTransform reflect;
  reflect.scale(-1,1);
  transforms.push_back(reflect);
  update();
}
