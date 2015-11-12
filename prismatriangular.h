#ifndef PRISMATRIANGULAR_H
#define PRISMATRIANGULAR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class prismaTriangular;
}

class prismaTriangular : public QDialog
{
    Q_OBJECT

public:
    explicit prismaTriangular(QWidget *parent = 0);
    ~prismaTriangular();

protected:
    void paintEvent(QPaintEvent *e);
    void drawPrismTriangle(QPainter & painter);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::prismaTriangular *ui;
    bool dibujaPrimsaTriangular = false;
    double centerX;
    double centerY;
    QVector<QTransform> transforms;
};

#endif // PRISMATRIANGULAR_H
