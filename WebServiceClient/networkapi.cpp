#include "networkapi.h"

NetworkAPI::NetworkAPI(QObject *parent) : QObject(parent)
{
    //    "QT += network" is necessary add to *.pro for netMngr below:
    netMngr = new QNetworkAccessManager(this);
    //    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
}

void NetworkAPI::getProcessors()
{
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    QUrlQuery query;
    QUrl url;
    url.setScheme("http");
    url.setHost("localhost");
    url.setPort(8080);
    url.setQuery("format=xml");
    url.setPath("/ShopAppWebService/rest/ShopResource/Processors");

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/xml");
    reply = netMngr->get(request);

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

    QNetworkRequest request;
    request.setUrl(myurl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

}

void NetworkAPI::parseProcessors(QNetworkReply *reply)
{
    QByteArray array = reply->readAll();
    QXmlStreamReader xml(array);

    while (!xml.atEnd()) {
        xml.readNext();

        if(xml.isStartElement()){

            if(xml.name() == "Processor")
            {
                QXmlStreamAttributes atr = xml.attributes();
                QString x = atr.value("id").toString();
                //            qDebug() << "atrybut" << x;
            }

            if (xml.name() == "productImage") {
                //            qDebug() << xml.readElementText();
                product.setImage(xml.readElementText());
            }
        }
    }
}

void NetworkAPI::replyFinished(QNetworkReply *reply)
{

    if (reply->error() != QNetworkReply::NoError)
        qDebug() << reply->error() << reply->errorString();
    else
        parseProcessors(reply);

    //    qDebug() << "Reply " << reply->Text << reply->url() << reply->error() << reply->isRunning() << reply->isFinished() << reply->rawHeaderList() << reply->bytesAvailable();
}

Product NetworkAPI::getProduct() const
{
    return product;
}
