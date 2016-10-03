/****************************************************************************
** Meta object code from reading C++ file 'licht.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "licht.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'licht.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Licht_t {
    QByteArrayData data[7];
    char stringdata[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Licht_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Licht_t qt_meta_stringdata_Licht = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 27),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 30),
QT_MOC_LITERAL(4, 66, 30),
QT_MOC_LITERAL(5, 97, 26),
QT_MOC_LITERAL(6, 124, 32)
    },
    "Licht\0on_pushButtonJugend_clicked\0\0"
    "on_pushButtonTeenkreis_clicked\0"
    "on_pushButtonPraisTime_clicked\0"
    "on_pushButtonMovie_clicked\0"
    "on_pushButtonEinstellung_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Licht[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Licht::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Licht *_t = static_cast<Licht *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonJugend_clicked(); break;
        case 1: _t->on_pushButtonTeenkreis_clicked(); break;
        case 2: _t->on_pushButtonPraisTime_clicked(); break;
        case 3: _t->on_pushButtonMovie_clicked(); break;
        case 4: _t->on_pushButtonEinstellung_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Licht::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Licht.data,
      qt_meta_data_Licht,  qt_static_metacall, 0, 0}
};


const QMetaObject *Licht::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Licht::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Licht.stringdata))
        return static_cast<void*>(const_cast< Licht*>(this));
    return QDialog::qt_metacast(_clname);
}

int Licht::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
