#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <user.h>
#include <mainlogin.h>
#include <validation.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(User *user, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAddNewUser_clicked();

private:
    Ui::MainWindow *ui;
    User user;
    User *pUser = &user;
    QStringList roleList;
    MainLogin mainLogin;
    QList<User *> usersList;
    Validation valid;
    QMessageBox msg;
};

#endif // MAINWINDOW_H
