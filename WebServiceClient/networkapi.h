#ifndef NETWORKAPI_H
#define NETWORKAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtCore>
#include <QXmlStreamReader>
#include <product.h>
#include <category.h>

class NetworkAPI : public QObject
{
    Q_OBJECT
public:
    explicit NetworkAPI(QObject *parent = nullptr);
    void getProductsXml(QString product, QString path);
    void getProductsJson(QString path);
    void getCategoryJson(QString path);
    void parseProductXml(QNetworkReply *reply);
    void parseProductJson(QNetworkReply *reply);
    void parseCategoryJson(QNetworkReply *reply);
    QList<Product *> getProductList() const;
    QList<Category *> getCategoryList() const;

signals:
    void setProductsList();
    void setCategoryList();
    void setProgressSignal(qint64 bytesReceived, qint64 bytesTotal);


public slots:
    void replyFinishedXml(QNetworkReply *reply);
    void replyFinishedJson(QNetworkReply *reply);
    void replyFinishedCategoryJson(QNetworkReply *reply);
    void progressSignal(qint64 bytesReceived, qint64 bytesTotal);

private:
    QNetworkAccessManager *netMngr;
    QNetworkReply *reply;
    Product *pProduct;
    Category *pCategory;
    QList<Product *> productList;
    QList<Category *> categoryList;
    QString productVariant;

};

#endif // NETWORKAPI_H
