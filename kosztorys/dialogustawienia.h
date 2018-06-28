#ifndef DIALOGUSTAWIENIA_H
#define DIALOGUSTAWIENIA_H

#include <QDialog>

namespace Ui {
class DialogUstawienia;
}

class DialogUstawienia : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUstawienia(QWidget *parent = 0);
    ~DialogUstawienia();

private:
    Ui::DialogUstawienia *ui;
};

#endif // DIALOGUSTAWIENIA_H
