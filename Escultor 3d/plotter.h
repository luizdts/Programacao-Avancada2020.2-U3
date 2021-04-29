#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QAction>
#include "sculptor.h"
#include <QMouseEvent>
#include <QString>
#include <QFileDialog>


class Plotter : public QWidget
{
    Q_OBJECT
private:
    int verde, vermelho, azul, transp;
    int timeId;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    //void timerEvent(QTimerEvent *event);//paletas

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);


    void mudaSculptor(int s_x,int s_y, int s_z);
    void mudaplano (int _dz);

    void Novo_PutBox(int dx, int dy, int dz);
    void Novo_PutSphere(int r);
    void Novo_PutEllipsoid(int _xraio, int _yraio, int _zraio);
    void Novo_Colors(float corR, float corG, float corB);

    void plot_PutVoxel();
    void plot_CutVoxel();
    void plot_PutBox();
    void plot_CutBox();
    void plot_PutSphere();
    void plot_CutSphere();
    void plot_PutEllipsoid();
    void plot_CutEllipsoid();


    Sculptor *s;
        int dimx=0, dimy=0, dimz=0;//alter
        float r=0,g=0,b=0;
        int nx=30,ny=30,nz=30;
        int x1=0,y1=0,z1=0;
        int raioS=0;
        int xraio=0,yraio=0,zraio=0;

        bool putvoxel=false;
        bool cutvoxel=false;
        bool putbox=false;
        bool cutbox=false;
        bool putsphere=false;
        bool cutsphere=false;
        bool putellipsoid=false;
        bool cutellipsoid= false;

signals:

public slots:
};

#endif // PLOTTER_H
