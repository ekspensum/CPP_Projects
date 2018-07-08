/****************************************************************************
** Meta object code from reading C++ file 'wypozyczalnia.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wypozyczalnia.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wypozyczalnia.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Wypozyczalnia_t {
    QByteArrayData data[14];
    char stringdata0[432];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Wypozyczalnia_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Wypozyczalnia_t qt_meta_stringdata_Wypozyczalnia = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Wypozyczalnia"
QT_MOC_LITERAL(1, 14, 37), // "on_pushButtonDodajUzytkownika..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 30), // "on_pushButtonDodajFilm_clicked"
QT_MOC_LITERAL(4, 84, 39), // "on_pushButtonWyszukajRokGatun..."
QT_MOC_LITERAL(5, 124, 38), // "on_pushButtonWyszukajTytulOpi..."
QT_MOC_LITERAL(6, 163, 33), // "on_pushButtonDodajKlienta_cli..."
QT_MOC_LITERAL(7, 197, 36), // "on_pushButtonWyszukajKlienta_..."
QT_MOC_LITERAL(8, 234, 31), // "on_pushButtonRezerwacja_clicked"
QT_MOC_LITERAL(9, 266, 33), // "on_pushButtonWypozyczenie_cli..."
QT_MOC_LITERAL(10, 300, 50), // "on_pushButtonWyszukajWypozycz..."
QT_MOC_LITERAL(11, 351, 44), // "on_lineEditNazwiskoWyszukajZw..."
QT_MOC_LITERAL(12, 396, 8), // "nazwisko"
QT_MOC_LITERAL(13, 405, 26) // "on_pushButtonZwrot_clicked"

    },
    "Wypozyczalnia\0on_pushButtonDodajUzytkownika_clicked\0"
    "\0on_pushButtonDodajFilm_clicked\0"
    "on_pushButtonWyszukajRokGatunek_clicked\0"
    "on_pushButtonWyszukajTytulOpis_clicked\0"
    "on_pushButtonDodajKlienta_clicked\0"
    "on_pushButtonWyszukajKlienta_clicked\0"
    "on_pushButtonRezerwacja_clicked\0"
    "on_pushButtonWypozyczenie_clicked\0"
    "on_pushButtonWyszukajWypozyczoneKlientFilm_clicked\0"
    "on_lineEditNazwiskoWyszukajZwrot_textChanged\0"
    "nazwisko\0on_pushButtonZwrot_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Wypozyczalnia[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void Wypozyczalnia::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Wypozyczalnia *_t = static_cast<Wypozyczalnia *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonDodajUzytkownika_clicked(); break;
        case 1: _t->on_pushButtonDodajFilm_clicked(); break;
        case 2: _t->on_pushButtonWyszukajRokGatunek_clicked(); break;
        case 3: _t->on_pushButtonWyszukajTytulOpis_clicked(); break;
        case 4: _t->on_pushButtonDodajKlienta_clicked(); break;
        case 5: _t->on_pushButtonWyszukajKlienta_clicked(); break;
        case 6: _t->on_pushButtonRezerwacja_clicked(); break;
        case 7: _t->on_pushButtonWypozyczenie_clicked(); break;
        case 8: _t->on_pushButtonWyszukajWypozyczoneKlientFilm_clicked(); break;
        case 9: _t->on_lineEditNazwiskoWyszukajZwrot_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_pushButtonZwrot_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Wypozyczalnia::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Wypozyczalnia.data,
      qt_meta_data_Wypozyczalnia,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Wypozyczalnia::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Wypozyczalnia::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Wypozyczalnia.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Wypozyczalnia::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
