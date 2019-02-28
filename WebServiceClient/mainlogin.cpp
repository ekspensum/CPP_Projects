#include "mainlogin.h"

MainLogin::MainLogin()
{

}

User *MainLogin::getUser() const
{
    return user;
}

void MainLogin::setUser(User *value)
{
    user = value;
}

bool MainLogin::createFileUsersList(QList<User *> list)
{

    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        qInfo() << file.errorString();
        return false;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_4_7);

    for (int i=0;i<list.size();i++)
        stream << i << list.at(i)->idUser << list.at(i)->login << list.at(i)->password << list.at(i)->firstName << list.at(i)->lastName << list.at(i)->email;

    file.flush();
    file.close();
    return true;
}

QList<User *> MainLogin::readFileUsersList(){
    int index;
    int j =0;
    User *u;
    QList<User *> list;
    QFile file(path);

    try {
        file.open(QIODevice::ReadOnly);
        QDataStream stream(&file);

        for (int i=0;i==j;i++) {
            stream >> index >> user->idUser >> user->login >> user->password >> user->firstName >> user->lastName >> user->email;
            if (i==index) {
                u = new User();
                u->setIdUser(user->idUser);
                u->setLogin(user->login);
                u->setPassword(user->password);
                u->setFirstName(user->firstName);
                u->setLastName(user->lastName);
                u->setEmail(user->email);
                list.append(u);
                j++;
            }
        }
        file.close();
        return list;
    } catch (...) {
        qInfo() << file.errorString();
        QList<User *> emptyList;
        return emptyList;
    }
}

QList<User *> MainLogin::getUserList() const
{
    return userList;
}

void MainLogin::setUserList(const QList<User *> &value)
{
    userList = value;
}

