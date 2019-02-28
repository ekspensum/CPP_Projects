#ifndef USER_H
#define USER_H
#include <QString>


class User
{
public:
    User();
    friend class MainLogin;

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    QString getFirstName() const;
    void setFirstName(const QString &value);

    QString getLastName() const;
    void setLastName(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    int getIdUser() const;
    void setIdUser(int value);

private:
    int idUser;
    QString login;
    QString password;
    QString firstName;
    QString lastName;
    QString email;
};

#endif // USER_H
