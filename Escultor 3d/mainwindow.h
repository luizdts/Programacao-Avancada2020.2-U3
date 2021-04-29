#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDialog>
#include "sculptor.h"
#include <cstdlib>
#include "plotter.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public slots:
    void abreDialogo(void);
    void salvar(void);
    void mudarPla(int _z);

    int getCorR();
    int getCorG(); // pegar as cores das paletas
    int getCorB();
    void cores();



    int getRaioElipseX();
    int getRaioElipseY();
    int getRaioElipseZ();
    int getRaioSphere();
    int getBox_X();
    int getBox_Y();
    int getBox_Z();

    void putVoxel();
    void cutVoxel();
    void putBox();
    void cutBox();
    void putElipse();
    void cutElipse();
    void putEsfera();
    void cutEsfera();




};
#endif // MAINWINDOW_H
