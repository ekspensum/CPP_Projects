#include "mainwindow.h"
#include "ui_mainwindow.h"

//extern QString idZalogowanyUzytkownik; //zmienna globalna

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logowanie->setShortcut(QKeySequence(Qt::Key_Enter));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logowanie_clicked()
{

    QString login = ui->login->text();
    QString haslo = ui->haslo->text();
    if (login == NULL || haslo == NULL)
        ui->komunikat->setText("Proszę uzupełnić dane logowania");
    else {
        ObslugaBD bd;
        if (bd.logowanie(login, haslo))
        {
            ui->komunikat->setText("");
            w = new Wypozyczalnia();
            w->show();
            close();
            qDebug() << ObslugaBD::idZalogowanyUzytkownik;
        }
        else
            ui->komunikat->setText("Nie poprawny login lub hasło.");
    }
}
