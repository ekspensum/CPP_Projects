#ifndef NETWORKAPI_H
#define NETWORKAPI_H

#include <QObject>
//#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
//#include <QNetworkRequest>
#include <QtCore>

class NetworkAPI : public QObject
{
    Q_OBJECT
public:
    explicit NetworkAPI(QObject *parent = nullptr);
    void getProduct();
    void getDataJson();

signals:

public slots:
    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *netMngr;
    QNetworkReply *reply;

};

#endif // NETWORKAPI_H
