#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QtDebug>
#include <QtWidgets>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> actionNovo_Desenho,
            SIGNAL(triggered(bool)),
            this,
            SLOT(abreDialogo())
            );

    connect(ui->actionSalvar,
            SIGNAL(triggered(bool)),
            this,
            SLOT(salvar())
            );

    connect(ui-> AlterarCor,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cores())
            );

    connect(ui->actionplotVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(putVoxel())
            );
    connect(ui->actioncutVoxel,
                SIGNAL(triggered(bool)),
                this,
                SLOT(cutVoxel())
                );
    connect(ui->actionplotBox,
                SIGNAL(triggered(bool)),
                this,
                SLOT(putBox())
                );
    connect(ui->actioncutBox,
                SIGNAL(triggered(bool)),
                this,
                SLOT(cutBox())
                );
    connect(ui->actionplotElipse,
                SIGNAL(triggered(bool)),
                this,
                SLOT(putElipse())
                );
    connect(ui->actioncutElipse,
                SIGNAL(triggered(bool)),
                this,
                SLOT(cutElipse())
                );

    connect(ui->actionplotEsfera,
                SIGNAL(triggered(bool)),
                this,
                SLOT(putEsfera())
                );
    connect(ui->actioncutEsfera,
                SIGNAL(triggered(bool)),
                this,
                SLOT(cutEsfera())
                );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abreDialogo(){
    Dialog d;
    if(d.exec()==QDialog::Accepted){
           if(d.getX()!=0 && d.getY()!=0 && d.getZ()!=0){
               ui->widgetTela->mudaSculptor(d.getX(),d.getY(),d.getZ());
               ui->horizontalSlider_Planos->setMaximum(d.getZ());
               repaint();
           }else{
               QMessageBox::information(this, tr("Erro"),tr("\n Dimessões erradas!\n"));
           }
    }
}

void MainWindow::salvar()
{
    QString file=QFileDialog::getSaveFileName();
    file=file+".off";
    ui->widgetTela->s->writeOFF(file.toStdString().c_str());
}

void MainWindow::mudarPla(int _z)
{
    ui->widgetTela->mudaplano(_z);
}

int MainWindow::getCorR(){
    return ui->horizontalSlider_R->value();
}

int MainWindow::getCorG(){
    return ui->horizontalSlider_G->value();
}

int MainWindow::getCorB(){
    return ui->horizontalSlider_B->value();
}

void MainWindow::cores()
{
    ui->widgetTela->Novo_Colors(getCorR(),getCorG(),getCorB());
    repaint();
}

int MainWindow::getRaioElipseX(){
    return ui->horizontalSlider_X->value();
}

int MainWindow::getRaioElipseY(){
    return ui->horizontalSlider_Y->value();
}

int MainWindow::getRaioElipseZ(){
    return ui->horizontalSlider_Z->value();
}

int MainWindow::getRaioSphere()
{
    return ui->horizontalSlider_Raio->value();
}

int MainWindow::getBox_X()
{
     return ui->horizontalSlider_X->value();
}

int MainWindow::getBox_Z()
{
    return ui->horizontalSlider_Z->value();
}
int MainWindow::getBox_Y()
{
     return ui->horizontalSlider_Y->value();
}

void MainWindow::putVoxel(){
    ui->widgetTela->plot_PutVoxel();
    repaint();
}

void MainWindow::cutVoxel()
{
    ui->widgetTela->plot_CutVoxel();
    repaint();
}

void MainWindow::putBox()
{
    ui->widgetTela->Novo_PutBox(getBox_X(),getBox_Y(),getBox_Z());
    ui->widgetTela->plot_PutBox();
    repaint();
}

void MainWindow::cutBox()
{
    ui->widgetTela->Novo_PutBox(getBox_X(),getBox_Y(),getBox_Z());
    ui->widgetTela->plot_CutBox();
    repaint();
}

void MainWindow::putElipse(){
    ui->widgetTela->Novo_PutEllipsoid(getBox_X(),getBox_Y(),getBox_Z());
    ui->widgetTela->plot_PutEllipsoid();
    repaint();
}

void MainWindow::cutElipse(){
    ui->widgetTela->Novo_PutEllipsoid(getBox_X(),getBox_Y(),getBox_Z());
    ui->widgetTela->plot_CutEllipsoid();
    repaint();

}

void MainWindow::putEsfera(){
    ui->widgetTela->Novo_PutSphere(getRaioSphere());
    ui->widgetTela->plot_PutSphere();
    repaint();
    }

void MainWindow::cutEsfera(){
    ui->widgetTela->Novo_PutSphere(getRaioSphere());
    ui->widgetTela->plot_CutSphere();
    repaint();
    }


