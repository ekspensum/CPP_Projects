#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <mainlogin.h>
#include <servicewindow.h>
#include <user.h>
#include <QList>
#include <QMessageBox>
#include <QCryptographicHash>
#include <networkapi.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
    User user;
    User *pUser = &user;
    MainLogin login;
    QMessageBox msg;
    NetworkAPI net;
};

#endif // LOGINWINDOW_H
