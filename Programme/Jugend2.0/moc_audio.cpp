/****************************************************************************
** Meta object code from reading C++ file 'audio.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "audio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Audio_t {
    QByteArrayData data[15];
    char stringdata[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Audio_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Audio_t qt_meta_stringdata_Audio = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 6),
QT_MOC_LITERAL(2, 13, 0),
QT_MOC_LITERAL(3, 14, 2),
QT_MOC_LITERAL(4, 17, 12),
QT_MOC_LITERAL(5, 30, 25),
QT_MOC_LITERAL(6, 56, 33),
QT_MOC_LITERAL(7, 90, 27),
QT_MOC_LITERAL(8, 118, 27),
QT_MOC_LITERAL(9, 146, 7),
QT_MOC_LITERAL(10, 154, 39),
QT_MOC_LITERAL(11, 194, 40),
QT_MOC_LITERAL(12, 235, 38),
QT_MOC_LITERAL(13, 274, 24),
QT_MOC_LITERAL(14, 299, 14)
    },
    "Audio\0beamer\0\0pc\0ParentEnable\0"
    "on_pushButtonAUX_released\0"
    "on_pushButtonPlaystation_released\0"
    "on_pushButton_back_released\0"
    "on_pushButton_OnOff_toggled\0checked\0"
    "on_pushButtonLautstaerke_Leise_released\0"
    "on_pushButtonLautstaerke_Mittel_released\0"
    "on_pushButtonLautstaerke_Laut_released\0"
    "on_pushButtonPC_released\0afterAnimation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Audio[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   79,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    1,   82,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Audio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Audio *_t = static_cast<Audio *>(_o);
        switch (_id) {
        case 0: _t->beamer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->pc(); break;
        case 2: _t->ParentEnable(); break;
        case 3: _t->on_pushButtonAUX_released(); break;
        case 4: _t->on_pushButtonPlaystation_released(); break;
        case 5: _t->on_pushButton_back_released(); break;
        case 6: _t->on_pushButton_OnOff_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonLautstaerke_Leise_released(); break;
        case 8: _t->on_pushButtonLautstaerke_Mittel_released(); break;
        case 9: _t->on_pushButtonLautstaerke_Laut_released(); break;
        case 10: _t->on_pushButtonPC_released(); break;
        case 11: _t->afterAnimation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Audio::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Audio::beamer)) {
                *result = 0;
            }
        }
        {
            typedef void (Audio::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Audio::pc)) {
                *result = 1;
            }
        }
        {
            typedef void (Audio::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Audio::ParentEnable)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Audio::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Audio.data,
      qt_meta_data_Audio,  qt_static_metacall, 0, 0}
};


const QMetaObject *Audio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Audio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Audio.stringdata))
        return static_cast<void*>(const_cast< Audio*>(this));
    return QDialog::qt_metacast(_clname);
}

int Audio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Audio::beamer(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Audio::pc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Audio::ParentEnable()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
