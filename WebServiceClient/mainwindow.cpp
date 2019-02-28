#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QList<User *> list;
    User user;
    User *pUser = &user;
    pUser->setLogin("login1");
    pUser->setPassword("pass1");
    pUser->setFirstName("FirstName1");
    pUser->setLastName("LastName1");
    pUser->setEmail("e-mail1");
    pUser->setIdUser(0);

    list.append(pUser);

    User usr2;
    User *pUser2 = &usr2;
    pUser2->setLogin("login2");
    pUser2->setPassword("pass2");
    pUser2->setFirstName("FirstName2");
    pUser2->setLastName("LastName2");
    pUser2->setEmail("e-mail2");
    pUser2->setIdUser(1);

    list.append(pUser2);

    login->createFileUsersList(list);

    list = login->readFileUsersList();
    qDebug() << list.at(0)->getFirstName();
    qDebug() << list.at(1)->getFirstName();
}


