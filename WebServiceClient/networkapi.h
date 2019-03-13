#ifndef NETWORKAPI_H
#define NETWORKAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtCore>
#include <QXmlStreamReader>
#include <product.h>

class NetworkAPI : public QObject
{
    Q_OBJECT
public:
    explicit NetworkAPI(QObject *parent = nullptr);
    void getProductsXml(QString product, QString path);
    void getProductsJson(QString path);
    void parseProductXml(QNetworkReply *reply);
    void parseProductJson(QNetworkReply *reply);
    QList<Product *> getProductList() const;

signals:
    void setProductsList();
    void setProgressSignal(qint64 bytesReceived, qint64 bytesTotal);


public slots:
    void replyFinishedXml(QNetworkReply *reply);
    void replyFinishedJson(QNetworkReply *reply);
    void progressSignal(qint64 bytesReceived, qint64 bytesTotal);

private:
    QNetworkAccessManager *netMngr;
    QNetworkReply *reply;
    Product *pProduct;
    QList<Product *> productList;
    QString productVariant;

};

#endif // NETWORKAPI_H
