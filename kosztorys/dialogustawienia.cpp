#include "dialogustawienia.h"
#include "ui_dialogustawienia.h"

DialogUstawienia::DialogUstawienia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUstawienia)
{
    ui->setupUi(this);
}

DialogUstawienia::~DialogUstawienia()
{
    delete ui;
}
