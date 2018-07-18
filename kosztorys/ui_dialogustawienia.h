/********************************************************************************
** Form generated from reading UI file 'dialogustawienia.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUSTAWIENIA_H
#define UI_DIALOGUSTAWIENIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DialogUstawienia
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogUstawienia)
    {
        if (DialogUstawienia->objectName().isEmpty())
            DialogUstawienia->setObjectName(QStringLiteral("DialogUstawienia"));
        DialogUstawienia->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogUstawienia);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogUstawienia);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogUstawienia, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogUstawienia, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogUstawienia);
    } // setupUi

    void retranslateUi(QDialog *DialogUstawienia)
    {
        DialogUstawienia->setWindowTitle(QApplication::translate("DialogUstawienia", "Ustawienia aplikacji", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogUstawienia: public Ui_DialogUstawienia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUSTAWIENIA_H
