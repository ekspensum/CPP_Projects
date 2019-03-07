#include "servicewindow.h"
#include "ui_servicewindow.h"

ServiceWindow::ServiceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServiceWindow)
{
    ui->setupUi(this);
}

ServiceWindow::ServiceWindow(User *user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServiceWindow)
{
    this->pUser = user;
    ui->setupUi(this);
    ui->labelWhoLogin->setText("Zalogowany jako: " + this->pUser->getFirstName() + " " + this->pUser->getLastName() + " rola: " + this->pUser->getRole());
    if(pUser->getRole() != "Admin")
        ui->settingTab->setDisabled(true);
    roleList.append("Wybierz");
    roleList.append("Admin");
    roleList.append("Operator");
    ui->comboBoxRole->addItems(roleList);
    usersList = mainLogin.readFileUsersList();

    connect(&net, SIGNAL(setProductsList()), this, SLOT(getProductsList()));
}

ServiceWindow::~ServiceWindow()
{
    delete ui;
}

void ServiceWindow::getProductsList()
{
    qDebug() << "List size " << net.getProductList().size();
    for (int i=0;i<net.getProductList().size(); i++) {
        qDebug() << net.getProductList().at(i)->getName() << net.getProductList().at(i)->getId();
    }
}

void ServiceWindow::on_pushButtonAddNewUser_clicked()
{
    bool validation = true;
        if (!valid.validLogin(ui->lineEditLogin->text())) {
            validation = false;
            msg.setText("Login zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
            msg.exec();
        }
        if (!valid.validPassword(ui->lineEditPassword->text())) {
            validation = false;
            msg.setText("Hasło zawiera niewłaściwą ilośc znaków!");
            msg.exec();
        }
        if(!valid.validName(ui->lineEditFirstName->text())){
            validation = false;
            msg.setText("Imię zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
            msg.exec();
        }
        if(!valid.validName(ui->lineEditLastName->text())){
            validation = false;
            msg.setText("Nazwisko zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
            msg.exec();
        }
        if (!valid.validEmail(ui->lineEditEmail->text())) {
            validation = false;
            msg.setText("Email zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
            msg.exec();
        }
        if (ui->comboBoxRole->currentText() == "Wybierz") {
            validation = false;
            msg.setText("Proszę wybrać rolę uzytkownika!");
            msg.exec();
        }
        if (validation) {
            pUser = new User();
            pUser->setIdUser(usersList.size());
            pUser->setLogin(ui->lineEditLogin->text());
            QByteArray passByteArray;
            QString passHash = QString(QCryptographicHash::hash(passByteArray.append(ui->lineEditPassword->text()), QCryptographicHash::Md5).toHex());
            pUser->setPassword(passHash);
            pUser->setFirstName(ui->lineEditFirstName->text());
            pUser->setLastName(ui->lineEditLastName->text());
            pUser->setEmail(ui->lineEditEmail->text());
            pUser->setRole(ui->comboBoxRole->currentText());
            usersList.append(pUser);
            if(mainLogin.createFileUsersList(usersList)){
                msg.setText("Dodano nowego użytkownika");
                msg.exec();
                ui->lineEditLogin->clear();
                ui->lineEditPassword->clear();
                ui->lineEditFirstName->clear();
                ui->lineEditLastName->clear();
                ui->lineEditEmail->clear();
                ui->comboBoxRole->setCurrentIndex(0);
            }
        }
}

void ServiceWindow::on_pushButton_clicked()
{
    net.getProcessors();
}

void ServiceWindow::on_pushButton_2_clicked()
{
    net.getDataJson();
}
