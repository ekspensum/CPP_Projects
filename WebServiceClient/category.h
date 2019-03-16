#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>

class Category
{
public:
    Category();

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int id;
    QString name;
};

#endif // CATEGORY_H
