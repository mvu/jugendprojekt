/****************************************************************************
** Meta object code from reading C++ file 'MainVisu_rgbwand.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainVisu_rgbwand.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainVisu_rgbwand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RgbWand_t {
    QByteArrayData data[12];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RgbWand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RgbWand_t qt_meta_stringdata_RgbWand = {
    {
QT_MOC_LITERAL(0, 0, 7), // "RgbWand"
QT_MOC_LITERAL(1, 8, 10), // "wandRGBrot"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "wandRGBblau"
QT_MOC_LITERAL(4, 32, 12), // "wandRGBgreun"
QT_MOC_LITERAL(5, 45, 17), // "SliderChanged_ROT"
QT_MOC_LITERAL(6, 63, 5), // "value"
QT_MOC_LITERAL(7, 69, 17), // "SliderChanged_GRN"
QT_MOC_LITERAL(8, 87, 18), // "SliderChanged_BLAU"
QT_MOC_LITERAL(9, 106, 27), // "on_pushButton_back_released"
QT_MOC_LITERAL(10, 134, 28), // "on_pushButton_einst_released"
QT_MOC_LITERAL(11, 163, 29) // "on_pushButton_toggle_released"

    },
    "RgbWand\0wandRGBrot\0\0wandRGBblau\0"
    "wandRGBgreun\0SliderChanged_ROT\0value\0"
    "SliderChanged_GRN\0SliderChanged_BLAU\0"
    "on_pushButton_back_released\0"
    "on_pushButton_einst_released\0"
    "on_pushButton_toggle_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RgbWand[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       3,    2,   64,    2, 0x06 /* Public */,
       4,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   74,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RgbWand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RgbWand *_t = static_cast<RgbWand *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->wandRGBrot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->wandRGBblau((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->wandRGBgreun((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->SliderChanged_ROT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SliderChanged_GRN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SliderChanged_BLAU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_back_released(); break;
        case 7: _t->on_pushButton_einst_released(); break;
        case 8: _t->on_pushButton_toggle_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RgbWand::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RgbWand::wandRGBrot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RgbWand::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RgbWand::wandRGBblau)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RgbWand::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RgbWand::wandRGBgreun)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject RgbWand::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RgbWand.data,
      qt_meta_data_RgbWand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RgbWand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RgbWand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RgbWand.stringdata0))
        return static_cast<void*>(const_cast< RgbWand*>(this));
    return QDialog::qt_metacast(_clname);
}

int RgbWand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RgbWand::wandRGBrot(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RgbWand::wandRGBblau(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RgbWand::wandRGBgreun(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
