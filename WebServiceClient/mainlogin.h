#ifndef MAINLOGIN_H
#define MAINLOGIN_H
#include <user.h>
#include <QList>
#include <QDataStream>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QCryptographicHash>


class MainLogin
{
public:
    MainLogin();

    bool createFileUsersList(QList<User *> userList);
    QList<User *> readFileUsersList();

    User *getLoggedUser(QString login, QString password);


private:
    QString path = QDir::currentPath() + QDir::separator() + "users.u";
    User *pUser;

};

#endif // MAINLOGIN_H
