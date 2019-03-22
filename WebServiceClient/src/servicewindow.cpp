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
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setStyleSheet("QTabWidget::pane > QWidget { background-color: #b8b8b8; }");
    ui->tableWidgetGet->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetUser->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->lineEditProductName->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->textEditProductDescription->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
    ui->tableWidgetPut->setStyleSheet("QWidget::pane > QWidget { background-color: #C3C3AE; }");
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
    ui->tableWidgetGet->setColumnWidth(3, 540);
    ui->tableWidgetGet->setColumnWidth(4, 60);
    ui->tableWidgetGet->setColumnWidth(5, 60);
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
    ui->tableWidgetPut->verticalHeader()->close();
    ui->tableWidgetPut->setColumnWidth(0, 15);
    ui->tableWidgetPut->setColumnWidth(1, 15);
    ui->tableWidgetPut->setColumnWidth(2, 140);
    ui->tableWidgetPut->setColumnWidth(3, 330);
    ui->tableWidgetPut->setColumnWidth(4, 50);
    ui->tableWidgetPut->setColumnWidth(5, 60);
    ui->tableWidgetPut->setColumnWidth(6, 150);
    ui->tableWidgetPut->setColumnWidth(7, 100);
    ui->tableWidgetPut->setColumnWidth(8, 180);
    connect(&net, SIGNAL(setProductsList()), this, SLOT(getProductsList()));
    connect(&net, SIGNAL(setProgressSignal(qint64, qint64)), this, SLOT(getProgressSignal(qint64, qint64)));
    connect(&net, SIGNAL(setCategoryList()), this, SLOT(getCategoryList()));
    connect(&net, SIGNAL(setAddProductAnswer(QString)), this, SLOT(getAddProductAnswer(QString)));
    connect(&net, SIGNAL(setUpdateProductAnswer(QString)), this, SLOT(getUpdateProductAnswer(QString)));
    net.getCategoryJson("/ShopAppWebService/rest/ShopResource/AllCategoryJson");
    connect(&net, SIGNAL(findProductList()), this, SLOT(findProductList()));
}

ServiceWindow::~ServiceWindow()
{
    delete ui;
    delete pProduct;
    delete comboCategory1;
    delete comboCategory2;
    delete pUser;
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

void ServiceWindow::getCategoryList()
{
    for(int i=0; i<net.getCategoryList().size(); i++){
        ui->comboBoxCategory1->addItem(net.getCategoryList().at(i)->getName(), QVariant::fromValue(net.getCategoryList().at(i)->getId()));
        ui->comboBoxCategory2->addItem(net.getCategoryList().at(i)->getName(), QVariant::fromValue(net.getCategoryList().at(i)->getId()));
    }
}

void ServiceWindow::getAddProductAnswer(QString str)
{
    msg.setText(str);
    msg.exec();
}

void ServiceWindow::getUpdateProductAnswer(QString str)
{
    msg.setText(str);
    msg.exec();
}

void ServiceWindow::getProgressSignal(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBarGet->setRange(0, static_cast<int>(bytesTotal));
    ui->progressBarGet->setValue(static_cast<int>(bytesReceived));
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
        msg.setText("Proszę wybrać rolę użytkownika!");
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

void ServiceWindow::on_pushButtonSelectImageFilePost_clicked()
{
    fileImagePathPost = QFileDialog::getOpenFileName(this, "Wybierz plik", QDir::homePath(), "Plik jpg (*.jpg);; Plik png(*.png);; Wszystkie pliki (*.*)");
    QFile fileImage(fileImagePathPost);
    if(!fileImage.open(QIODevice::ReadOnly)){
        msg.setText("Błąd otwarcia pliku!");
        msg.exec();
        return;
    }
    QFileInfo fileInfo(fileImagePathPost);
    if(fileInfo.size() > 600000){
        msg.setText("Rozmiar pliku to "+QString("%1").arg(fileInfo.size()/1000)+"kB i jest powyżej 600kB. Proszę wybrać mniejszy plik!");
        msg.exec();
        return;
    }
    byteFileImagePost = fileImage.readAll();
    ui->lineEditFileNamePost->setText(fileInfo.fileName());
}

void ServiceWindow::on_commandLinkButtonAddProduct_clicked()
{
    bool validation = true;
    if(pUser->getRole() != "Operator"){
        validation = false;
        msg.setText("Obecnie zalogowany użytkowanik nie ma uprawnień do tej akcji!");
        msg.exec();
        return;
    }
    if(!valid.validProductName(ui->lineEditProductName->text())){
        validation = false;
        msg.setText("Nazwa produktu zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
        msg.exec();
    }
    if(!valid.validProductDescription(ui->textEditProductDescription->toPlainText())){
        validation = false;
        msg.setText("Opis produktu zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
        msg.exec();
    }
    if(ui->spinBoxUnitsInStock->value() == 0){
        validation = false;
        msg.setText("Ilość produktu jest zerowa!");
        msg.exec();
    }
    if(ui->doubleSpinBoxPrice->value() == 0.00){
        validation = false;
        msg.setText("Cena produktu jest zerowa!");
        msg.exec();
    }
    if (ui->comboBoxCategory1->currentIndex() == 0) {
        validation = false;
        msg.setText("Proszę wybrać kategorie nr 1!");
        msg.exec();
    }
    if (ui->comboBoxCategory1->currentText() == ui->comboBoxCategory2->currentText()) {
        validation = false;
        msg.setText("Kategoria nr 1 jest taka sama jak kategoria nr 2!");
        msg.exec();
    }
    if(byteFileImagePost.size() == 0){
        validation = false;
        msg.setText("Nie dodano zdjęcia produktu!");
        msg.exec();
    }
    if (validation) {
        pProduct = new Product();
        pProduct->setName(ui->lineEditProductName->text());
        pProduct->setDescription(ui->textEditProductDescription->toPlainText());
        pProduct->setPrice(ui->doubleSpinBoxPrice->value());
        pProduct->setUnitsInStock(ui->spinBoxUnitsInStock->value());
        pProduct->setCategory1Id(ui->comboBoxCategory1->itemData(ui->comboBoxCategory1->currentIndex()).toInt());
        pProduct->setCategory2Id(ui->comboBoxCategory2->itemData(ui->comboBoxCategory2->currentIndex()).toInt());
        pProduct->setImage(byteFileImagePost.toBase64());
        if(net.addProductJson("/ShopAppWebService/rest/ShopResource/ProductAddJson", pProduct, pUser)){
            ui->lineEditProductName->clear();
            ui->textEditProductDescription->clear();
            ui->doubleSpinBoxPrice->setValue(0);
            ui->spinBoxUnitsInStock->setValue(0);
            ui->comboBoxCategory1->setCurrentIndex(0);
            ui->comboBoxCategory2->setCurrentIndex(0);
            ui->lineEditFileNamePost->clear();
            byteFileImagePost.clear();
        }
    }
}

void ServiceWindow::findProductList()
{
    previousCategory1IdList.clear();
    previousCategory2IdList.clear();
    ui->tableWidgetPut->setRowCount(net.getProductList().size());
    for (int i=0;i<net.getProductList().size(); i++) {
        ui->tableWidgetPut->setItem(i, 0, new QTableWidgetItem(QString("%1").arg(net.getProductList().at(i)->getId())));
        ui->tableWidgetPut->item(i, 0)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetPut->setItem(i, 1, new QTableWidgetItem(QString("%1").arg(net.getProductList().at(i)->getIdProduct())));
        ui->tableWidgetPut->item(i, 1)->setFlags(Qt::ItemIsEditable);
        ui->tableWidgetPut->setItem(i, 2, new QTableWidgetItem(net.getProductList().at(i)->getName()));
        ui->tableWidgetPut->setItem(i, 3, new QTableWidgetItem(net.getProductList().at(i)->getDescription()));

        QSpinBox *spinBox = new QSpinBox();
        spinBox->setFixedSize(50, 25);
        spinBox->setRange(0, 1000);
        spinBox->setValue(net.getProductList().at(i)->getUnitsInStock());
        ui->tableWidgetPut->setCellWidget(i, 4, spinBox);

        QDoubleSpinBox *doubleBox = new QDoubleSpinBox();
        doubleBox->setFixedSize(60, 25);
        doubleBox->setRange(0.00, 99999.99);
        doubleBox->setValue(net.getProductList().at(i)->getPrice());
        ui->tableWidgetPut->setCellWidget(i, 5, doubleBox);

        QPixmap image;
        image.loadFromData(QByteArray::fromBase64(net.getProductList().at(i)->getImage().toUtf8()));
        image = image.scaled(150, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QTableWidgetItem *imageItem = new QTableWidgetItem();
        imageItem->setData(Qt::DecorationRole ,image);
        ui->tableWidgetPut->setItem(i, 6, imageItem);
        ui->tableWidgetPut->setRowHeight(i, 100);

        comboCategory1 = new QComboBox();
        comboCategory1->setFixedSize(100, 25);
        comboCategory2 = new QComboBox();
        comboCategory2->setFixedSize(180, 25);
        for (int j=0;j<net.getCategoryList().size();j++) {
            comboCategory1->addItem(net.getCategoryList().at(j)->getName(), QVariant::fromValue(net.getCategoryList().at(j)->getId()));
            if(net.getCategoryList().at(j)->getId() == net.getProductList().at(i)->getCategory1Id()){
                comboCategory1->setCurrentText(net.getCategoryList().at(j)->getName());
                previousCategory1IdList.append(net.getCategoryList().at(j)->getId());
            }
            comboCategory2->addItem(net.getCategoryList().at(j)->getName(), QVariant::fromValue(net.getCategoryList().at(j)->getId()));
            if(net.getCategoryList().at(j)->getId() == net.getProductList().at(i)->getCategory2Id()){
                comboCategory2->setCurrentText(net.getCategoryList().at(j)->getName());
                previousCategory2IdList.append(net.getCategoryList().at(j)->getId());
            }
        }
        ui->tableWidgetPut->setCellWidget(i, 7, comboCategory1);
        ui->tableWidgetPut->setCellWidget(i, 8, comboCategory2);
    }
}

void ServiceWindow::on_pushButtonFindProduct_clicked()
{
    if (!ui->lineEditFindProductName->text().isEmpty()) {
        productsJson = "/ShopAppWebService/rest/ShopResource/ProductsByNameJson/"+ui->lineEditFindProductName->text();
        net.findProductJson(productsJson);
    } else {
        msg.setText("Proszę uzupełnić pole wyszukiwania!");
        msg.exec();
    }
}

void ServiceWindow::on_commandLinkButtonUpdateProduct_clicked()
{
    if(ui->tableWidgetPut->selectedRanges().size() != 1){
        msg.setText("Powinien być zaznaczony jeden wiersz do edycji!");
        msg.exec();
        return;
    }
    int currentRow = ui->tableWidgetPut->currentRow();
    bool validation = true;
    if(pUser->getRole() != "Operator"){
        validation = false;
        msg.setText("Obecnie zalogowany użytkowanik nie ma uprawnień do tej akcji!");
        msg.exec();
        return;
    }
    if(!valid.validProductName(ui->tableWidgetPut->item(currentRow, 2)->text())){
        validation = false;
        msg.setText("Nazwa produktu zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
        msg.exec();
    }
    if(!valid.validProductDescription(ui->tableWidgetPut->item(currentRow, 3)->text())){
        validation = false;
        msg.setText("Opis produktu zawiera niepoprawne znaki lub niewłaściwą ilośc znaków!");
        msg.exec();
    }
    QSpinBox *spinBox = dynamic_cast<QSpinBox *>(ui->tableWidgetPut->cellWidget(currentRow, 4));
    if(spinBox->value() == 0){
        validation = false;
        msg.setText("Ilość produktu jest zerowa!");
        msg.exec();
    }
    QDoubleSpinBox *doubleBox = dynamic_cast<QDoubleSpinBox *>(ui->tableWidgetPut->cellWidget(currentRow, 5));
    if(doubleBox->value() == 0.00){
        validation = false;
        msg.setText("Cena produktu jest zerowa!");
        msg.exec();
    }
    comboCategory1 = dynamic_cast <QComboBox *> (ui->tableWidgetPut->cellWidget(currentRow, 7));
    if (comboCategory1->currentIndex() == 0) {
        validation = false;
        msg.setText("Proszę wybrać kategorie nr 1!");
        msg.exec();
    }
    comboCategory2 = dynamic_cast<QComboBox *>(ui->tableWidgetPut->cellWidget(currentRow, 8));
    if (comboCategory1->currentText() == comboCategory2->currentText()) {
        validation = false;
        msg.setText("Kategoria nr 1 jest taka sama jak kategoria nr 2!");
        msg.exec();
    }
    if (validation) {
        pProduct = new Product();
        pProduct->setIdProduct(ui->tableWidgetPut->item(currentRow, 1)->text().toInt());
        pProduct->setName(ui->tableWidgetPut->item(currentRow, 2)->text());
        pProduct->setDescription(ui->tableWidgetPut->item(currentRow, 3)->text());
        pProduct->setPrice(doubleBox->value());
        pProduct->setUnitsInStock(spinBox->value());
        pProduct->setCategory1Id(comboCategory1->itemData(comboCategory1->currentIndex()).toInt());
        pProduct->setCategory2Id(comboCategory2->itemData(comboCategory2->currentIndex()).toInt());
        pProduct->setImage(byteFileImagePut.toBase64());
        pProduct->setPreviousCategory1Id(previousCategory1IdList.at(currentRow));
        pProduct->setPreviousCategory2Id(previousCategory2IdList.at(currentRow));
        pProduct->setImageSize(imageSize);
        if(net.updateProductJson("/ShopAppWebService/rest/ShopResource/ProductUpdateJson", pProduct, pUser)){
            ui->lineEditFileNamePut->clear();
            byteFileImagePost.clear();
            imageSize = 0;
            ui->tableWidgetPut->setRowCount(0);
        }
    }
}

void ServiceWindow::on_pushButtonSelectImageFilePut_clicked()
{
    fileImagePathPut = QFileDialog::getOpenFileName(this, "Wybierz plik", QDir::homePath(), "Plik jpg (*.jpg);; Plik png(*.png);; Wszystkie pliki (*.*)");
    QFile fileImage(fileImagePathPut);
    if(!fileImage.open(QIODevice::ReadOnly)){
        msg.setText("Błąd otwarcia pliku!");
        msg.exec();
        return;
    }
    QFileInfo fileInfo(fileImagePathPut);
    if(fileInfo.size() > 600000){
        msg.setText("Rozmiar pliku to "+QString("%1").arg(fileInfo.size()/1000)+"kB i jest powyżej 600kB. Proszę wybrać mniejszy plik!");
        msg.exec();
        return;
    }
    byteFileImagePut = fileImage.readAll();
    ui->lineEditFileNamePut->setText(fileInfo.fileName());
    imageSize = static_cast<int>(fileInfo.size());
}
