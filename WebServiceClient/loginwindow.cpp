#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->pushButtonLogin->setShortcut(QKeySequence(Qt::Key_Return));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButtonLogin_clicked()
{
    //    add default user which role is "Admin":
    //    QList<User *> list;
    //    User user;
    //    User *pUser1 = &user;
    //    pUser1->setLogin("admin1");
    //    QByteArray passByteArray1;
    //    QString passHash1 = QString(QCryptographicHash::hash(passByteArray1.append("Admin11"), QCryptographicHash::Md5).toHex());
    //    pUser1->setPassword(passHash1);
    //    pUser1->setFirstName("FirstName1");
    //    pUser1->setLastName("LastName1");
    //    pUser1->setEmail("admin1@gmail.com");
    //    pUser1->setIdUser(0);
    //    pUser1->setRole("Admin");

    //    list.append(pUser1);
    //    login.createFileUsersList(list);

        User *pUser = login.getLoggedUser(ui->lineEditLogin->text(), ui->lineEditPassword->text());
        if(pUser != nullptr){
            ServiceWindow *mw = new ServiceWindow(pUser);
            mw->show();
            LoginWindow::close();
        } else {
            msg.setText("Błędny login lub hasło!");
            msg.setWindowTitle("Błąd logowania!");
            msg.exec();
        }
}
