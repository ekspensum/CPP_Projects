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
    void getProcessors();
    void getDataJson();
    void parseProcessors(QNetworkReply *reply);


    QList<Product *> getProductList() const;

signals:
    void setProductsList();
    void someSignal();

public slots:
    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *netMngr;
    QNetworkReply *reply;
    Product product;
    Product *pProduct;
    QList<Product *> productList;

};

#endif // NETWORKAPI_H
