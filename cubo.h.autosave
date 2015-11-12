#ifndef CUBO_H
#define CUBO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class cubo;
}

class cubo : public QDialog
{
    Q_OBJECT

public:
    explicit cubo(QWidget *parent = 0);
    ~cubo();

  //Variables que se van a utilizar en el programa
private:
    Ui::cubo *ui;
    bool dibujacubo = false;
    double centerX;
    double centerY;
    QVector<QTransform> transforms;


protected:
    void paintEvent(QPaintEvent *e);  //Función que pinta
    void drawCube(QPainter & painter);//Función para hacer el cubo

    //Botones de la interfaz de el cubo
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};

#endif // CUBO_H
