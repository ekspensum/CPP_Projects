#include "user.h"

User::User()
{

}

QString User::getLogin() const
{
    return login;
}

void User::setLogin(const QString &value)
{
    login = value;
}

QString User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &value)
{
    password = value;
}

QString User::getFirstName() const
{
    return firstName;
}

void User::setFirstName(const QString &value)
{
    firstName = value;
}

QString User::getLastName() const
{
    return lastName;
}

void User::setLastName(const QString &value)
{
    lastName = value;
}

QString User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &value)
{
    email = value;
}

int User::getIdUser() const
{
    return idUser;
}

void User::setIdUser(int value)
{
    idUser = value;
}

QString User::getRole() const
{
    return role;
}

void User::setRole(const QString &value)
{
    role = value;
}
