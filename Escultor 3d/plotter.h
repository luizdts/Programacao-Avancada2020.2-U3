#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QAction>
#include "sculptor.h"
#include <QMouseEvent>
#include <QString>
#include <QFileDialog>
/**
 * @brief O Plotter é responsável por desenhar a área da matriz.
 */

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
    /**
     * @brief mouseMoveEvent: função responsável pela movimentação do mouse.
     * @param event: ponteiro responsável por ativar a ação do mouse.
     */
    void mouseMoveEvent(QMouseEvent *event);
    /**
     * @brief mousePressEvent: função responsável pelo clique do mouse na tela.
     * @param event: ponteiro responsável por ativar a ação do mouse.
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * @brief mudaSculptor: altera o escultor.
     * @param s_x: coordenada em X.
     * @param s_y: coordenada em Y.
     * @param s_z: coordenada em Z.
     */
    void mudaSculptor(int s_x,int s_y, int s_z);
    /**
     * @brief mudaplano: altera o plano de visão.
     * @param _dz: coordenada em Z.
     */
    void mudaplano (int _dz);
    /**
     * @brief Novo_PutBox: adiciona uma nova caixa.
     * @param dx: coordenada em X.
     * @param dy: coordenada em Y.
     * @param dz: coordenada em Z.
     */
    void Novo_PutBox(int dx, int dy, int dz);
    /**
     * @brief Novo_PutSphere: adiciona uma nova esfera no plano.
     * @param r: raio da esfera
     */
    void Novo_PutSphere(int r);
    /**
     * @brief Novo_PutEllipsoid: adiciona uma nova elipse no plano.
     * @param _xraio: raio em X.
     * @param _yraio: raio em Y.
     * @param _zraio: raio em Z.
     */
    void Novo_PutEllipsoid(int _xraio, int _yraio, int _zraio);
    /**
     * @brief Novo_Colors: Adiciona uma cor de acordo com a paleta de cores.
     * @param corR: cor vermelha.
     * @param corG: cor verde.
     * @param corB: cor azul.
     */
    void Novo_Colors(float corR, float corG, float corB);
    /**
     * @brief plot_PutVoxel: Adiciona um novo Voxel para desenho.
     */
    void plot_PutVoxel();
    /**
     * @brief plot_CutVoxel: desativa o Voxel em uma determinada área do plano.
     */
    void plot_CutVoxel();
    /**
     * @brief plot_PutBox: Adiciona uma caixa em uma determinada área do plano.
     */
    void plot_PutBox();
    /**
     * @brief plot_CutBox: desativa o Voxel em uma determinada área do plano.
     */
    void plot_CutBox();
    /**
     * @brief plot_PutSphere: Adiciona uma esfera em uma determinada área do plano.
     */
    void plot_PutSphere();
    /**
     * @brief plot_CutSphere: desativa o Voxel em uma determinada área do plano.
     */
    void plot_CutSphere();
    /**
     * @brief plot_PutEllipsoid: Adiciona uma elipse em uma determinada área do plano.
     */
    void plot_PutEllipsoid();
    /**
     * @brief plot_CutEllipsoid: desativa o Voxel em uma determinada área do plano.
     */
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
