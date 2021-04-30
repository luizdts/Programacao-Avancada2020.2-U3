#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}
/**
 * @brief A classe Dialog é responsável por gerar a caixa de diálogo que captura as coordenadas da matriz.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    /**
     * @brief getX responsável por capturar o valor inserido na coordenada X da matriz.
     */
    int getX();// retorna o valor x da matriz
    /**
     * @brief getY responsável por capturar o valor inserido na coordenada Y da matriz.
     */
    int getY();// retorna o valor y de matriz
    /**
     * @brief getZ responsável por capturar o valor inserido na coordenada Z da matriz.
     */
    int getZ(); // retorna o valor z da matriz


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
