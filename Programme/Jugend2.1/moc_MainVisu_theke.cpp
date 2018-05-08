/****************************************************************************
** Meta object code from reading C++ file 'MainVisu_theke.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainVisu_theke.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainVisu_theke.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Theke_t {
    QByteArrayData data[20];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Theke_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Theke_t qt_meta_stringdata_Theke = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Theke"
QT_MOC_LITERAL(1, 6, 11), // "thekeRGBrot"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 1), // "r"
QT_MOC_LITERAL(4, 21, 3), // "val"
QT_MOC_LITERAL(5, 25, 12), // "thekeRGBblau"
QT_MOC_LITERAL(6, 38, 1), // "b"
QT_MOC_LITERAL(7, 40, 13), // "thekeRGBgruen"
QT_MOC_LITERAL(8, 54, 1), // "g"
QT_MOC_LITERAL(9, 56, 11), // "thekeRGBall"
QT_MOC_LITERAL(10, 68, 16), // "thekeDeckeToggle"
QT_MOC_LITERAL(11, 85, 12), // "parentEnable"
QT_MOC_LITERAL(12, 98, 17), // "SliderChanged_ROT"
QT_MOC_LITERAL(13, 116, 17), // "SliderChanged_GRN"
QT_MOC_LITERAL(14, 134, 18), // "SliderChanged_BLAU"
QT_MOC_LITERAL(15, 153, 14), // "afterAnimation"
QT_MOC_LITERAL(16, 168, 32), // "on_pushButton_rgb_togge_released"
QT_MOC_LITERAL(17, 201, 30), // "on_pushButton_rgb_set_released"
QT_MOC_LITERAL(18, 232, 27), // "on_pushButton_back_released"
QT_MOC_LITERAL(19, 260, 22) // "on_pushButton_released"

    },
    "Theke\0thekeRGBrot\0\0r\0val\0thekeRGBblau\0"
    "b\0thekeRGBgruen\0g\0thekeRGBall\0"
    "thekeDeckeToggle\0parentEnable\0"
    "SliderChanged_ROT\0SliderChanged_GRN\0"
    "SliderChanged_BLAU\0afterAnimation\0"
    "on_pushButton_rgb_togge_released\0"
    "on_pushButton_rgb_set_released\0"
    "on_pushButton_back_released\0"
    "on_pushButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Theke[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    2,   89,    2, 0x06 /* Public */,
       7,    2,   94,    2, 0x06 /* Public */,
       9,    3,   99,    2, 0x06 /* Public */,
      10,    1,  106,    2, 0x06 /* Public */,
      11,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  110,    2, 0x08 /* Private */,
      13,    1,  113,    2, 0x08 /* Private */,
      14,    1,  116,    2, 0x08 /* Private */,
      15,    0,  119,    2, 0x08 /* Private */,
      16,    0,  120,    2, 0x08 /* Private */,
      17,    0,  121,    2, 0x08 /* Private */,
      18,    0,  122,    2, 0x08 /* Private */,
      19,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Theke::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Theke *_t = static_cast<Theke *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->thekeRGBrot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->thekeRGBblau((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->thekeRGBgruen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->thekeRGBall((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->thekeDeckeToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->parentEnable(); break;
        case 6: _t->SliderChanged_ROT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SliderChanged_GRN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SliderChanged_BLAU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->afterAnimation(); break;
        case 10: _t->on_pushButton_rgb_togge_released(); break;
        case 11: _t->on_pushButton_rgb_set_released(); break;
        case 12: _t->on_pushButton_back_released(); break;
        case 13: _t->on_pushButton_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Theke::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBrot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Theke::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBblau)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Theke::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBgruen)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Theke::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBall)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Theke::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeDeckeToggle)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Theke::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::parentEnable)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Theke::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Theke.data,
      qt_meta_data_Theke,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Theke::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Theke::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Theke.stringdata0))
        return static_cast<void*>(const_cast< Theke*>(this));
    return QDialog::qt_metacast(_clname);
}

int Theke::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Theke::thekeRGBrot(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Theke::thekeRGBblau(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Theke::thekeRGBgruen(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Theke::thekeRGBall(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Theke::thekeDeckeToggle(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Theke::parentEnable()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
