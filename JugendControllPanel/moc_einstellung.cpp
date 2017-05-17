/****************************************************************************
** Meta object code from reading C++ file 'einstellung.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "einstellung.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'einstellung.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Einstellung_t {
    QByteArrayData data[18];
    char stringdata[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Einstellung_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Einstellung_t qt_meta_stringdata_Einstellung = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 18),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 3),
QT_MOC_LITERAL(4, 36, 20),
QT_MOC_LITERAL(5, 57, 21),
QT_MOC_LITERAL(6, 79, 18),
QT_MOC_LITERAL(7, 98, 20),
QT_MOC_LITERAL(8, 119, 21),
QT_MOC_LITERAL(9, 141, 12),
QT_MOC_LITERAL(10, 154, 8),
QT_MOC_LITERAL(11, 163, 14),
QT_MOC_LITERAL(12, 178, 27),
QT_MOC_LITERAL(13, 206, 26),
QT_MOC_LITERAL(14, 233, 12),
QT_MOC_LITERAL(15, 246, 16),
QT_MOC_LITERAL(16, 263, 15),
QT_MOC_LITERAL(17, 279, 10)
    },
    "Einstellung\0luefterSetNetzteil\0\0val\0"
    "luefterSetController\0luefterSetAusgangOben\0"
    "getLuefterNetzteil\0getLuefterController\0"
    "getLuefterAusgangOben\0ParentEnable\0"
    "Shutdown\0afterAnimation\0"
    "on_pushButton_back_released\0"
    "on_pushButton_Off_released\0TempRaum_neu\0"
    "TempNetzteil_neu\0TempPlatine_neu\0"
    "TempPi_neu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Einstellung[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,
       7,    0,   99,    2, 0x06 /* Public */,
       8,    0,  100,    2, 0x06 /* Public */,
       9,    0,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    1,  106,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    1,  112,    2, 0x08 /* Private */,
      17,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,

       0        // eod
};

void Einstellung::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Einstellung *_t = static_cast<Einstellung *>(_o);
        switch (_id) {
        case 0: _t->luefterSetNetzteil((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->luefterSetController((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->luefterSetAusgangOben((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->getLuefterNetzteil(); break;
        case 4: _t->getLuefterController(); break;
        case 5: _t->getLuefterAusgangOben(); break;
        case 6: _t->ParentEnable(); break;
        case 7: _t->Shutdown(); break;
        case 8: _t->afterAnimation(); break;
        case 9: _t->on_pushButton_back_released(); break;
        case 10: _t->on_pushButton_Off_released(); break;
        case 11: _t->TempRaum_neu((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->TempNetzteil_neu((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: _t->TempPlatine_neu((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->TempPi_neu((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Einstellung::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Einstellung::luefterSetNetzteil)) {
                *result = 0;
            }
        }
        {
            typedef void (Einstellung::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Einstellung::luefterSetController)) {
                *result = 1;
            }
        }
        {
            typedef void (Einstellung::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Einstellung::luefterSetAusgangOben)) {
                *result = 2;
            }
        }
        {
            typedef void (Einstellung::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Einstellung::getLuefterNetzteil)) {
                *result = 3;
            }
        }
        {
            typedef void (Einstellung::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Einstellung::getLuefterController)) {
                *result = 4;
            }
        }
        {
            typedef void (Einstellung::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Einstellung::getLuefterAusgangOben)) {
                *result = 5;
            }
        }
        {
            typedef void (Einstellung::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Einstellung::ParentEnable)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject Einstellung::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Einstellung.data,
      qt_meta_data_Einstellung,  qt_static_metacall, 0, 0}
};


const QMetaObject *Einstellung::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Einstellung::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Einstellung.stringdata))
        return static_cast<void*>(const_cast< Einstellung*>(this));
    return QDialog::qt_metacast(_clname);
}

int Einstellung::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Einstellung::luefterSetNetzteil(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Einstellung::luefterSetController(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Einstellung::luefterSetAusgangOben(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Einstellung::getLuefterNetzteil()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Einstellung::getLuefterController()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Einstellung::getLuefterAusgangOben()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Einstellung::ParentEnable()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
