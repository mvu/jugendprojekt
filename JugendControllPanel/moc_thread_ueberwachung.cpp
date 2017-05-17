/****************************************************************************
** Meta object code from reading C++ file 'thread_ueberwachung.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "thread_ueberwachung.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thread_ueberwachung.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_thread_Ueberwachung_t {
    QByteArrayData data[16];
    char stringdata[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_thread_Ueberwachung_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_thread_Ueberwachung_t qt_meta_stringdata_thread_Ueberwachung = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 13),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 20),
QT_MOC_LITERAL(4, 56, 24),
QT_MOC_LITERAL(5, 81, 16),
QT_MOC_LITERAL(6, 98, 19),
QT_MOC_LITERAL(7, 118, 10),
QT_MOC_LITERAL(8, 129, 6),
QT_MOC_LITERAL(9, 136, 3),
QT_MOC_LITERAL(10, 140, 11),
QT_MOC_LITERAL(11, 152, 6),
QT_MOC_LITERAL(12, 159, 7),
QT_MOC_LITERAL(13, 167, 10),
QT_MOC_LITERAL(14, 178, 17),
QT_MOC_LITERAL(15, 196, 9)
    },
    "thread_Ueberwachung\0TempPiChanged\0\0"
    "TempNetzteileChanged\0TempSteuerplatineChanged\0"
    "TempDeckeChanged\0WandschalterPressed\0"
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
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,
       6,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   84,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x0a /* Public */,
      12,    1,   92,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Float, QMetaType::Int,   11,
    QMetaType::Float, QMetaType::Int,   11,
    QMetaType::Float,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void thread_Ueberwachung::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        thread_Ueberwachung *_t = static_cast<thread_Ueberwachung *>(_o);
        switch (_id) {
        case 0: _t->TempPiChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->TempNetzteileChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->TempSteuerplatineChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->TempDeckeChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->WandschalterPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setLuefter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: { float _r = _t->requestTemp((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 7: { float _r = _t->getTemp((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 8: { float _r = _t->getTemp_pi();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->checkWandschalter();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: _t->checkTemp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (thread_Ueberwachung::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempPiChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempNetzteileChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempSteuerplatineChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::TempDeckeChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (thread_Ueberwachung::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&thread_Ueberwachung::WandschalterPressed)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject thread_Ueberwachung::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_thread_Ueberwachung.data,
      qt_meta_data_thread_Ueberwachung,  qt_static_metacall, 0, 0}
};


const QMetaObject *thread_Ueberwachung::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *thread_Ueberwachung::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_thread_Ueberwachung.stringdata))
        return static_cast<void*>(const_cast< thread_Ueberwachung*>(this));
    return QThread::qt_metacast(_clname);
}

int thread_Ueberwachung::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void thread_Ueberwachung::TempPiChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void thread_Ueberwachung::TempNetzteileChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void thread_Ueberwachung::TempSteuerplatineChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void thread_Ueberwachung::TempDeckeChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void thread_Ueberwachung::WandschalterPressed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
