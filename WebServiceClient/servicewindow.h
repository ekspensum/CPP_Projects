#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H

#include <QMainWindow>
#include <user.h>
#include <product.h>
#include <mainlogin.h>
#include <validation.h>
#include <QMessageBox>
#include <networkapi.h>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QByteArray>
#include <QComboBox>

namespace Ui {
class ServiceWindow;
}

class ServiceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServiceWindow(QWidget *parent = nullptr);
    explicit ServiceWindow(User *user, QWidget *parent = nullptr);
    ~ServiceWindow();

private slots:
    void getProductsList();
    void getCategoryList();
    void getAddProductAnswer(QString str);
    void getProgressSignal(qint64 bytesReceived, qint64 bytesTotal);
    void on_pushButtonAddNewUser_clicked();
    void on_pushButtonGetProductsXml_clicked();
    void on_pushButtonGetProductJson_clicked();
    void on_pushButtonSelectImageFile_clicked();
    void on_commandLinkButtonAddProduct_clicked();
    void findProductList();
    void on_pushButtonFindProduct_clicked();
    void on_commandLinkButtonUpdate_clicked();

private:
    Ui::ServiceWindow *ui;
    User *pUser;
    QStringList roleList;
    MainLogin mainLogin;
    QList<User *> usersList;
    Validation valid;
    QMessageBox msg;
    NetworkAPI net;
    QString fileImagePath;
    QByteArray byteFileImage;
    Product *pProduct;

    QString procesorsXmlElement = "Processor";
    QString procesorsXmlPath = "/ShopAppWebService/rest/ShopResource/ProcessorsXml";
    QVariantList processorXmlList = {QVariant::fromValue(procesorsXmlElement), QVariant::fromValue(procesorsXmlPath)};

    QString hardDisksXmlElement = "HardDisk";
    QString hardDisksXmlPath = "/ShopAppWebService/rest/ShopResource/HardDisksXml";
    QVariantList hardDisksXmlList = {QVariant::fromValue(hardDisksXmlElement), QVariant::fromValue(hardDisksXmlPath)};

    QString mainBoardsXmlElement = "mainBoardXml";
    QString mainBoardsXmlPath = "/ShopAppWebService/rest/ShopResource/MainBoardsXml";
    QVariantList mainBoardsXmlList = {QVariant::fromValue(mainBoardsXmlElement), QVariant::fromValue(mainBoardsXmlPath)};

    QString ramMemoryXmlElement = "ramMemoryXml";
    QString ramMemoryXmlPath = "/ShopAppWebService/rest/ShopResource/RamMemoryXml";
    QVariantList ramMemoryXmlList = {QVariant::fromValue(ramMemoryXmlElement), QVariant::fromValue(ramMemoryXmlPath)};

    QString allProductsXmlElement = "Product";
    QString allProductsXmlPath = "";
    QVariantList allProductsXmlList = {QVariant::fromValue(allProductsXmlElement), QVariant::fromValue(allProductsXmlPath)};

    QString procesorsJson = "/ShopAppWebService/rest/ShopResource/ProcessorsJson";
    QString hardisksJson = "/ShopAppWebService/rest/ShopResource/HardDisksJson";
    QString mainBoardsJson = "/ShopAppWebService/rest/ShopResource/MainBoardsJson";
    QString ramMemoryJson = "/ShopAppWebService/rest/ShopResource/RamMemoryJson";
    QString productsJson = "";
    void fillUserTable();
    QComboBox *comboCategory1;
    QComboBox *comboCategory2;

};

#endif // SERVICEWINDOW_H
