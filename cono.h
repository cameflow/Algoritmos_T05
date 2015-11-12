#ifndef CONO_H
#define CONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class cono;
}

class cono : public QDialog
{
    Q_OBJECT

public:
    explicit cono(QWidget *parent = 0);
    ~cono();

  //Botonoes de la UI de el cono
private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();

protected:
    void paintEvent(QPaintEvent *e);//Función Para pintar
    void drawcone(QPainter & painter);//Función para pintar el cono

    //Variables que se van a necesitar
private:
    Ui::cono *ui;
    bool dibujaCono = false;
    double centerX;
    double centerY;
    QVector<QTransform> transforms;
};

#endif // CONO_H
