#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::getX()
{
    return ui->spinBox_X->value();
}

int Dialog::getY()
{
 return ui->spinBox_X->value();
}

int Dialog::getZ()
{
    return ui->spinBox_X->value();
}
