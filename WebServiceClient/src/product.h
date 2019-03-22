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

    int getIdProduct() const;
    void setIdProduct(int value);

    int getCategory1Id() const;
    void setCategory1Id(int value);

    int getCategory2Id() const;
    void setCategory2Id(int value);

    int getImageSize() const;
    void setImageSize(int value);

    int getPreviousCategory1Id() const;
    void setPreviousCategory1Id(int value);

    int getPreviousCategory2Id() const;
    void setPreviousCategory2Id(int value);

private:
    int id;
    int idProduct;
    QString name;
    QString description;
    double price;
    int unitsInStock;
    QString image;
    int category1Id;
    int category2Id;
    int imageSize;
    int previousCategory1Id;
    int previousCategory2Id;


};

#endif // PRODUCT_H
