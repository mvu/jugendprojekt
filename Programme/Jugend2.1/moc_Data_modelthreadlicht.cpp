/****************************************************************************
** Meta object code from reading C++ file 'Data_modelthreadlicht.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Data_modelthreadlicht.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Data_modelthreadlicht.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModelThreadLicht_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelThreadLicht_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelThreadLicht_t qt_meta_stringdata_ModelThreadLicht = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ModelThreadLicht"
QT_MOC_LITERAL(1, 17, 13), // "getHauptlicht"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "val"
QT_MOC_LITERAL(4, 36, 15), // "getStatusRelais"
QT_MOC_LITERAL(5, 52, 13), // "mainInfoCheck"
QT_MOC_LITERAL(6, 66, 17), // "getHauptlichtslot"
QT_MOC_LITERAL(7, 84, 19) // "getStatusRelaisslot"

    },
    "ModelThreadLicht\0getHauptlicht\0\0val\0"
    "getStatusRelais\0mainInfoCheck\0"
    "getHauptlichtslot\0getStatusRelaisslot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelThreadLicht[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   45,    2, 0x0a /* Public */,
       6,    1,   46,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void ModelThreadLicht::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelThreadLicht *_t = static_cast<ModelThreadLicht *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getHauptlicht((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getStatusRelais((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mainInfoCheck(); break;
        case 3: _t->getHauptlichtslot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getStatusRelaisslot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModelThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelThreadLicht::getHauptlicht)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ModelThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelThreadLicht::getStatusRelais)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ModelThreadLicht::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ModelThreadLicht.data,
      qt_meta_data_ModelThreadLicht,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModelThreadLicht::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelThreadLicht::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModelThreadLicht.stringdata0))
        return static_cast<void*>(const_cast< ModelThreadLicht*>(this));
    return QThread::qt_metacast(_clname);
}

int ModelThreadLicht::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ModelThreadLicht::getHauptlicht(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModelThreadLicht::getStatusRelais(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
