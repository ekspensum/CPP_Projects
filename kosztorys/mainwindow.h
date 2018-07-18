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
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString otwartyPlik;
//    QFile plik(otwartyPlik);
//    QTextStream strumien(plik);
    QString temp, norma, opis;
    double ilosc, cena, wartosc;
    bool text;
    QMessageBox pustyItem;
    QMessageBox openFile;
    QMessageBox znakiFiltr;
    QStringList jm;
    QComboBox *combo, *comboOut;
    QVariant jmv;
    int ileLinii;
    QTableWidgetItem *itm;


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

    bool filtrItem();
    bool isNoEmptyItem();
    void oblicz(QTableWidgetItem*);
    void obliczPrzyOtwarciu();
//    void slotOblicz(int);

    void on_tableWidget_cellChanged(int row, int column);

public slots:


signals:
//    void signalOblicz(bool x);

private:
    Ui::MainWindow *ui;
//    int y=1;
};

#endif // MAINWINDOW_H
