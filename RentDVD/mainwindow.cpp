#include "mainwindow.h"
#include "ui_mainwindow.h"

//extern QString idZalogowanyUzytkownik; //zmienna globalna

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logowanie->setShortcut(QKeySequence(Qt::Key_Return));
    regex.setPattern("^[a-zA-Z1-9]+$");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logowanie_clicked()
{

    QString login = ui->login->text();
    QString haslo = ui->haslo->text();
    match = regex.match(login);
    if (login == NULL || haslo == NULL)
        ui->komunikat->setText("Proszę uzupełnić dane logowania");
    else {
        ObslugaBD bd;
        if (bd.logowanie(login, haslo) && match.hasMatch())
        {
            ui->komunikat->setText("");
            w = new Wypozyczalnia();
            w->show();
            close();
        }
        else
            ui->komunikat->setText("Niepoprawny login lub hasło.");
    }
}
