/****************************************************************************
** Meta object code from reading C++ file 'einstellunglicht.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "einstellunglicht.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'einstellunglicht.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EinstellungLicht_t {
    QByteArrayData data[13];
    char stringdata[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EinstellungLicht_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EinstellungLicht_t qt_meta_stringdata_EinstellungLicht = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 13),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 15),
QT_MOC_LITERAL(4, 48, 14),
QT_MOC_LITERAL(5, 63, 31),
QT_MOC_LITERAL(6, 95, 28),
QT_MOC_LITERAL(7, 124, 29),
QT_MOC_LITERAL(8, 154, 32),
QT_MOC_LITERAL(9, 187, 26),
QT_MOC_LITERAL(10, 214, 7),
QT_MOC_LITERAL(11, 222, 29),
QT_MOC_LITERAL(12, 252, 27)
    },
    "EinstellungLicht\0theke_toggled\0\0"
    "palette_toggled\0beamer_toggled\0"
    "on_pushButtonHauptlicht_clicked\0"
    "on_pushButtonRGBWand_clicked\0"
    "on_pushButtonRGBTheke_clicked\0"
    "on_pushButtonEinstellung_clicked\0"
    "on_pushButtonTheke_toggled\0checked\0"
    "on_pushButtonPaletten_toggled\0"
    "on_pushButtonBeamer_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EinstellungLicht[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       4,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   73,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void EinstellungLicht::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EinstellungLicht *_t = static_cast<EinstellungLicht *>(_o);
        switch (_id) {
        case 0: _t->theke_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->palette_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->beamer_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_pushButtonHauptlicht_clicked(); break;
        case 4: _t->on_pushButtonRGBWand_clicked(); break;
        case 5: _t->on_pushButtonRGBTheke_clicked(); break;
        case 6: _t->on_pushButtonEinstellung_clicked(); break;
        case 7: _t->on_pushButtonTheke_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonPaletten_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_pushButtonBeamer_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EinstellungLicht::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EinstellungLicht::theke_toggled)) {
                *result = 0;
            }
        }
        {
            typedef void (EinstellungLicht::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EinstellungLicht::palette_toggled)) {
                *result = 1;
            }
        }
        {
            typedef void (EinstellungLicht::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EinstellungLicht::beamer_toggled)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject EinstellungLicht::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EinstellungLicht.data,
      qt_meta_data_EinstellungLicht,  qt_static_metacall, 0, 0}
};


const QMetaObject *EinstellungLicht::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EinstellungLicht::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EinstellungLicht.stringdata))
        return static_cast<void*>(const_cast< EinstellungLicht*>(this));
    return QDialog::qt_metacast(_clname);
}

int EinstellungLicht::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void EinstellungLicht::theke_toggled(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EinstellungLicht::palette_toggled(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EinstellungLicht::beamer_toggled(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
