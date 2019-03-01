#include "mainlogin.h"

MainLogin::MainLogin()
{

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
            stream >> index >> pUser->idUser >> pUser->login >> pUser->password >> pUser->firstName >> pUser->lastName >> pUser->email;
            if (i==index) {
                u = new User();
                u->setIdUser(pUser->idUser);
                u->setLogin(pUser->login);
                u->setPassword(pUser->password);
                u->setFirstName(pUser->firstName);
                u->setLastName(pUser->lastName);
                u->setEmail(pUser->email);
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

User *MainLogin::getLoggedUser(QString login, QString password)
{
    User *pUser = nullptr;
    QList<User *> userList = readFileUsersList();
    for (int i=0;i<userList.size();i++) {
        if (login == userList.at(i)->getLogin() && password == userList.at(i)->getPassword()) {
            pUser = userList.at(i);
            return pUser;
        }
    }
    return pUser;
}


