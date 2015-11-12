#ifndef POLIGONO_H
#define POLIGONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class poligono;
}

class poligono : public QDialog
{
    Q_OBJECT

public:
    explicit poligono(QWidget *parent = 0);
    ~poligono();

  //Variables que se van a utilizar en el programa
private:
    Ui::poligono *ui;
    bool dibujaPoli = false;
    double centerX;
    double centerY;
    int lados = 0;
    QVector<QTransform> transforms;


protected:
    void paintEvent(QPaintEvent *e); //Función que pinta
    void drawPoligono(int lados, QPainter & painter); //Función para hacer el poligono


    //Botones de la interfaz de el polígono
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};

#endif // POLIGONO_H
