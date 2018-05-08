/****************************************************************************
** Meta object code from reading C++ file 'thread_ueberwachung.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "thread_ueberwachung.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thread_ueberwachung.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_thread_Ueberwachung_t {
    QByteArrayData data[18];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_thread_Ueberwachung_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_thread_Ueberwachung_t qt_meta_stringdata_thread_Ueberwachung = {
    {
QT_MOC_LITERAL(0, 0, 19), // "thread_Ueberwachung"
QT_MOC_LITERAL(1, 20, 13), // "TempPiChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "TempNetzteileChanged"
QT_MOC_LITERAL(4, 56, 24), // "TempSteuerplatineChanged"
QT_MOC_LITERAL(5, 81, 16), // "TempDeckeChanged"
QT_MOC_LITERAL(6, 98, 22), // "TempVerstaerkerChanged"
QT_MOC_LITERAL(7, 121, 13), // "TempPCChanged"
QT_MOC_LITERAL(8, 135, 19), // "WandschalterPressed"
QT_MOC_LITERAL(9, 155, 10), // "setLuefter"
QT_MOC_LITERAL(10, 166, 6), // "number"
QT_MOC_LITERAL(11, 173, 3), // "val"
QT_MOC_LITERAL(12, 177, 11), // "requestTemp"
QT_MOC_LITERAL(13, 189, 6), // "Sensor"
QT_MOC_LITERAL(14, 196, 7), // "getTemp"
QT_MOC_LITERAL(15, 204, 10), // "getTemp_pi"
QT_MOC_LITERAL(16, 215, 17), // "checkWandschalter"
QT_MOC_LITERAL(17, 233, 9) // "checkTemp"

    },
    "thread_Ueberwachung\0TempPiChanged\0\0"
    "TempNetzteileChanged\0TempSteuerplatineChanged\0"
    "TempDeckeChanged\0TempVerstaerkerChanged\0"
    "TempPCChanged\0WandschalterPressed\0"
    "setLuefter\0number\0val\0requestTemp\0"
    "Sensor\0getTemp\0getTemp_pi\0checkWandschalter\0"
    "checkTemp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_thread_Ueberwachung[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    2,   82,    2, 0x06 /* Public */,
       4,    2,   87,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,
       6,    2,   97,    2, 0x06 /* Public */,
       7,    1,  102,    2, 0x06 /* Public */,
       8,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,  108,    2, 0x0a /* Public */,
      12,    1,  113,    2, 0x0a /* Public */,
      14,    1,  116,    2, 0x08 /* Private */,
      15,    0,  119,    2, 0x08 /* Private */,
      16,    0,  120,    2, 0x08 /* Private */,
      17,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Float, QMetaType::Int,   13,
    QMetaType::Float, QMetaType::Int,   13,
    QMetaType::Float,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void thread_Ueberwachung::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        thread_Ueberwachung *_t = static_cast<thread_Ueberwachung *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TempPiChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->TempNetzteileChanged((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->TempSteuerplatineChanged((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->TempDeckeChanged((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->TempVerstaerkerChanged((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->TempPCChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->WandschalterPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setLuefter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: { float _r = _t->requestTemp((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 9: { float _r = _t->getTemp((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 10: { float _r = _t->getTemp_pi();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->checkWandschalter();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->checkTemp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (thread_Ueberwachung::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempPiChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempNetzteileChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempSteuerplatineChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempDeckeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempVerstaerkerChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempPCChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::WandschalterPressed)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject thread_Ueberwachung::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_thread_Ueberwachung.data,
      qt_meta_data_thread_Ueberwachung,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *thread_Ueberwachung::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *thread_Ueberwachung::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_thread_Ueberwachung.stringdata0))
        return static_cast<void*>(const_cast< thread_Ueberwachung*>(this));
    return QThread::qt_metacast(_clname);
}

int thread_Ueberwachung::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void thread_Ueberwachung::TempPiChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void thread_Ueberwachung::TempNetzteileChanged(float _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void thread_Ueberwachung::TempSteuerplatineChanged(float _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void thread_Ueberwachung::TempDeckeChanged(float _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void thread_Ueberwachung::TempVerstaerkerChanged(float _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void thread_Ueberwachung::TempPCChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void thread_Ueberwachung::WandschalterPressed(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
