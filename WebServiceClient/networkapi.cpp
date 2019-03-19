#include "networkapi.h"

NetworkAPI::NetworkAPI(QObject *parent) : QObject(parent)
{

}

NetworkAPI::~NetworkAPI()
{
    delete netMngr;
    delete reply;
    delete pProduct;
    delete pCategory;
}

void NetworkAPI::getProductsXml(QString product, QString path)
{
    //    "QT += network" is necessary add to *.pro for netMngr below:
    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedXml(QNetworkReply *)));
    productVariant = product;
    QUrl url;
    url.setScheme("http");
    url.setHost(HOST);
    url.setPort(8080);
    url.setQuery("format=xml");
    url.setPath(path);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/xml");
    reply = netMngr->get(request);
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(progressSignal(qint64, qint64)));
}

void NetworkAPI::getProductsJson(QString path)
{
    //    "QT += network" is necessary add to *.pro for netMngr below:
    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedJson(QNetworkReply *)));
    QUrl url;
    url.setScheme("http");
    url.setHost(HOST);
    url.setPort(8080);
    url.setQuery("format=json");
    url.setPath(path);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reply = netMngr->get(request);
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(progressSignal(qint64, qint64)));
}

void NetworkAPI::getCategoryJson(QString path)
{
    //    "QT += network" is necessary add to *.pro for netMngr below:
    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedCategoryJson(QNetworkReply *)));
    QUrl url;
    url.setScheme("http");
    url.setHost(HOST);
    url.setPort(8080);
    url.setQuery("format=json");
    url.setPath(path);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reply = netMngr->get(request);
}

bool NetworkAPI::addProductJson(QString path, Product *pProduct, User *pUser)
{
    QJsonDocument jsonDoc;
    QJsonObject jsonObject;

    jsonObject["login"] = pUser->getLogin();
    jsonObject["password"] = pUser->getPassword();
    jsonObject["name"] = pProduct->getName();
    jsonObject["description"] = pProduct->getDescription();
    jsonObject["price"] = pProduct->getPrice();
    jsonObject["unitsInStock"] = pProduct->getUnitsInStock();
    jsonObject["category1Id"] = pProduct->getCategory1Id();
    jsonObject["category2Id"] = pProduct->getCategory2Id();
    jsonObject["image"] = pProduct->getImage();
    jsonDoc.setObject(jsonObject);

    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedAddProductJson(QNetworkReply *)));
    QUrl url;
    url.setScheme("http");
    url.setHost(HOST);
    url.setPort(8080);
    url.setQuery("format=json");
    url.setPath(path);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reply = netMngr->post(request, jsonDoc.toJson());
    return true;
}

bool NetworkAPI::updateProductJson(QString path, Product *pProduct, User *pUser)
{
    QJsonDocument jsonDoc;
    QJsonObject jsonObject;

    jsonObject["login"] = pUser->getLogin();
    jsonObject["password"] = pUser->getPassword();
    jsonObject["idProduct"] = pProduct->getIdProduct();
    jsonObject["name"] = pProduct->getName();
    jsonObject["description"] = pProduct->getDescription();
    jsonObject["price"] = pProduct->getPrice();
    jsonObject["unitsInStock"] = pProduct->getUnitsInStock();
    jsonObject["category1Id"] = pProduct->getCategory1Id();
    jsonObject["category2Id"] = pProduct->getCategory2Id();
    jsonObject["image"] = pProduct->getImage();
    jsonObject["previousCategory1Id"] = pProduct->getPreviousCategory1Id();
    jsonObject["previousCategory2Id"] = pProduct->getPreviousCategory2Id();
    jsonObject["imageSize"] = pProduct->getImageSize();
    jsonDoc.setObject(jsonObject);

    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedAddProductJson(QNetworkReply *)));
    QUrl url;
    url.setScheme("http");
    url.setHost(HOST);
    url.setPort(8080);
    url.setQuery("format=json");
    url.setPath(path);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reply = netMngr->put(request, jsonDoc.toJson());
    return true;
}

void NetworkAPI::findProductJson(QString path)
{
    netMngr = new QNetworkAccessManager(this);
    connect(netMngr, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinishedFindProductJson(QNetworkReply *)));
    QUrl url;
    url.setScheme("http");
    url.setHost(HOST);
    url.setPort(8080);
    url.setQuery("format=json");
    url.setPath(path);

    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reply = netMngr->get(request);
}

void NetworkAPI::parseProductXml(QNetworkReply *reply)
{
    productList.clear();
    QByteArray array = reply->readAll();
    QXmlStreamReader xml(array);

    if (productVariant == "mainBoardXml") {
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

    } else if(productVariant == "ramMemoryXml") {

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
    productList.clear();
    QByteArray array = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(array);
    if(jsonDoc.isEmpty()){
        qDebug() << "Json doc is empty!";
        return;
    }
    if(jsonDoc.isArray()){
        QJsonArray jsonArray = jsonDoc.array();
        for (int i=0;i<jsonArray.size();i++) {
            pProduct = new Product();
            pProduct->setId(i);
            pProduct->setIdProduct(jsonArray.at(i).toArray().at(0).toInt());
            pProduct->setName(jsonArray.at(i).toArray().at(1).toString());
            pProduct->setDescription(jsonArray.at(i).toArray().at(2).toString());
            pProduct->setPrice(jsonArray.at(i).toArray().at(3).toDouble());
            pProduct->setUnitsInStock(jsonArray.at(i).toArray().at(4).toInt());
            pProduct->setImage(jsonArray.at(i).toArray().at(5).toString());
            productList.append(pProduct);
        }
        emit setProductsList();
    } else if (jsonDoc.isObject()) {
        QJsonObject jsonObject = jsonDoc.object();
        int k=0;
        for(int i=0; i<jsonObject.keys().size(); i++)
            for(int j=0; j<jsonObject.value(jsonObject.keys().at(i)).toArray().at(j).toObject().size(); j++){
                pProduct = new Product();
                pProduct->setId(k);
                pProduct->setIdProduct(jsonObject.value(jsonObject.keys().at(i)).toArray().at(j).toObject().value("id").toInt());
                pProduct->setName(jsonObject.value(jsonObject.keys().at(i)).toArray().at(j).toObject().value("name").toString());
                pProduct->setDescription(jsonObject.value(jsonObject.keys().at(i)).toArray().at(j).toObject().value("description").toString());
                pProduct->setPrice(jsonObject.value(jsonObject.keys().at(i)).toArray().at(j).toObject().value("price").toDouble());
                pProduct->setUnitsInStock(jsonObject.value(jsonObject.keys().at(i)).toArray().at(j).toObject().value("unitsInStock").toInt());
                pProduct->setImage(jsonObject.value(jsonObject.keys().at(i)).toArray().at(j).toObject().value("base64Image").toString());
                productList.append(pProduct);
                k++;
            }
        emit setProductsList();
    } else
        qDebug()<< "Json doc is not an array and not object!";
}

void NetworkAPI::parseCategoryJson(QNetworkReply *reply)
{
    categoryList.clear();
    QByteArray array = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(array);
    if(jsonDoc.isEmpty()){
        qDebug() << "Json doc is empty!";
        return;
    }
    if(jsonDoc.isArray()){
        QJsonArray jsonArray = jsonDoc.array();
        for (int i=0;i<jsonArray.size();i++) {
            pCategory = new Category();
            pCategory->setId(jsonArray.at(i).toArray().at(0).toInt());
            pCategory->setName(jsonArray.at(i).toArray().at(1).toString());
            categoryList.append(pCategory);
        }
        emit setCategoryList();
    } else
        qDebug()<< "Json doc is not an array";
}

void NetworkAPI::parseFindProductJson(QNetworkReply *reply)
{
    productList.clear();
    QByteArray array = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(array);
    if(jsonDoc.isEmpty()){
        qDebug() << "Json doc is empty!";
        return;
    }
    if(jsonDoc.isArray()){
        QJsonArray jsonArray = jsonDoc.array();
        QJsonObject obj;
        for (int i=0;i<jsonArray.size();i++) {
            pProduct = new Product();
            pProduct->setId(i);
            pProduct->setName(jsonArray.at(i).toObject().value("name").toString());
            pProduct->setDescription(jsonArray.at(i).toObject().value("description").toString());
            pProduct->setPrice(jsonArray.at(i).toObject().value("price").toDouble());
            pProduct->setUnitsInStock(jsonArray.at(i).toObject().value("unitsInStock").toInt());
            pProduct->setImage(jsonArray.at(i).toObject().value("image").toString());
            pProduct->setCategory1Id(jsonArray.at(i).toObject().value("category1Id").toInt());
            pProduct->setCategory2Id(jsonArray.at(i).toObject().value("category2Id").toInt());
            pProduct->setIdProduct(jsonArray.at(i).toObject().value("idProduct").toInt());
            productList.append(pProduct);
        }
        emit findProductList();
    } else
        qDebug()<< "Json doc is not an array";
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

void NetworkAPI::replyFinishedCategoryJson(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << reply->error() << reply->errorString();
    else
        parseCategoryJson(reply);
}

void NetworkAPI::replyFinishedAddProductJson(QNetworkReply *reply)
{
    QString answer = "Odpowiedź serwera: ";
    if (reply->error() != QNetworkReply::NoError){
        qDebug() << reply->error() << reply->errorString();
        emit setAddProductAnswer(answer+reply->errorString());
    }
    else
        emit setAddProductAnswer(answer+reply->readAll());
}

void NetworkAPI::replyFinishedUpdateProductJson(QNetworkReply *reply)
{
    QString answer = "Odpowiedź serwera: ";
    if (reply->error() != QNetworkReply::NoError){
        qDebug() << reply->error() << reply->errorString();
        emit setUpdateProductAnswer(answer+reply->errorString());
    }
    else
        emit setUpdateProductAnswer(answer+reply->readAll());
}

void NetworkAPI::replyFinishedFindProductJson(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << reply->error() << reply->errorString();
    else
        parseFindProductJson(reply);
}

void NetworkAPI::progressSignal(qint64 bytesReceived, qint64 bytesTotal)
{
    emit setProgressSignal(bytesReceived, bytesTotal);
}

QList<Category *> NetworkAPI::getCategoryList() const
{
    return categoryList;
}

QList<Product *> NetworkAPI::getProductList() const
{
    return productList;
}

