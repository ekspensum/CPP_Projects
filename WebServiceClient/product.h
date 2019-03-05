#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>


class Product
{
public:
    Product();

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    double getPrice() const;
    void setPrice(double value);

    int getUnitsInStock() const;
    void setUnitsInStock(int value);

    QString getImage() const;
    void setImage(const QString &value);

private:
    int id;
    QString name;
    QString description;
    double price;
    int unitsInStock;
    QString image;


};

#endif // PRODUCT_H
