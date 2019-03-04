#include "networkapi.h"

NetworkAPI::NetworkAPI(QObject *parent) : QObject(parent)
{
    //    "QT += network" is necessary add to *.pro for netMngr below:
//        netMngr = new QNetworkAccessManager(this);
//        connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
}

void NetworkAPI::getProduct()
{
    QUrlQuery query;
//    query.addQueryItem()

    QUrl myurl;
    myurl.setScheme("http");
//    myurl.setHost("localhost");
    myurl.setHost("api.nbp.pl");
//    myurl.setPort(8080);
//    myurl.setPath("/ShopAppWebService/rest/ShopResource/ProcessorsByte/");
    myurl.setQuery("format=xml");
    myurl.setPath("/api/exchangerates/tables/a/");

    QEventLoop eventLoop;

    netMngr = new QNetworkAccessManager(this);
//    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));

    QNetworkRequest request;
    request.setUrl(myurl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/xml");
    reply = netMngr->get(request);
    eventLoop.exec();

    qDebug() << "replyFinished " << reply->readAll();

}

void NetworkAPI::getDataJson()
{
    QVariantMap feed;
    feed.insert("api_key","XXXXXXXX XXXXXXXX”");
    feed.insert("field1",QVariant(25).toString());
    feed.insert("field2",QVariant(72).toString());
    feed.insert("field3",QVariant(900).toString());
    QByteArray payload=QJsonDocument::fromVariant(feed).toJson();

    qDebug() << QVariant(payload).toString();

    QUrl myurl;
    myurl.setScheme("http"); //https also applicable
    myurl.setHost("api.thingspeak.com");
    myurl.setPath("/update.json");

    qDebug() << myurl.toString();

    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    QNetworkRequest request;
    request.setUrl(myurl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    reply = netMngr->post(request,payload);

//    connect(reply, &QNetworkReply::finished, this, &NetworkAPI::replyFinished);

//    reply->deleteLater();

}

void NetworkAPI::replyFinished(QNetworkReply *reply)
{
    qDebug() << "replyFinished " << reply->readAll();
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << reply->error() << reply->errorString();

//    qDebug() << "Reply " << reply->bytesToWrite() << reply->readBufferSize() << reply->readAll() << reply->read(2048);
//    qDebug() << "Reply " << reply->Text << reply->url() << reply->error() << reply->isRunning() << reply->isFinished() << reply->rawHeaderList() << reply->bytesAvailable();
}
