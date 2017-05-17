/****************************************************************************
** Meta object code from reading C++ file 'licht.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "licht.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'licht.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Licht_t {
    QByteArrayData data[14];
    char stringdata[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Licht_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Licht_t qt_meta_stringdata_Licht = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 13),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 16),
QT_MOC_LITERAL(4, 38, 16),
QT_MOC_LITERAL(5, 55, 11),
QT_MOC_LITERAL(6, 67, 8),
QT_MOC_LITERAL(7, 76, 32),
QT_MOC_LITERAL(8, 109, 27),
QT_MOC_LITERAL(9, 137, 7),
QT_MOC_LITERAL(10, 145, 30),
QT_MOC_LITERAL(11, 176, 26),
QT_MOC_LITERAL(12, 203, 30),
QT_MOC_LITERAL(13, 234, 30)
    },
    "Licht\0jugendLichtOn\0\0teenkreisLichtOn\0"
    "praistimeLichtOn\0kinoLichtOn\0lichtAus\0"
    "on_pushButtonEinstellung_clicked\0"
    "on_pushButtonJugend_toggled\0checked\0"
    "on_pushButtonTeenkreis_toggled\0"
    "on_pushButtonMovie_toggled\0"
    "on_pushButtonPraisTime_toggled\0"
    "on_pushButtonLichtAus_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Licht[] = {

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
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      11,    1,   81,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,

       0        // eod
};

void Licht::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Licht *_t = static_cast<Licht *>(_o);
        switch (_id) {
        case 0: _t->jugendLichtOn(); break;
        case 1: _t->teenkreisLichtOn(); break;
        case 2: _t->praistimeLichtOn(); break;
        case 3: _t->kinoLichtOn(); break;
        case 4: _t->lichtAus(); break;
        case 5: _t->on_pushButtonEinstellung_clicked(); break;
        case 6: _t->on_pushButtonJugend_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonTeenkreis_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonMovie_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_pushButtonPraisTime_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_pushButtonLichtAus_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Licht::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Licht::jugendLichtOn)) {
                *result = 0;
            }
        }
        {
            typedef void (Licht::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Licht::teenkreisLichtOn)) {
                *result = 1;
            }
        }
        {
            typedef void (Licht::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Licht::praistimeLichtOn)) {
                *result = 2;
            }
        }
        {
            typedef void (Licht::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Licht::kinoLichtOn)) {
                *result = 3;
            }
        }
        {
            typedef void (Licht::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Licht::lichtAus)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Licht::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Licht.data,
      qt_meta_data_Licht,  qt_static_metacall, 0, 0}
};


const QMetaObject *Licht::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Licht::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Licht.stringdata))
        return static_cast<void*>(const_cast< Licht*>(this));
    return QDialog::qt_metacast(_clname);
}

int Licht::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void Licht::jugendLichtOn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Licht::teenkreisLichtOn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Licht::praistimeLichtOn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Licht::kinoLichtOn()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Licht::lichtAus()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
