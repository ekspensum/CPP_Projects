#ifndef MAINLOGIN_H
#define MAINLOGIN_H
#include <user.h>
#include <QList>
#include <QDataStream>
#include <QFile>
#include <QDir>
#include <QDebug>


class MainLogin
{
public:
    MainLogin();

    User *getUser() const;
    void setUser(User *value);

    bool createFileUsersList(QList<User *> userList);
    QList<User *> readFileUsersList();

    QList<User *> getUserList() const;
    void setUserList(const QList<User *> &value);


private:

    QString path = QDir::currentPath() + QDir::separator() + "users.u";
    User usr;
    User *user = &usr;
    QList<User*> userList;

};

#endif // MAINLOGIN_H
