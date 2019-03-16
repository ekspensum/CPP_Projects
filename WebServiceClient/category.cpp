#include "category.h"

Category::Category()
{

}

int Category::getId() const
{
    return id;
}

void Category::setId(int value)
{
    id = value;
}

QString Category::getName() const
{
    return name;
}

void Category::setName(const QString &value)
{
    name = value;
}
