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
    arco(int _angulo, int _radio, int _translateArcoFactorX, int _translateArcoFactorY, double _scaleArcoFactor, int _rotateArcoAngle);
    ~arco();

protected:
    void paintEvent(QPaintEvent *e);
    void drawArc(int angulo, int radio, QPainter & painter);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

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
