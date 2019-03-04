#ifndef VALIDATION_H
#define VALIDATION_H

#include <QRegularExpression>


class Validation
{
public:
    Validation();
    bool validLogin(QString login);
    bool validPassword(QString password);
    bool validName(QString name);
    bool validEmail(QString email);

private:
    QRegularExpression regex;
    QRegularExpressionMatch match;
};

#endif // VALIDATION_H
