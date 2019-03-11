#include "networkapi.h"

NetworkAPI::NetworkAPI(QObject *parent) : QObject(parent)
{
    //    "QT += network" is necessary add to *.pro for netMngr below:
    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedXml(QNetworkReply *)));
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedJson(QNetworkReply *)));
}

void NetworkAPI::getProductsXml(QString product, QString path)
{
    productVariant = product;
    QUrl url;
    url.setScheme("http");
    url.setHost("localhost");
    url.setPort(8080);
    url.setQuery("format=xml");
    url.setPath(path);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/xml");
    reply = netMngr->get(request);
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(progressSignal(qint64, qint64)));
}

void NetworkAPI::getProductsJson(QString product, QString path)
{
    QVariantMap feed;
    feed.insert("api_key","api_key");
    feed.insert("field1",QVariant(25).toString());
    feed.insert("field2",QVariant(72).toString());
    feed.insert("field3",QVariant(900).toString());
    QByteArray payload=QJsonDocument::fromVariant(feed).toJson();

    qDebug() << QVariant(payload).toString();

    QUrl url;
    url.setScheme("http");
    url.setHost("loclhost");
    url.setPort(8080);
    url.setQuery("format=json");
    url.setPath(path);

    qDebug() << url.toString();

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reply = netMngr->get(request);
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(progressSignal(qint64, qint64)));
}

void NetworkAPI::parseProductXml(QNetworkReply *reply)
{
    productList.clear();
    QByteArray array = reply->readAll();
    QXmlStreamReader xml(array);

    if (productVariant == "mainBoard") {
        int i = 0;
        while (!xml.atEnd()) {
            QXmlStreamReader::TokenType token = xml.readNext();
            if(token == xml.StartDocument){
//                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }
            if(token == xml.StartElement) {
//                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();

                if(xml.name() == "collection") {
//                    qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if(xml.name() == productVariant) {
                    pProduct = new Product();
                    pProduct->setId(i);
                    continue;
                }
                if(xml.name() == "base64Image") {
                    pProduct->setImage(xml.readElementText());
//                    qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if(xml.name() == "description"){
                    pProduct->setDescription(xml.readElementText());
//                    qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if (xml.name() == "id"){
                    pProduct->setIdProduct(xml.readElementText().toInt());
//                    qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if (xml.name() == "name"){
                    pProduct->setName(xml.readElementText());
//                    qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if(xml.name() == "price"){
                    pProduct->setPrice(xml.readElementText().toDouble());
//                    qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if(xml.name() == "unitsInStock"){
                    pProduct->setUnitsInStock(xml.readElementText().toInt());
//                    qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    productList.append(pProduct);
                    i++;
                    continue;
                }
            }
        }
        emit setProductsList();
        xml.clear();

    } else {
        QXmlStreamAttributes atr;
        QString x;
        while (!xml.atEnd()) {
            QXmlStreamReader::TokenType token = xml.readNext();
            if(token == xml.StartDocument){
                //            qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                continue;
            }
            if(token == xml.StartElement) {
                //            qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                if(xml.name() == productVariant) {
                    atr = xml.attributes();
                    x = atr.value("id").toString();
                    pProduct = new Product();
                    pProduct->setId(x.toInt());
                    //                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if (xml.name() == "idPproduct"){
                    pProduct->setIdProduct(xml.readElementText().toInt());
                    //                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if (xml.name() == "productName"){
                    pProduct->setName(xml.readElementText());
                    //                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if(xml.name() == "productDescription"){
                    pProduct->setDescription(xml.readElementText());
                    //                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if(xml.name() == "productPrice"){
                    pProduct->setPrice(xml.readElementText().toDouble());
                    //                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if(xml.name() == "productUnitsInStock"){
                    pProduct->setUnitsInStock(xml.readElementText().toInt());
                    //                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    continue;
                }
                if (xml.name() == "productImage"){
                    pProduct->setImage(xml.readElementText());
                    //                qDebug() << xml.name() << xml.tokenType() << xml.errorString() << xml.lineNumber() << xml.columnNumber() << xml.characterOffset();
                    productList.append(pProduct);
                    continue;
                }
                continue;
            }
        }
        emit setProductsList();
        xml.clear();
    }


}

void NetworkAPI::parseProductJson(QNetworkReply *reply)
{

}

void NetworkAPI::replyFinishedXml(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << reply->error() << reply->errorString();
    else
        parseProductXml(reply);

    //    qDebug() << "Reply " << reply->Text << reply->url() << reply->error() << reply->isRunning() << reply->isFinished() << reply->rawHeaderList() << reply->bytesAvailable();
}

void NetworkAPI::replyFinishedJson(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << reply->error() << reply->errorString();
    else
        parseProductJson(reply);
}

void NetworkAPI::progressSignal(qint64 bytesReceived, qint64 bytesTotal)
{
    emit setProgressSignal(bytesReceived, bytesTotal);
}

QList<Product *> NetworkAPI::getProductList() const
{
    return productList;
}

