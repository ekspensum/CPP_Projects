#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(User *user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->user = user;
    ui->setupUi(this);
    ui->labelWhoLogin->setText("Zalogowany jako: " + this->user->getFirstName() + " " + this->user->getLastName());
}

MainWindow::~MainWindow()
{
    delete ui;
}
