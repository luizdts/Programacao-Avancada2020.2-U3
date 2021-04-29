#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

class Sculptor{
protected:
    Voxel ***v; //ponteiro pra armazenar as dimensões da matriz de voxel
    int nx; // tamanho dimensão em x
    int ny;// tamanho dimensão em y
    int nz; // tamanho dimensão em z

    float r; //variavl para a cor vermelho
    float g; //variavel para a cor verde
    float  b; // variavel para a cor azul
    float a; // variavel para a transparencia


public:
    Sculptor(int _nx, int _ny, int _nz); //construtor da classe Sculptor
    ~Sculptor(); // destrutor da classe Sculptor
    void setCor(float r, float g, float b, float a); //metodo que atribui cor ao voxel

    void putVoxel(int x, int y, int z);// ativa o voxel
    void cutVoxel(int x, int y, int z); // desativa o voxel no intervalor

    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);// ativa todos os voxels  em um determinada intervalo
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);// desativa todos os voxels em um determinado intervalo

    void putSphere(int xcenter, int ycenter, int zcenter, int radius);// gera uma espera
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);//cortar uma figura

     void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // gera uma elipse
     void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);// corta uma elipse

     bool getis0n(int x, int y, int z); // verifica se uma determinar posição está com isno ativo

     float getR (int i, int j, int k); // retornar a cor vermelha
     float getG (int i, int j, int k);// retornar a cor  verde
     float getB (int i, int j, int k);// retornar a cor azul

     void writeOFF( const char* filename);// metodo para salvar arquivo off
};

#endif // SCULPTOR_H
