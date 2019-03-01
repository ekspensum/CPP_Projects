#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <user.h>

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

private:
    Ui::MainWindow *ui;
    User *user;
};

#endif // MAINWINDOW_H
