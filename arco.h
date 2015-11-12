#ifndef ARCO_H
#define ARCO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>


namespace Ui {
class arco;
}

class arco : public QDialog
{
    Q_OBJECT

public:
    explicit arco(QWidget *parent = 0);
    ~arco();

protected:
    void paintEvent(QPaintEvent *e); //Función Para pintar
    void drawArc(int angulo, int radio, QPainter & painter); //Función para pintar el arco

    //Botonoes de la UI de el árco
private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

    //Variables que se van a necesitar
private:
    Ui::arco *ui;
    bool dibujaArco = false;
    double centerX;
    double centerY;
    int angulo = 0;
    int radio = 0;
    QVector<QTransform> transforms;

};

#endif // ARCO_H
