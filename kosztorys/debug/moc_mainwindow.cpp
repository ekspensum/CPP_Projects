/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 32), // "on_pushButtonWstawWiersz_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 31), // "on_pushButtonUsunWiersz_clicked"
QT_MOC_LITERAL(4, 77, 25), // "on_actionZapisz_triggered"
QT_MOC_LITERAL(5, 103, 32), // "on_pushButtonDodajWiersz_clicked"
QT_MOC_LITERAL(6, 136, 25), // "on_actionOtworz_triggered"
QT_MOC_LITERAL(7, 162, 29), // "on_actionUstawienia_triggered"
QT_MOC_LITERAL(8, 192, 30), // "on_actionZapisz_jako_triggered"
QT_MOC_LITERAL(9, 223, 9), // "filtrItem"
QT_MOC_LITERAL(10, 233, 13), // "isNoEmptyItem"
QT_MOC_LITERAL(11, 247, 6), // "oblicz"
QT_MOC_LITERAL(12, 254, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(13, 272, 18), // "obliczPrzyOtwarciu"
QT_MOC_LITERAL(14, 291, 26), // "on_tableWidget_cellChanged"
QT_MOC_LITERAL(15, 318, 3), // "row"
QT_MOC_LITERAL(16, 322, 6) // "column"

    },
    "MainWindow\0on_pushButtonWstawWiersz_clicked\0"
    "\0on_pushButtonUsunWiersz_clicked\0"
    "on_actionZapisz_triggered\0"
    "on_pushButtonDodajWiersz_clicked\0"
    "on_actionOtworz_triggered\0"
    "on_actionUstawienia_triggered\0"
    "on_actionZapisz_jako_triggered\0filtrItem\0"
    "isNoEmptyItem\0oblicz\0QTableWidgetItem*\0"
    "obliczPrzyOtwarciu\0on_tableWidget_cellChanged\0"
    "row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    2,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonWstawWiersz_clicked(); break;
        case 1: _t->on_pushButtonUsunWiersz_clicked(); break;
        case 2: _t->on_actionZapisz_triggered(); break;
        case 3: _t->on_pushButtonDodajWiersz_clicked(); break;
        case 4: _t->on_actionOtworz_triggered(); break;
        case 5: _t->on_actionUstawienia_triggered(); break;
        case 6: _t->on_actionZapisz_jako_triggered(); break;
        case 7: { bool _r = _t->filtrItem();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->isNoEmptyItem();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->oblicz((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->obliczPrzyOtwarciu(); break;
        case 11: _t->on_tableWidget_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE