#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ileLinii=3;
    itm = new QTableWidgetItem[200];
    ui->tableWidget->setRowCount(ileLinii);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,600);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,100);
    ui->tableWidget->setColumnWidth(5,150);
    jm<<"kpl"<<"szt"<<"m"<<"m2"<<"m3"<<".....";
    for(int i=0; i<ileLinii; i++)
    {
        combo = new QComboBox();
        ui->tableWidget->setCellWidget(i,2,combo);
        for(int j=0; j<jm.size(); j++)
            combo->addItem(jm.at(j),jmv);
    }
    ui->komunikaty->setText("");
    pustyItem.setText("Proszę wypełnić puste pole");
    openFile.setText("Błąd otwarcia pliku");
    znakiFiltr.setText(QString("Niedozwolone znaki: %1 %2").arg(f.getZnaki(0)).arg(f.getZnaki(1)));
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(oblicz(QTableWidgetItem*)));
//    connect(this,SIGNAL(signalOblicz(int)),this,SLOT(slotOblicz(int)));
//    connect(ui->tableWidget,&QTableWidget::itemChanged,this,&MainWindow::obliczPrzyOtwarciu);
//    connect(this,&MainWindow::signalOblicz,this,&MainWindow::slotOblicz);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->currentRow());
    combo = new QComboBox();
    ui->tableWidget->setCellWidget(ui->tableWidget->currentRow()-1,2,combo);
    for(int k=0; k<jm.size(); k++)
        combo->addItem(jm.at(k),jmv);
    comboOut = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(ui->tableWidget->currentRow()-1,2));
    ui->tableWidget->setItem(ui->tableWidget->currentRow()-1,2, new QTableWidgetItem(comboOut->currentText()));
    ileLinii++;
}

void MainWindow::on_pushButton_4_clicked()
{
    //    czy trzeba usunąć combobox ??
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    ileLinii--;
}

void MainWindow::on_actionZapisz_triggered()
{
    if(!isNoEmptyItem()) pustyItem.exec();
    else
    {
        if(filtrItem())
        {
            //            MainWindow::otwartyPlik;
            QFile plik(MainWindow::otwartyPlik);
            if (!plik.open(QIODevice::WriteOnly | QIODevice::Text)) openFile.exec();
            QTextStream out(&plik);
            for(int i=0; i<ui->tableWidget->rowCount(); i++)
            {
                comboOut = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(i,2));
                out<<ui->tableWidget->item(i,0)->text()<<"#"<<ui->tableWidget->item(i,1)->text()<<"#"<<comboOut->currentText()<<"#"<<ui->tableWidget->item(i,3)->text()<<"#"<<ui->tableWidget->item(i,4)->text()<<"#"<<ui->tableWidget->item(i,5)->text()<<"\n";
            }
            plik.close();
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    combo = new QComboBox();
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,2,combo);
    for(int k=0; k<jm.size(); k++)
        combo->addItem(jm.at(k),jmv);
    comboOut = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1,2));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(comboOut->currentText()));
    ileLinii++;
}

void MainWindow::on_actionOtworz_triggered()
{
    disconnect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(oblicz(QTableWidgetItem*)));
    QString linia;
    MainWindow::otwartyPlik = QFileDialog::getOpenFileName(this, "Wybierz plik", "C://Users/", "Plik txt (*.txt);; Wszystkie pliki (*.*)");
    QFile plik(otwartyPlik);
    if (!plik.open(QIODevice::ReadOnly | QIODevice::Text)) openFile.exec();
    QTextStream strumien(&plik);
    int i=0;
    do{
        linia = strumien.readLine();
        i++;
    } while(!linia.isNull());
    ui->tableWidget->setRowCount(i-1);
    plik.close();
    ileLinii=i-1;
    //    linia.clear();
    //    strumien.flush();
    QFile plik2(otwartyPlik);
    if (!plik2.open(QIODevice::ReadOnly | QIODevice::Text)) openFile.exec();
    QTextStream strumien2(&plik2);
    QStringList lista;
    for(int j=0; j<i-1; j++)
    {
        strumien2.readLineInto(&linia);
        lista=linia.split('#');
        ui->tableWidget->setItem(j,0, new QTableWidgetItem(lista.at(0)));
        ui->tableWidget->setItem(j,1, new QTableWidgetItem(lista.at(1)));
        ui->tableWidget->setItem(j,2, new QTableWidgetItem(lista.at(2)));
        ui->tableWidget->setItem(j,3, new QTableWidgetItem(lista.at(3)));
        ui->tableWidget->setItem(j,4, new QTableWidgetItem(lista.at(4)));
        ui->tableWidget->setItem(j,5, new QTableWidgetItem(lista.at(5)));
        combo = new QComboBox();
        ui->tableWidget->setCellWidget(j,2,combo);
        for(int k=0; k<jm.size(); k++)
            combo->addItem(jm.at(k),jmv);
        comboOut = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(j,2));
        for(int l=0; l<jm.size(); l++)
        {
            if(comboOut->itemText(l)==lista.at(2)) combo->setCurrentIndex(l);
            //                combo->itemText(l);
            //            else combo->setItemText(0,lista.at(2));
            //                jm.append(lista.at(2));
        }
    }
    plik2.close();
    obliczPrzyOtwarciu();
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(oblicz(QTableWidgetItem*)));
}

void MainWindow::on_actionUstawienia_triggered()
{
    DialogUstawienia ustawienia;
    ustawienia.setModal(true);
    ustawienia.exec();
}

void MainWindow::on_actionZapisz_jako_triggered()
{
    if(!isNoEmptyItem()) pustyItem.exec();
    else
    {
        if(filtrItem())
        {
            //            MainWindow::otwartyPlik;
            otwartyPlik = QFileDialog::getSaveFileName(this,"Zapisz plik jako: ", "C://Users/", "Plik txt (*.txt)");
            QFile plik(otwartyPlik);
            if (!plik.open(QIODevice::WriteOnly | QIODevice::Text)) openFile.exec();
            QTextStream out(&plik);
            for(int i=0; i<ui->tableWidget->rowCount(); i++)
            {
                comboOut = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(i,2));
                out<<ui->tableWidget->item(i,0)->text()<<"#"<<ui->tableWidget->item(i,1)->text()<<"#"<<comboOut->currentText()<<"#"<<ui->tableWidget->item(i,3)->text()<<"#"<<ui->tableWidget->item(i,4)->text()<<"#"<<ui->tableWidget->item(i,5)->text()<<"\n";
            }
            plik.close();
        }
    }
}

bool MainWindow::filtrItem()
{
    text = true;
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        for(int j=0; j<ui->tableWidget->columnCount(); j++)
        {
            temp = ui->tableWidget->item(i,j)->text();
            temp = f.usunSpacje(&temp);
            if(f.filtrZnakow(&temp)==false)
            {
                text = false;
                znakiFiltr.exec();
                ui->tableWidget->setCurrentCell(i,j);
                break;
            }
            else ui->tableWidget->item(i,j)->setText(temp);
        }
        if(!text)
            break;
    }
    return text;
}

bool MainWindow::isNoEmptyItem()
{
    bool k=1;
    int m=0;
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        if(!ui->tableWidget->item(i,0) || ui->tableWidget->item(i,0)->text().isEmpty())
        {
            ui->tableWidget->setCurrentCell(i,0);
            ui->komunikaty->setText(QString("I=%1 J=%2").arg(i).arg(0));
            k=0;
            break;
        }
        else
        {
            for(int j=0; j<ui->tableWidget->columnCount(); j++)
            {
                if(!ui->tableWidget->item(i,j) || ui->tableWidget->item(i,j)->text().isEmpty())
                {
                    ui->tableWidget->setCurrentCell(i,j);
                    ui->komunikaty->setText(QString("I=%1 J=%2").arg(i).arg(j));
                    k=0;
                    m=j;
                    break;
                }
            }
        }
        if(ui->tableWidget->item(i,m)==0)
            break;
    }
    return k;
}

void MainWindow::oblicz(QTableWidgetItem*)
{
    double suma=0;
    for(int i=0; i<ileLinii; i++)
    {
        if (ui->tableWidget->item(i,3) && ui->tableWidget->item(i,4))
        {
            temp = ui->tableWidget->item(i,3)->text();
            ilosc = temp.toDouble();
            temp = ui->tableWidget->item(i,4)->text();
            cena = temp.toDouble();
            wartosc=cena*ilosc;
            itm[i].setText(QString("%1").arg(wartosc));
            ui->tableWidget->setItem(i,5,&itm[i]);
            suma+=itm[i].text().toDouble();
        }
    }
    ui->ogolem->setText(QString("%1").arg(suma));
//    obliczPrzyOtwarciu();
//    emit signalOblicz(y);
}

void MainWindow::obliczPrzyOtwarciu()
{
    double suma=0;
    for(int i=0; i<ileLinii; i++)
    {
//        itm = new QTableWidgetItem[200];
        if (ui->tableWidget->item(i,3) && ui->tableWidget->item(i,4))
        {
            temp = ui->tableWidget->item(i,3)->text();
            ilosc = temp.toDouble();
            temp = ui->tableWidget->item(i,4)->text();
            cena = temp.toDouble();
            wartosc=cena*ilosc;
            suma+=wartosc;
//            itm[i].setText(QString("%1").arg(wartosc));
            ui->tableWidget->setItem(i,5, new QTableWidgetItem(QString("%1").arg(wartosc)));
//            ui->tableWidget->setItem(i,5,&itm[i]);
//            suma+=itm[i].text().toDouble();
        }
    }
    ui->ogolem->setText(QString("%1").arg(suma));
}

//void MainWindow::slotOblicz(int x)
//{
//    if(x==1)
//    obliczPrzyOtwarciu();
//}

//void MainWindow::signalOblicz(bool x)
//{
//    if(ui->tableWidget->cellChanged(0,0))
//        emit x;
//}
