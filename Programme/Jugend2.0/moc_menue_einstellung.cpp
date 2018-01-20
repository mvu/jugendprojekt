/****************************************************************************
** Meta object code from reading C++ file 'menue_einstellung.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menue_einstellung.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menue_einstellung.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Menue_Einstellung_t {
    QByteArrayData data[13];
    char stringdata[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menue_Einstellung_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menue_Einstellung_t qt_meta_stringdata_Menue_Einstellung = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 12),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 13),
QT_MOC_LITERAL(4, 46, 11),
QT_MOC_LITERAL(5, 58, 35),
QT_MOC_LITERAL(6, 94, 31),
QT_MOC_LITERAL(7, 126, 30),
QT_MOC_LITERAL(8, 157, 30),
QT_MOC_LITERAL(9, 188, 33),
QT_MOC_LITERAL(10, 222, 27),
QT_MOC_LITERAL(11, 250, 28),
QT_MOC_LITERAL(12, 279, 11)
    },
    "Menue_Einstellung\0ParentEnable\0\0"
    "PaletteToggle\0EnableMenue\0"
    "on_pushButton_hauptlicht_2_released\0"
    "on_pushButton_RGBdecke_released\0"
    "on_pushButton_Theke_2_released\0"
    "on_pushButton_palette_released\0"
    "on_pushButton_RGBfenster_released\0"
    "on_pushButton_save_released\0"
    "on_pushButton_close_released\0time_update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menue_Einstellung[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   73,    2, 0x0a /* Public */,
       5,    0,   74,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Menue_Einstellung::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Menue_Einstellung *_t = static_cast<Menue_Einstellung *>(_o);
        switch (_id) {
        case 0: _t->ParentEnable(); break;
        case 1: _t->PaletteToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->EnableMenue(); break;
        case 3: _t->on_pushButton_hauptlicht_2_released(); break;
        case 4: _t->on_pushButton_RGBdecke_released(); break;
        case 5: _t->on_pushButton_Theke_2_released(); break;
        case 6: _t->on_pushButton_palette_released(); break;
        case 7: _t->on_pushButton_RGBfenster_released(); break;
        case 8: _t->on_pushButton_save_released(); break;
        case 9: _t->on_pushButton_close_released(); break;
        case 10: _t->time_update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Menue_Einstellung::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Menue_Einstellung::ParentEnable)) {
                *result = 0;
            }
        }
        {
            typedef void (Menue_Einstellung::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Menue_Einstellung::PaletteToggle)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Menue_Einstellung::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Menue_Einstellung.data,
      qt_meta_data_Menue_Einstellung,  qt_static_metacall, 0, 0}
};


const QMetaObject *Menue_Einstellung::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menue_Einstellung::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Menue_Einstellung.stringdata))
        return static_cast<void*>(const_cast< Menue_Einstellung*>(this));
    return QDialog::qt_metacast(_clname);
}

int Menue_Einstellung::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Menue_Einstellung::ParentEnable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Menue_Einstellung::PaletteToggle(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
