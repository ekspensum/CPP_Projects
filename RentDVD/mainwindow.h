#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "obslugabd.h"
#include "wypozyczalnia.h"
#include <QKeySequence>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_logowanie_clicked();

private:
    Ui::MainWindow *ui;
    Wypozyczalnia *w;

};

#endif // MAINWINDOW_H
