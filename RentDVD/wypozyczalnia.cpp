#include "wypozyczalnia.h"
#include "ui_wypozyczalnia.h"

Wypozyczalnia::Wypozyczalnia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wypozyczalnia)
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(4, false);
    if (ObslugaBD::idZalogowanyUzytkownik == "1")
        ui->tabWidget->setTabEnabled(4, true);
}

Wypozyczalnia::~Wypozyczalnia()
{
    delete ui;
}
