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
