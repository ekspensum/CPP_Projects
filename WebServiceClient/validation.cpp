#include "validation.h"

Validation::Validation()
{


}

bool Validation::validLogin(QString login)
{
//    characters number is min 3 max 10 in this case
    regex.setPattern("^[a-zA-Z]{1}[a-zA-Z0-9]{1,8}[0-9]{1}$");
    match = regex.match(login);
    return match.hasMatch();
}

bool Validation::validPassword(QString password)
{
    regex.setPattern("^.{5,15}$");
    match = regex.match(password);
    return match.hasMatch();
}

bool Validation::validName(QString name)
{
    regex.setPattern("^[^|'\":%^#~}{\\]\\[;=<>`]{2,20}$");
    match = regex.match(name);
    return match.hasMatch();
}

bool Validation::validEmail(QString email)
{
    regex.setPattern("^[a-zA-Z]{3,20}[.]?[a-zA-Z]{0,20}@[a-zA-Z]{2,16}[.]{1}[a-zA-Z]{2,16}$");
    match = regex.match(email);
    return match.hasMatch();
}
