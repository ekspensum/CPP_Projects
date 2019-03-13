#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H

#include <QMainWindow>
#include <user.h>
#include <mainlogin.h>
#include <validation.h>
#include <QMessageBox>
#include <networkapi.h>

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
    void getProgressSignal(qint64 bytesReceived, qint64 bytesTotal);
    void on_pushButtonAddNewUser_clicked();
    void on_pushButtonGetProductsXml_clicked();
    void on_pushButtonGetProductJson_clicked();

private:
    Ui::ServiceWindow *ui;
    User *pUser;
    QStringList roleList;
    MainLogin mainLogin;
    QList<User *> usersList;
    Validation valid;
    QMessageBox msg;
    NetworkAPI net;

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

};

#endif // SERVICEWINDOW_H
