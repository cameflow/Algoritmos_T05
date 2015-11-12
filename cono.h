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

private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

protected:
    void paintEvent(QPaintEvent *e);
    void drawcone(QPainter & painter);

private:
    Ui::cono *ui;
    bool dibujaCono = false;
    double centerX;
    double centerY;
    QVector<QTransform> transforms;
};

#endif // CONO_H
