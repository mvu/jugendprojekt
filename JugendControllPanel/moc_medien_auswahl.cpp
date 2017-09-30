/****************************************************************************
** Meta object code from reading C++ file 'medien_auswahl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "medien_auswahl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'medien_auswahl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Medien_auswahl_t {
    QByteArrayData data[11];
    char stringdata[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Medien_auswahl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Medien_auswahl_t qt_meta_stringdata_Medien_auswahl = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 6),
QT_MOC_LITERAL(4, 36, 8),
QT_MOC_LITERAL(5, 45, 11),
QT_MOC_LITERAL(6, 57, 27),
QT_MOC_LITERAL(7, 85, 28),
QT_MOC_LITERAL(8, 114, 28),
QT_MOC_LITERAL(9, 143, 7),
QT_MOC_LITERAL(10, 151, 24)
    },
    "Medien_auswahl\0ParentEnable\0\0beamer\0"
    "pc_pulse\0time_update\0on_pushButton_back_released\0"
    "on_pushButton_Audio_released\0"
    "on_pushButton_Beamer_toggled\0checked\0"
    "on_pushButton_PC_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Medien_auswahl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       4,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   59,    2, 0x08 /* Private */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    1,   62,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void Medien_auswahl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Medien_auswahl *_t = static_cast<Medien_auswahl *>(_o);
        switch (_id) {
        case 0: _t->ParentEnable(); break;
        case 1: _t->beamer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->pc_pulse(); break;
        case 3: _t->time_update(); break;
        case 4: _t->on_pushButton_back_released(); break;
        case 5: _t->on_pushButton_Audio_released(); break;
        case 6: _t->on_pushButton_Beamer_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_PC_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Medien_auswahl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Medien_auswahl::ParentEnable)) {
                *result = 0;
            }
        }
        {
            typedef void (Medien_auswahl::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Medien_auswahl::beamer)) {
                *result = 1;
            }
        }
        {
            typedef void (Medien_auswahl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Medien_auswahl::pc_pulse)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Medien_auswahl::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Medien_auswahl.data,
      qt_meta_data_Medien_auswahl,  qt_static_metacall, 0, 0}
};


const QMetaObject *Medien_auswahl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Medien_auswahl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Medien_auswahl.stringdata))
        return static_cast<void*>(const_cast< Medien_auswahl*>(this));
    return QDialog::qt_metacast(_clname);
}

int Medien_auswahl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Medien_auswahl::ParentEnable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Medien_auswahl::beamer(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Medien_auswahl::pc_pulse()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
