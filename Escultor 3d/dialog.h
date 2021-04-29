#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int getX();// retorna o valor x da matriz
    int getY();// retorna o valor y de matriz
    int getZ(); // retorna o valor z da matriz


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
