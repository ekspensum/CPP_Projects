#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H

#include <QMainWindow>
#include <user.h>
#include <mainlogin.h>
#include <validation.h>
#include <QMessageBox>
#include <networkapi.h>

namespace Ui {
class ServiceWindow;
}

class ServiceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServiceWindow(QWidget *parent = nullptr);
    explicit ServiceWindow(User *user, QWidget *parent = nullptr);
    ~ServiceWindow();

private slots:
    void on_pushButtonAddNewUser_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ServiceWindow *ui;
    User user;
    User *pUser = &user;
    QStringList roleList;
    MainLogin mainLogin;
    QList<User *> usersList;
    Validation valid;
    QMessageBox msg;
};

#endif // SERVICEWINDOW_H
