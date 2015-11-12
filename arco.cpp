#include "arco.h"
#include "ui_arco.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

arco::arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arco)
{
  centerX = width()/2;
  centerY = height()/2;
  QTransform center;
  center.translate(centerX,centerY);
  transforms.push_back(center);
  ui->setupUi(this);
}


arco::~arco()
{
  delete ui;
}

void arco::paintEvent(QPaintEvent *e)
{
  //Setup del painter
  QPainter painter(this);
  QPen pointPen(Qt::black);
  pointPen.setWidth(2);
  painter.setPen(pointPen);

  if (dibujaArco)
  {
    //Saca el radio y el ángulo de las TextBox
    QString radioStr = ui->radioTxt->toPlainText();
    QString anguloStr = ui->angulosTxt->toPlainText();

    //Checa si hay valores en las TextBox
    if (!radioStr.isEmpty() && !anguloStr.isEmpty())
    {
      //Transforma el angulo y el radio al string
      angulo = anguloStr.toInt();
      radio = radioStr.toInt();
      for(int i=0; i<transforms.size(); ++i)
      {
        //Se ejecutan las transformaciones y luego se pinta
        painter.setTransform(transforms[i],true);
        drawArc(angulo, radio,painter);
     }
    }
  }
}

void arco::drawArc(int angulo, int radio, QPainter &painter)
{
  int x = 0;
  int y = radio;
  double p = 5.0/4.0-y;

  //centro de la ventana
  int maxx = 0;
  int maxy = 0;

  int oct = (angulo - (angulo % 45)) / 45;
  double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
  double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

  if (oct > 0 || (oct == 0 && y > limit1))
      painter.drawPoint(maxx+x,maxy-y);
  if (oct > 1 || (oct == 1 && y <= limit2))
      painter.drawPoint(maxx+y,maxy-x);
  if (oct > 2 || (oct == 2 && y > limit1))
      painter.drawPoint(maxx+y,maxy+x);
  if (oct > 3 || (oct == 3 && y <= limit2))
      painter.drawPoint(maxx+x,maxy+y);
  if (oct > 4 || (oct == 4 && y > limit1))
      painter.drawPoint(maxx-x,maxy+y);
  if (oct > 5 || (oct == 5 && y <= limit2))
      painter.drawPoint(maxx-y,maxy+x);
  if (oct > 6 || (oct == 6 && y > limit1))
      painter.drawPoint(maxx-y,maxy-x);
  if (oct > 7 || (oct == 7 && y <= limit2))
      painter.drawPoint(maxx-x,maxy-y);

  while(y > x)
  {
    if(p < 0)
    {
      p += 2.0 * x + 3.0;
    }
    else
    {
      p += 2.0 * (x - y) + 5.0;
      y--;
    }
    x++;

    //centro de la ventana
    int maxx = 0;
    int maxy = 0;

    int oct = (angulo - (angulo % 45)) / 45;
    double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
    double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

    if (oct > 0 || (oct == 0 && y > limit1))
        painter.drawPoint(maxx+x,maxy-y);
    if (oct > 1 || (oct == 1 && y <= limit2))
        painter.drawPoint(maxx+y,maxy-x);
    if (oct > 2 || (oct == 2 && y > limit1))
        painter.drawPoint(maxx+y,maxy+x);
    if (oct > 3 || (oct == 3 && y <= limit2))
        painter.drawPoint(maxx+x,maxy+y);
    if (oct > 4 || (oct == 4 && y > limit1))
        painter.drawPoint(maxx-x,maxy+y);
    if (oct > 5 || (oct == 5 && y <= limit2))
        painter.drawPoint(maxx-y,maxy+x);
    if (oct > 6 || (oct == 6 && y > limit1))
        painter.drawPoint(maxx-y,maxy-x);
    if (oct > 7 || (oct == 7 && y <= limit2))
        painter.drawPoint(maxx-x,maxy-y);
  }
}

void arco::on_pushButton_clicked()
{
  //Borra todo el vector de transformaciones
  //Es para darle reset al poligono
  //Vuelve a ajustar el centro
  QString r = ui->radioTxt->toPlainText();
  QString a = ui->angulosTxt->toPlainText();
  if(r.isEmpty() && a.isEmpty())
  {
    QMessageBox msgBox;
    msgBox.setText("Ingrsa el radio y el ángulo");
    msgBox.exec();
  }
  else if (r.isEmpty())
  {
    QMessageBox msgBox;
    msgBox.setText("Ingrsa el radio");
    msgBox.exec();
  }
  else if (a.isEmpty())
  {
    QMessageBox msgBox;
    msgBox.setText("Ingrsa el ángulo");
    msgBox.exec();
  }
  dibujaArco = !dibujaArco;
  transforms.clear();
  QTransform center;
  center.translate(centerX,centerY);
  transforms.push_back(center);
  update();
}

void arco::on_pushButton_5_clicked()
{
  //Hace una rotación de 30 grados cada vez que se da click
  QTransform rotate;
  rotate.rotate(30);
  transforms.push_back(rotate);
  update();
}

void arco::on_pushButton_4_clicked()
{
  //Hace un Zoom In del doble del tamaño
  QTransform zoomIn;
  zoomIn.scale(2,2);
  transforms.push_back(zoomIn);
  update();
}

void arco::on_pushButton_3_clicked()
{
  //Hace un Zoom In de la mitad del tamaño
  QTransform zoomOut;
  zoomOut.scale(0.5,0.5);
  transforms.push_back(zoomOut);
  update();
}

void arco::on_pushButton_2_clicked()
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

void arco::on_pushButton_6_clicked()
{
  //Aplica una reflección con respecto al eje horizontal
  QTransform reflect;
  reflect.scale(-1,1);
  transforms.push_back(reflect);
  update();
}

void arco::on_pushButton_7_clicked()
{
  //Aplica una reflección con respecto al eje vertical
  QTransform reflect;
  reflect.scale(1,-1);
  transforms.push_back(reflect);
  update();
}
