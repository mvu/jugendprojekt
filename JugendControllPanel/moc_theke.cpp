/****************************************************************************
** Meta object code from reading C++ file 'theke.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "theke.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'theke.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Theke_t {
    QByteArrayData data[19];
    char stringdata[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Theke_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Theke_t qt_meta_stringdata_Theke = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 11),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 1),
QT_MOC_LITERAL(4, 21, 3),
QT_MOC_LITERAL(5, 25, 12),
QT_MOC_LITERAL(6, 38, 1),
QT_MOC_LITERAL(7, 40, 13),
QT_MOC_LITERAL(8, 54, 1),
QT_MOC_LITERAL(9, 56, 11),
QT_MOC_LITERAL(10, 68, 16),
QT_MOC_LITERAL(11, 85, 17),
QT_MOC_LITERAL(12, 103, 17),
QT_MOC_LITERAL(13, 121, 18),
QT_MOC_LITERAL(14, 140, 14),
QT_MOC_LITERAL(15, 155, 32),
QT_MOC_LITERAL(16, 188, 30),
QT_MOC_LITERAL(17, 219, 27),
QT_MOC_LITERAL(18, 247, 22)
    },
    "Theke\0thekeRGBrot\0\0r\0val\0thekeRGBblau\0"
    "b\0thekeRGBgruen\0g\0thekeRGBall\0"
    "thekeDeckeToggle\0SliderChanged_ROT\0"
    "SliderChanged_GRN\0SliderChanged_BLAU\0"
    "afterAnimation\0on_pushButton_rgb_togge_released\0"
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    2,   84,    2, 0x06 /* Public */,
       7,    2,   89,    2, 0x06 /* Public */,
       9,    3,   94,    2, 0x06 /* Public */,
      10,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  104,    2, 0x08 /* Private */,
      12,    1,  107,    2, 0x08 /* Private */,
      13,    1,  110,    2, 0x08 /* Private */,
      14,    0,  113,    2, 0x08 /* Private */,
      15,    0,  114,    2, 0x08 /* Private */,
      16,    0,  115,    2, 0x08 /* Private */,
      17,    0,  116,    2, 0x08 /* Private */,
      18,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,

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
        switch (_id) {
        case 0: _t->thekeRGBrot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->thekeRGBblau((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->thekeRGBgruen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->thekeRGBall((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->thekeDeckeToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->SliderChanged_ROT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SliderChanged_GRN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SliderChanged_BLAU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->afterAnimation(); break;
        case 9: _t->on_pushButton_rgb_togge_released(); break;
        case 10: _t->on_pushButton_rgb_set_released(); break;
        case 11: _t->on_pushButton_back_released(); break;
        case 12: _t->on_pushButton_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Theke::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBrot)) {
                *result = 0;
            }
        }
        {
            typedef void (Theke::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBblau)) {
                *result = 1;
            }
        }
        {
            typedef void (Theke::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBgruen)) {
                *result = 2;
            }
        }
        {
            typedef void (Theke::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeRGBall)) {
                *result = 3;
            }
        }
        {
            typedef void (Theke::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Theke::thekeDeckeToggle)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Theke::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Theke.data,
      qt_meta_data_Theke,  qt_static_metacall, 0, 0}
};


const QMetaObject *Theke::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Theke::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Theke.stringdata))
        return static_cast<void*>(const_cast< Theke*>(this));
    return QDialog::qt_metacast(_clname);
}

int Theke::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Theke::thekeRGBrot(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Theke::thekeRGBblau(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Theke::thekeRGBgruen(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Theke::thekeRGBall(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Theke::thekeDeckeToggle(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
