#include "product.h"

Product::Product()
{

}

int Product::getId() const
{
    return id;
}

void Product::setId(int value)
{
    id = value;
}

QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &value)
{
    name = value;
}

QString Product::getDescription() const
{
    return description;
}

void Product::setDescription(const QString &value)
{
    description = value;
}

double Product::getPrice() const
{
    return price;
}

void Product::setPrice(double value)
{
    price = value;
}

int Product::getUnitsInStock() const
{
    return unitsInStock;
}

void Product::setUnitsInStock(int value)
{
    unitsInStock = value;
}

QString Product::getImage() const
{
    return image;
}

void Product::setImage(const QString &value)
{
    image = value;
}

int Product::getIdProduct() const
{
    return idProduct;
}

void Product::setIdProduct(int value)
{
    idProduct = value;
}

int Product::getCategory1Id() const
{
    return category1Id;
}

void Product::setCategory1Id(int value)
{
    category1Id = value;
}

int Product::getCategory2Id() const
{
    return category2Id;
}

void Product::setCategory2Id(int value)
{
    category2Id = value;
}

int Product::getImageSize() const
{
    return imageSize;
}

void Product::setImageSize(int value)
{
    imageSize = value;
}

int Product::getPreviousCategory1Id() const
{
    return previousCategory1Id;
}

void Product::setPreviousCategory1Id(int value)
{
    previousCategory1Id = value;
}

int Product::getPreviousCategory2Id() const
{
    return previousCategory2Id;
}

void Product::setPreviousCategory2Id(int value)
{
    previousCategory2Id = value;
}

