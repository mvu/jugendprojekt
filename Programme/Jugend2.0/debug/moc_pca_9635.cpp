/****************************************************************************
** Meta object code from reading C++ file 'pca_9635.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pca_9635.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pca_9635.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_pca_9635_t {
    QByteArrayData data[13];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pca_9635_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pca_9635_t qt_meta_stringdata_pca_9635 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "pca_9635"
QT_MOC_LITERAL(1, 9, 15), // "pca9635PWMWrite"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "fd"
QT_MOC_LITERAL(4, 29, 3), // "pin"
QT_MOC_LITERAL(5, 33, 3), // "pwm"
QT_MOC_LITERAL(6, 37, 15), // "pca9635PWMReset"
QT_MOC_LITERAL(7, 53, 14), // "pca9635PWMRead"
QT_MOC_LITERAL(8, 68, 3), // "reg"
QT_MOC_LITERAL(9, 72, 12), // "pca9635Setup"
QT_MOC_LITERAL(10, 85, 10), // "i2cAddress"
QT_MOC_LITERAL(11, 96, 7), // "pcaInit"
QT_MOC_LITERAL(12, 104, 3) // "i2c"

    },
    "pca_9635\0pca9635PWMWrite\0\0fd\0pin\0pwm\0"
    "pca9635PWMReset\0pca9635PWMRead\0reg\0"
    "pca9635Setup\0i2cAddress\0pcaInit\0i2c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pca_9635[] = {

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
       1,    3,   39,    2, 0x0a /* Public */,
       6,    1,   46,    2, 0x0a /* Public */,
       7,    2,   49,    2, 0x0a /* Public */,
       9,    1,   54,    2, 0x0a /* Public */,
      11,    1,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    8,
    QMetaType::Int, QMetaType::Int,   10,
    QMetaType::Int, QMetaType::Int,   12,

       0        // eod
};

void pca_9635::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pca_9635 *_t = static_cast<pca_9635 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pca9635PWMWrite((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->pca9635PWMReset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->pca9635PWMRead((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->pca9635Setup((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->pcaInit((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject pca_9635::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pca_9635.data,
      qt_meta_data_pca_9635,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pca_9635::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pca_9635::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pca_9635.stringdata0))
        return static_cast<void*>(const_cast< pca_9635*>(this));
    return QObject::qt_metacast(_clname);
}

int pca_9635::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
