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
    ui->tabWidget->setStyleSheet("QTabWidget::pane > QWidget { background-color: #b8b8b8; }");
    ui->tableWidgetGet->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetUser->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->labelWhoLogin->setText("Zalogowany jako: " + this->pUser->getFirstName() + " " + this->pUser->getLastName() + " rola: " + this->pUser->getRole());
    usersList = mainLogin.readFileUsersList();
    if(pUser->getRole() != "Admin")
        ui->settingTab->setEnabled(false);
    roleList.append("Wybierz");
    roleList.append("Admin");
    roleList.append("Operator");
    ui->comboBoxRole->addItems(roleList);
    ui->comboBoxProductXml->addItem("Procesory", QVariant::fromValue(processorXmlList));
    ui->comboBoxProductXml->addItem("Dyski twarde", QVariant::fromValue(hardDisksXmlList));
    ui->comboBoxProductXml->addItem("Płyty główne", QVariant::fromValue(mainBoardsXmlList));
    ui->comboBoxProductXml->addItem("Pamięci RAM", QVariant::fromValue(ramMemoryXmlList));
    ui->comboBoxProductXml->addItem("Wszystkie produkty", QVariant::fromValue(allProductsXmlList));
    ui->comboBoxProductJson->addItem("Procesory", QVariant::fromValue(procesorsJson));
    ui->comboBoxProductJson->addItem("Dyski twarde", QVariant::fromValue(hardisksJson));
    ui->comboBoxProductJson->addItem("Płyty główne", QVariant::fromValue(mainBoardsJson));
    ui->comboBoxProductJson->addItem("Pamięci RAM", QVariant::fromValue(ramMemoryJson));
    ui->comboBoxProductJson->addItem("Wszystkie produkty", QVariant::fromValue(productsJson));
    ui->tableWidgetGet->verticalHeader()->close();
    ui->tableWidgetGet->setColumnWidth(0, 20);
    ui->tableWidgetGet->setColumnWidth(1, 80);
    ui->tableWidgetGet->setColumnWidth(2, 150);
    ui->tableWidgetGet->setColumnWidth(3, 300);
    ui->tableWidgetGet->setColumnWidth(4, 120);
    ui->tableWidgetGet->setColumnWidth(5, 100);
    ui->tableWidgetGet->setColumnWidth(6, 150);
    ui->tableWidgetUser->verticalHeader()->close();
    ui->tableWidgetUser->setColumnWidth(0, 20);
    ui->tableWidgetUser->setColumnWidth(1, 100);
    ui->tableWidgetUser->setColumnWidth(2, 120);
    ui->tableWidgetUser->setColumnWidth(3, 120);
    ui->tableWidgetUser->setColumnWidth(4, 150);
    ui->tableWidgetUser->setColumnWidth(5, 100);
    ui->lineEditProductIdFromXml->setText("0");
    ui->lineEditProductIdToXml->setText("100");
    ui->lineEditProductIdFromJson->setText("0");
    ui->lineEditProductIdToJson->setText("100");
    fillUserTable();
    connect(&net, SIGNAL(setProductsList()), this, SLOT(getProductsList()));
    connect(&net, SIGNAL(setProgressSignal(qint64, qint64)), this, SLOT(getProgressSignal(qint64, qint64)));
}

ServiceWindow::~ServiceWindow()
{
    delete ui;
}

void ServiceWindow::getProductsList()
{
    ui->tableWidgetGet->setRowCount(net.getProductList().size());
    for (int i=0;i<net.getProductList().size(); i++) {
        ui->tableWidgetGet->setItem(i, 0, new QTableWidgetItem(QString("%1").arg(net.getProductList().at(i)->getId())));
        ui->tableWidgetGet->setItem(i, 1, new QTableWidgetItem(QString("%1").arg(net.getProductList().at(i)->getIdProduct())));
        ui->tableWidgetGet->setItem(i, 2, new QTableWidgetItem(net.getProductList().at(i)->getName()));
        ui->tableWidgetGet->setItem(i, 3, new QTableWidgetItem(net.getProductList().at(i)->getDescription()));
        ui->tableWidgetGet->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(net.getProductList().at(i)->getUnitsInStock())));
        ui->tableWidgetGet->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(net.getProductList().at(i)->getPrice())));
        QPixmap image;
        image.loadFromData(QByteArray::fromBase64(net.getProductList().at(i)->getImage().toUtf8()));
        image = image.scaled(150, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QTableWidgetItem *imageItem = new QTableWidgetItem();
        imageItem->setData(Qt::DecorationRole ,image);
        ui->tableWidgetGet->setItem(i, 6, imageItem);
        ui->tableWidgetGet->setRowHeight(i, 100);
    }
}

void ServiceWindow::getProgressSignal(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBarGet->setRange(0, bytesTotal);
    ui->progressBarGet->setValue(bytesReceived);
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
            fillUserTable();
        }
    }
}

void ServiceWindow::on_pushButtonGetProductsXml_clicked()
{
    if (!ui->lineEditProductIdFromXml->text().isEmpty() && !ui->lineEditProductIdToXml->text().isEmpty()) {
        allProductsXmlPath = "/ShopAppWebService/rest/ShopResource/ProductsXml/"+ui->lineEditProductIdFromXml->text()+"/"+ui->lineEditProductIdToXml->text();
        allProductsXmlList = {QVariant::fromValue(allProductsXmlElement), QVariant::fromValue(allProductsXmlPath)};
        ui->comboBoxProductXml->setItemData(4, allProductsXmlList);
        net.getProductsXml(ui->comboBoxProductXml->itemData(ui->comboBoxProductXml->currentIndex()).toList().at(0).toString(), ui->comboBoxProductXml->itemData(ui->comboBoxProductXml->currentIndex()).toList().at(1).toString());
    } else {
        msg.setText("Proszę uzupełnić oba pola numerów Id !");
        msg.exec();
    }
}

void ServiceWindow::fillUserTable()
{
    ui->tableWidgetUser->setRowCount(usersList.size());
    for (int i=0;i<usersList.size();i++) {
        ui->tableWidgetUser->setItem(i, 0, new QTableWidgetItem(QString("%1").arg(mainLogin.readFileUsersList().at(i)->getIdUser())));
        ui->tableWidgetUser->setItem(i, 1, new QTableWidgetItem(usersList.at(i)->getLogin()));
        ui->tableWidgetUser->setItem(i, 2, new QTableWidgetItem(usersList.at(i)->getFirstName()));
        ui->tableWidgetUser->setItem(i, 3, new QTableWidgetItem(usersList.at(i)->getLastName()));
        ui->tableWidgetUser->setItem(i, 4, new QTableWidgetItem(usersList.at(i)->getEmail()));
        ui->tableWidgetUser->setItem(i, 5, new QTableWidgetItem(usersList.at(i)->getRole()));
    }
}

void ServiceWindow::on_pushButtonGetProductJson_clicked()
{
    if (!ui->lineEditProductIdFromJson->text().isEmpty() && !ui->lineEditProductIdToJson->text().isEmpty()) {
        productsJson = "/ShopAppWebService/rest/ShopResource/ProductsJson/"+ui->lineEditProductIdFromJson->text()+"/"+ui->lineEditProductIdToJson->text();
        ui->comboBoxProductJson->setItemData(4, productsJson);
        net.getProductsJson(ui->comboBoxProductJson->itemData(ui->comboBoxProductJson->currentIndex()).toString());
    } else {
        msg.setText("Proszę uzupełnić oba pola numerów Id !");
        msg.exec();
    }
}
