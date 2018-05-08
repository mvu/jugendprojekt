/****************************************************************************
** Meta object code from reading C++ file 'Steuer_steuerungthreadlicht.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Steuer_steuerungthreadlicht.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Steuer_steuerungthreadlicht.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_steuerungThreadLicht_t {
    QByteArrayData data[96];
    char stringdata0[1317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_steuerungThreadLicht_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_steuerungThreadLicht_t qt_meta_stringdata_steuerungThreadLicht = {
    {
QT_MOC_LITERAL(0, 0, 20), // "steuerungThreadLicht"
QT_MOC_LITERAL(1, 21, 13), // "hauptlichtVal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 22), // "hauptlichtSelectValSig"
QT_MOC_LITERAL(4, 59, 16), // "thekegetRGBvalue"
QT_MOC_LITERAL(5, 76, 1), // "r"
QT_MOC_LITERAL(6, 78, 1), // "g"
QT_MOC_LITERAL(7, 80, 1), // "b"
QT_MOC_LITERAL(8, 82, 10), // "fensterRot"
QT_MOC_LITERAL(9, 93, 11), // "fensterBlau"
QT_MOC_LITERAL(10, 105, 12), // "fensterGruen"
QT_MOC_LITERAL(11, 118, 18), // "fenstergetRGBvalue"
QT_MOC_LITERAL(12, 137, 10), // "thekeLicht"
QT_MOC_LITERAL(13, 148, 12), // "paletteLicht"
QT_MOC_LITERAL(14, 161, 6), // "beamer"
QT_MOC_LITERAL(15, 168, 15), // "hauptlichtPower"
QT_MOC_LITERAL(16, 184, 8), // "rgbPower"
QT_MOC_LITERAL(17, 193, 15), // "getStatusRelais"
QT_MOC_LITERAL(18, 209, 3), // "val"
QT_MOC_LITERAL(19, 213, 18), // "getLuefterNetzteil"
QT_MOC_LITERAL(20, 232, 20), // "getLuefterController"
QT_MOC_LITERAL(21, 253, 21), // "getLuefterAusgangOben"
QT_MOC_LITERAL(22, 275, 15), // "statusSliderCom"
QT_MOC_LITERAL(23, 291, 13), // "statusTempCom"
QT_MOC_LITERAL(24, 305, 9), // "getSlider"
QT_MOC_LITERAL(25, 315, 7), // "getTemp"
QT_MOC_LITERAL(26, 323, 10), // "connectUdp"
QT_MOC_LITERAL(27, 334, 10), // "readSensor"
QT_MOC_LITERAL(28, 345, 14), // "initHauptlicht"
QT_MOC_LITERAL(29, 360, 7), // "initRGB"
QT_MOC_LITERAL(30, 368, 8), // "initGPIO"
QT_MOC_LITERAL(31, 377, 14), // "toggleStandard"
QT_MOC_LITERAL(32, 392, 2), // "on"
QT_MOC_LITERAL(33, 395, 13), // "hauptlichtAll"
QT_MOC_LITERAL(34, 409, 16), // "hauptlichtSelect"
QT_MOC_LITERAL(35, 426, 7), // "leuchte"
QT_MOC_LITERAL(36, 434, 19), // "hauptlichtSelectVal"
QT_MOC_LITERAL(37, 454, 13), // "SetHauptlicht"
QT_MOC_LITERAL(38, 468, 19), // "getStatusHauptlicht"
QT_MOC_LITERAL(39, 488, 17), // "hauptlichtValSlot"
QT_MOC_LITERAL(40, 506, 14), // "thekeRGBAllVal"
QT_MOC_LITERAL(41, 521, 4), // "valR"
QT_MOC_LITERAL(42, 526, 4), // "valG"
QT_MOC_LITERAL(43, 531, 4), // "valB"
QT_MOC_LITERAL(44, 536, 17), // "thekeRGBSelectVal"
QT_MOC_LITERAL(45, 554, 5), // "farbe"
QT_MOC_LITERAL(46, 560, 20), // "thekeRGBRainbowOnOff"
QT_MOC_LITERAL(47, 581, 11), // "thekegetRGB"
QT_MOC_LITERAL(48, 593, 13), // "thekegetDecke"
QT_MOC_LITERAL(49, 607, 16), // "fensterRGBAllVal"
QT_MOC_LITERAL(50, 624, 19), // "fensterRGBSelectVal"
QT_MOC_LITERAL(51, 644, 22), // "fensterRGBRainbowOnOff"
QT_MOC_LITERAL(52, 667, 13), // "fenstergetRGB"
QT_MOC_LITERAL(53, 681, 18), // "deckeRGBPowerOnOff"
QT_MOC_LITERAL(54, 700, 15), // "thekeLichtOnOff"
QT_MOC_LITERAL(55, 716, 7), // "checked"
QT_MOC_LITERAL(56, 724, 17), // "paletteLichtOnOff"
QT_MOC_LITERAL(57, 742, 23), // "hauptlichtNetzteilOnOff"
QT_MOC_LITERAL(58, 766, 20), // "hauptlichtNetzteilOn"
QT_MOC_LITERAL(59, 787, 21), // "hauptlichtNetzteilOff"
QT_MOC_LITERAL(60, 809, 11), // "beamerOnOff"
QT_MOC_LITERAL(61, 821, 8), // "pc_pulse"
QT_MOC_LITERAL(62, 830, 15), // "getStatusBeamer"
QT_MOC_LITERAL(63, 846, 16), // "getStatusPalette"
QT_MOC_LITERAL(64, 863, 6), // "Relais"
QT_MOC_LITERAL(65, 870, 25), // "RGB_Decke_DataRot_Changed"
QT_MOC_LITERAL(66, 896, 27), // "RGB_Decke_DataGruen_Changed"
QT_MOC_LITERAL(67, 924, 26), // "RGB_Decke_DataBlau_Changed"
QT_MOC_LITERAL(68, 951, 18), // "getStatusRGBRelais"
QT_MOC_LITERAL(69, 970, 6), // "allOFF"
QT_MOC_LITERAL(70, 977, 13), // "jugendLichtON"
QT_MOC_LITERAL(71, 991, 11), // "teenLichtOn"
QT_MOC_LITERAL(72, 1003, 4), // "kino"
QT_MOC_LITERAL(73, 1008, 9), // "praistime"
QT_MOC_LITERAL(74, 1018, 15), // "luefterNetzteil"
QT_MOC_LITERAL(75, 1034, 17), // "luefterController"
QT_MOC_LITERAL(76, 1052, 18), // "luefterAusgangOben"
QT_MOC_LITERAL(77, 1071, 12), // "luefterOnkyo"
QT_MOC_LITERAL(78, 1084, 22), // "getLuefterNetzteilslot"
QT_MOC_LITERAL(79, 1107, 25), // "getLuefterAusgangObenslot"
QT_MOC_LITERAL(80, 1133, 24), // "getLuefterControllerslot"
QT_MOC_LITERAL(81, 1158, 19), // "statusSliderComSLot"
QT_MOC_LITERAL(82, 1178, 17), // "statusTempComSLot"
QT_MOC_LITERAL(83, 1196, 13), // "getSliderSlot"
QT_MOC_LITERAL(84, 1210, 9), // "sliderNum"
QT_MOC_LITERAL(85, 1220, 11), // "getTempSlot"
QT_MOC_LITERAL(86, 1232, 6), // "sensor"
QT_MOC_LITERAL(87, 1239, 13), // "setSliderSlot"
QT_MOC_LITERAL(88, 1253, 3), // "Val"
QT_MOC_LITERAL(89, 1257, 14), // "connectUdpSLot"
QT_MOC_LITERAL(90, 1272, 3), // "udp"
QT_MOC_LITERAL(91, 1276, 2), // "ip"
QT_MOC_LITERAL(92, 1279, 4), // "port"
QT_MOC_LITERAL(93, 1284, 14), // "readSensorSlot"
QT_MOC_LITERAL(94, 1299, 6), // "Sensor"
QT_MOC_LITERAL(95, 1306, 10) // "standardOn"

    },
    "steuerungThreadLicht\0hauptlichtVal\0\0"
    "hauptlichtSelectValSig\0thekegetRGBvalue\0"
    "r\0g\0b\0fensterRot\0fensterBlau\0fensterGruen\0"
    "fenstergetRGBvalue\0thekeLicht\0"
    "paletteLicht\0beamer\0hauptlichtPower\0"
    "rgbPower\0getStatusRelais\0val\0"
    "getLuefterNetzteil\0getLuefterController\0"
    "getLuefterAusgangOben\0statusSliderCom\0"
    "statusTempCom\0getSlider\0getTemp\0"
    "connectUdp\0readSensor\0initHauptlicht\0"
    "initRGB\0initGPIO\0toggleStandard\0on\0"
    "hauptlichtAll\0hauptlichtSelect\0leuchte\0"
    "hauptlichtSelectVal\0SetHauptlicht\0"
    "getStatusHauptlicht\0hauptlichtValSlot\0"
    "thekeRGBAllVal\0valR\0valG\0valB\0"
    "thekeRGBSelectVal\0farbe\0thekeRGBRainbowOnOff\0"
    "thekegetRGB\0thekegetDecke\0fensterRGBAllVal\0"
    "fensterRGBSelectVal\0fensterRGBRainbowOnOff\0"
    "fenstergetRGB\0deckeRGBPowerOnOff\0"
    "thekeLichtOnOff\0checked\0paletteLichtOnOff\0"
    "hauptlichtNetzteilOnOff\0hauptlichtNetzteilOn\0"
    "hauptlichtNetzteilOff\0beamerOnOff\0"
    "pc_pulse\0getStatusBeamer\0getStatusPalette\0"
    "Relais\0RGB_Decke_DataRot_Changed\0"
    "RGB_Decke_DataGruen_Changed\0"
    "RGB_Decke_DataBlau_Changed\0"
    "getStatusRGBRelais\0allOFF\0jugendLichtON\0"
    "teenLichtOn\0kino\0praistime\0luefterNetzteil\0"
    "luefterController\0luefterAusgangOben\0"
    "luefterOnkyo\0getLuefterNetzteilslot\0"
    "getLuefterAusgangObenslot\0"
    "getLuefterControllerslot\0statusSliderComSLot\0"
    "statusTempComSLot\0getSliderSlot\0"
    "sliderNum\0getTempSlot\0sensor\0setSliderSlot\0"
    "Val\0connectUdpSLot\0udp\0ip\0port\0"
    "readSensorSlot\0Sensor\0standardOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_steuerungThreadLicht[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      76,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      22,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  394,    2, 0x06 /* Public */,
       3,    1,  397,    2, 0x06 /* Public */,
       4,    3,  400,    2, 0x06 /* Public */,
       8,    1,  407,    2, 0x06 /* Public */,
       9,    1,  410,    2, 0x06 /* Public */,
      10,    1,  413,    2, 0x06 /* Public */,
      11,    3,  416,    2, 0x06 /* Public */,
      12,    1,  423,    2, 0x06 /* Public */,
      13,    1,  426,    2, 0x06 /* Public */,
      14,    1,  429,    2, 0x06 /* Public */,
      15,    1,  432,    2, 0x06 /* Public */,
      16,    1,  435,    2, 0x06 /* Public */,
      17,    1,  438,    2, 0x06 /* Public */,
      19,    1,  441,    2, 0x06 /* Public */,
      20,    1,  444,    2, 0x06 /* Public */,
      21,    1,  447,    2, 0x06 /* Public */,
      22,    1,  450,    2, 0x06 /* Public */,
      23,    1,  453,    2, 0x06 /* Public */,
      24,    1,  456,    2, 0x06 /* Public */,
      25,    1,  459,    2, 0x06 /* Public */,
      26,    1,  462,    2, 0x06 /* Public */,
      27,    1,  465,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      28,    0,  468,    2, 0x0a /* Public */,
      29,    0,  469,    2, 0x0a /* Public */,
      30,    0,  470,    2, 0x0a /* Public */,
      31,    1,  471,    2, 0x0a /* Public */,
      33,    1,  474,    2, 0x0a /* Public */,
      34,    2,  477,    2, 0x0a /* Public */,
      36,    1,  482,    2, 0x0a /* Public */,
      37,    1,  485,    2, 0x0a /* Public */,
      38,    0,  488,    2, 0x0a /* Public */,
      39,    1,  489,    2, 0x0a /* Public */,
      40,    3,  492,    2, 0x0a /* Public */,
      44,    2,  499,    2, 0x0a /* Public */,
      46,    0,  504,    2, 0x0a /* Public */,
      47,    0,  505,    2, 0x0a /* Public */,
      48,    0,  506,    2, 0x0a /* Public */,
      49,    1,  507,    2, 0x0a /* Public */,
      50,    2,  510,    2, 0x0a /* Public */,
      51,    0,  515,    2, 0x0a /* Public */,
      52,    0,  516,    2, 0x0a /* Public */,
      53,    0,  517,    2, 0x0a /* Public */,
      54,    1,  518,    2, 0x0a /* Public */,
      56,    1,  521,    2, 0x0a /* Public */,
      57,    0,  524,    2, 0x0a /* Public */,
      58,    0,  525,    2, 0x0a /* Public */,
      59,    0,  526,    2, 0x0a /* Public */,
      60,    1,  527,    2, 0x0a /* Public */,
      61,    0,  530,    2, 0x0a /* Public */,
      62,    0,  531,    2, 0x0a /* Public */,
      63,    0,  532,    2, 0x0a /* Public */,
      17,    1,  533,    2, 0x0a /* Public */,
      65,    1,  536,    2, 0x0a /* Public */,
      66,    1,  539,    2, 0x0a /* Public */,
      67,    1,  542,    2, 0x0a /* Public */,
      68,    0,  545,    2, 0x0a /* Public */,
      69,    0,  546,    2, 0x0a /* Public */,
      70,    0,  547,    2, 0x0a /* Public */,
      71,    0,  548,    2, 0x0a /* Public */,
      72,    0,  549,    2, 0x0a /* Public */,
      73,    0,  550,    2, 0x0a /* Public */,
      74,    1,  551,    2, 0x0a /* Public */,
      75,    1,  554,    2, 0x0a /* Public */,
      76,    1,  557,    2, 0x0a /* Public */,
      77,    1,  560,    2, 0x0a /* Public */,
      78,    0,  563,    2, 0x0a /* Public */,
      79,    0,  564,    2, 0x0a /* Public */,
      80,    0,  565,    2, 0x0a /* Public */,
      81,    0,  566,    2, 0x0a /* Public */,
      82,    0,  567,    2, 0x0a /* Public */,
      83,    1,  568,    2, 0x0a /* Public */,
      85,    1,  571,    2, 0x0a /* Public */,
      87,    2,  574,    2, 0x0a /* Public */,
      89,    3,  579,    2, 0x0a /* Public */,
      93,    1,  586,    2, 0x0a /* Public */,
      95,    0,  589,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Float,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,   18,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   18,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   41,   42,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   55,
    QMetaType::Void, QMetaType::Bool,   55,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   55,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Char,   84,
    QMetaType::Void, QMetaType::Int,   86,
    QMetaType::Void, QMetaType::Char, QMetaType::Int,   84,   88,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::UShort,   90,   91,   92,
    QMetaType::Void, QMetaType::Int,   94,
    QMetaType::Void,

       0        // eod
};

void steuerungThreadLicht::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        steuerungThreadLicht *_t = static_cast<steuerungThreadLicht *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hauptlichtVal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->hauptlichtSelectValSig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->thekegetRGBvalue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->fensterRot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->fensterBlau((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->fensterGruen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->fenstergetRGBvalue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->thekeLicht((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->paletteLicht((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->beamer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->hauptlichtPower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->rgbPower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->getStatusRelais((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->getLuefterNetzteil((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->getLuefterController((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->getLuefterAusgangOben((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->statusSliderCom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->statusTempCom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->getSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->getTemp((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 20: _t->connectUdp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->readSensor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->initHauptlicht(); break;
        case 23: _t->initRGB(); break;
        case 24: _t->initGPIO(); break;
        case 25: _t->toggleStandard((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->hauptlichtAll((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->hauptlichtSelect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: _t->hauptlichtSelectVal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->SetHauptlicht((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: { bool _r = _t->getStatusHauptlicht();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: _t->hauptlichtValSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->thekeRGBAllVal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 33: _t->thekeRGBSelectVal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->thekeRGBRainbowOnOff(); break;
        case 35: _t->thekegetRGB(); break;
        case 36: { bool _r = _t->thekegetDecke();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 37: _t->fensterRGBAllVal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->fensterRGBSelectVal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->fensterRGBRainbowOnOff(); break;
        case 40: _t->fenstergetRGB(); break;
        case 41: _t->deckeRGBPowerOnOff(); break;
        case 42: _t->thekeLichtOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->paletteLichtOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->hauptlichtNetzteilOnOff(); break;
        case 45: _t->hauptlichtNetzteilOn(); break;
        case 46: _t->hauptlichtNetzteilOff(); break;
        case 47: _t->beamerOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->pc_pulse(); break;
        case 49: { bool _r = _t->getStatusBeamer();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 50: { bool _r = _t->getStatusPalette();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 51: _t->getStatusRelais((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->RGB_Decke_DataRot_Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->RGB_Decke_DataGruen_Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->RGB_Decke_DataBlau_Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: { bool _r = _t->getStatusRGBRelais();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 56: _t->allOFF(); break;
        case 57: _t->jugendLichtON(); break;
        case 58: _t->teenLichtOn(); break;
        case 59: _t->kino(); break;
        case 60: _t->praistime(); break;
        case 61: _t->luefterNetzteil((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: _t->luefterController((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->luefterAusgangOben((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 64: _t->luefterOnkyo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->getLuefterNetzteilslot(); break;
        case 66: _t->getLuefterAusgangObenslot(); break;
        case 67: _t->getLuefterControllerslot(); break;
        case 68: _t->statusSliderComSLot(); break;
        case 69: _t->statusTempComSLot(); break;
        case 70: _t->getSliderSlot((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 71: _t->getTempSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: _t->setSliderSlot((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 73: _t->connectUdpSLot((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 74: _t->readSensorSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 75: _t->standardOn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::hauptlichtVal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::hauptlichtSelectValSig)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::thekegetRGBvalue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::fensterRot)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::fensterBlau)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::fensterGruen)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::fenstergetRGBvalue)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::thekeLicht)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::paletteLicht)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::beamer)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::hauptlichtPower)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::rgbPower)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::getStatusRelais)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::getLuefterNetzteil)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::getLuefterController)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::getLuefterAusgangOben)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::statusSliderCom)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::statusTempCom)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::getSlider)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::getTemp)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::connectUdp)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (steuerungThreadLicht::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&steuerungThreadLicht::readSensor)) {
                *result = 21;
                return;
            }
        }
    }
}

const QMetaObject steuerungThreadLicht::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_steuerungThreadLicht.data,
      qt_meta_data_steuerungThreadLicht,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *steuerungThreadLicht::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *steuerungThreadLicht::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_steuerungThreadLicht.stringdata0))
        return static_cast<void*>(const_cast< steuerungThreadLicht*>(this));
    return QThread::qt_metacast(_clname);
}

int steuerungThreadLicht::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 76)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 76;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 76)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 76;
    }
    return _id;
}

// SIGNAL 0
void steuerungThreadLicht::hauptlichtVal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void steuerungThreadLicht::hauptlichtSelectValSig(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void steuerungThreadLicht::thekegetRGBvalue(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void steuerungThreadLicht::fensterRot(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void steuerungThreadLicht::fensterBlau(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void steuerungThreadLicht::fensterGruen(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void steuerungThreadLicht::fenstergetRGBvalue(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void steuerungThreadLicht::thekeLicht(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void steuerungThreadLicht::paletteLicht(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void steuerungThreadLicht::beamer(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void steuerungThreadLicht::hauptlichtPower(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void steuerungThreadLicht::rgbPower(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void steuerungThreadLicht::getStatusRelais(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void steuerungThreadLicht::getLuefterNetzteil(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void steuerungThreadLicht::getLuefterController(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void steuerungThreadLicht::getLuefterAusgangOben(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void steuerungThreadLicht::statusSliderCom(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void steuerungThreadLicht::statusTempCom(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void steuerungThreadLicht::getSlider(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void steuerungThreadLicht::getTemp(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void steuerungThreadLicht::connectUdp(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void steuerungThreadLicht::readSensor(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
