#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QDebug>
#include "filtr.h"
#include <QFileDialog>
#include <QMessageBox>
#include <dialogustawienia.h>
#include <QComboBox>
#include <QStringList>
#include <QVariant>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString otwartyPlik;
    QString temp, norma, opis;
    double ilosc, cena, wartosc;
    QMessageBox pustyItem;
    QMessageBox openFile;
    QMessageBox znakiFiltr;
    QStringList jm;
    QComboBox *combo, *comboOut;
    QVariant jmv;
    int ileLinii;
    QLabel *labelWartosc;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Filtr f;


private slots:

    void on_pushButtonWstawWiersz_clicked();

    void on_pushButtonUsunWiersz_clicked();

    void on_actionZapisz_triggered();

    void on_pushButtonDodajWiersz_clicked();

    void on_actionOtworz_triggered();

    void on_actionUstawienia_triggered();

    void on_actionZapisz_jako_triggered();

    void on_tableWidget_cellChanged(int row, int column);


public slots:


signals:


private:
    Ui::MainWindow *ui;
    bool filtrItem();
    bool isNoEmptyItem();

};

#endif // MAINWINDOW_H
