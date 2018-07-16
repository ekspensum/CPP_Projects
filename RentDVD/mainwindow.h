#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "obslugabd.h"
#include "wypozyczalnia.h"
#include <QKeySequence>
#include <QRegularExpression>

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
    QRegularExpression regex;
    QRegularExpressionMatch match;

};

#endif // MAINWINDOW_H
