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
    int i = 0;
    QXmlStreamAttributes atr;
    QString x;
    while (!xml.atEnd()) {

        QXmlStreamReader::TokenType token = xml.readNext();

        if(token == xml.StartDocument){
            qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
            continue;
        }

        if(token == xml.StartElement) {
            qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();

            if(xml.name() == "Processor") {

                atr = xml.attributes();
                x = atr.value("id").toString();

                if(x.toInt() > i){
                    i++;
                    productList.append(pProduct);
                }

                pProduct = new Product();
                pProduct->setId(x.toInt());

                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }

            if (xml.name() == "productName"){
                pProduct->setName(xml.readElementText());
                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }

            if(xml.name() == "productDescription"){
                pProduct->setDescription(xml.readElementText());
                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }

            if(xml.name() == "productPrice"){
                pProduct->setPrice(xml.readElementText().toDouble());
                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }

            if(xml.name() == "productUnitsInStock"){
                pProduct->setUnitsInStock(xml.readElementText().toInt());
                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }

            if (xml.name() == "productImage"){
                pProduct->setImage(xml.readElementText());
                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }

            continue;
        }
    }
    productList.append(pProduct);
    emit setProductsList();
}

void NetworkAPI::replyFinished(QNetworkReply *reply)
{

    if (reply->error() != QNetworkReply::NoError)
        qDebug() << reply->error() << reply->errorString();
    else
        parseProcessors(reply);

    //    qDebug() << "Reply " << reply->Text << reply->url() << reply->error() << reply->isRunning() << reply->isFinished() << reply->rawHeaderList() << reply->bytesAvailable();
}

QList<Product *> NetworkAPI::getProductList() const
{
    return productList;
}

