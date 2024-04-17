/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../untitled/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "imageLoaded",
    "",
    "filterFinished",
    "QPushButton*",
    "btn",
    "updateGui",
    "updateToImage",
    "on_BWBtn_clicked",
    "on_ResizeBtn_clicked",
    "on_FlipBtn_clicked",
    "on_CropBtn_clicked",
    "on_pushButton_clicked",
    "on_saveBtn_clicked",
    "on_clearBtn_clicked",
    "on_applyBtn_toggled",
    "checked",
    "on_applyBtn_clicked",
    "on_Infrared_clicked",
    "on_OilPaint_clicked",
    "on_GrayscaleBtn_clicked",
    "on_loadNewImage_clicked",
    "on_mergeBtn_clicked",
    "on_Brightness_valueChanged",
    "value",
    "on_brightnessBtn_clicked",
    "on_EdgeDetection_clicked",
    "on_sunLightBtn_clicked",
    "on_Purple_clicked",
    "on_Sepia_clicked",
    "on_nightMoodBtn_clicked",
    "on_Invert_clicked",
    "on_RotateBtn_clicked",
    "on_horizontalSlider_valueChanged",
    "on_BlurBtn_clicked",
    "on_horizontalSlider_2_valueChanged",
    "on_TVEffect_clicked",
    "on_SkewBtn_clicked",
    "on_horizontalSlider_3_valueChanged",
    "on_FrameBtn_clicked",
    "on_pushButton_2_clicked",
    "on_radioButton_3_clicked",
    "on_radioButton_4_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[86];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[13];
    char stringdata5[4];
    char stringdata6[10];
    char stringdata7[14];
    char stringdata8[17];
    char stringdata9[21];
    char stringdata10[19];
    char stringdata11[19];
    char stringdata12[22];
    char stringdata13[19];
    char stringdata14[20];
    char stringdata15[20];
    char stringdata16[8];
    char stringdata17[20];
    char stringdata18[20];
    char stringdata19[20];
    char stringdata20[24];
    char stringdata21[24];
    char stringdata22[20];
    char stringdata23[27];
    char stringdata24[6];
    char stringdata25[25];
    char stringdata26[25];
    char stringdata27[23];
    char stringdata28[18];
    char stringdata29[17];
    char stringdata30[24];
    char stringdata31[18];
    char stringdata32[21];
    char stringdata33[33];
    char stringdata34[19];
    char stringdata35[35];
    char stringdata36[20];
    char stringdata37[19];
    char stringdata38[35];
    char stringdata39[20];
    char stringdata40[24];
    char stringdata41[25];
    char stringdata42[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 11),  // "imageLoaded"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 14),  // "filterFinished"
        QT_MOC_LITERAL(39, 12),  // "QPushButton*"
        QT_MOC_LITERAL(52, 3),  // "btn"
        QT_MOC_LITERAL(56, 9),  // "updateGui"
        QT_MOC_LITERAL(66, 13),  // "updateToImage"
        QT_MOC_LITERAL(80, 16),  // "on_BWBtn_clicked"
        QT_MOC_LITERAL(97, 20),  // "on_ResizeBtn_clicked"
        QT_MOC_LITERAL(118, 18),  // "on_FlipBtn_clicked"
        QT_MOC_LITERAL(137, 18),  // "on_CropBtn_clicked"
        QT_MOC_LITERAL(156, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(178, 18),  // "on_saveBtn_clicked"
        QT_MOC_LITERAL(197, 19),  // "on_clearBtn_clicked"
        QT_MOC_LITERAL(217, 19),  // "on_applyBtn_toggled"
        QT_MOC_LITERAL(237, 7),  // "checked"
        QT_MOC_LITERAL(245, 19),  // "on_applyBtn_clicked"
        QT_MOC_LITERAL(265, 19),  // "on_Infrared_clicked"
        QT_MOC_LITERAL(285, 19),  // "on_OilPaint_clicked"
        QT_MOC_LITERAL(305, 23),  // "on_GrayscaleBtn_clicked"
        QT_MOC_LITERAL(329, 23),  // "on_loadNewImage_clicked"
        QT_MOC_LITERAL(353, 19),  // "on_mergeBtn_clicked"
        QT_MOC_LITERAL(373, 26),  // "on_Brightness_valueChanged"
        QT_MOC_LITERAL(400, 5),  // "value"
        QT_MOC_LITERAL(406, 24),  // "on_brightnessBtn_clicked"
        QT_MOC_LITERAL(431, 24),  // "on_EdgeDetection_clicked"
        QT_MOC_LITERAL(456, 22),  // "on_sunLightBtn_clicked"
        QT_MOC_LITERAL(479, 17),  // "on_Purple_clicked"
        QT_MOC_LITERAL(497, 16),  // "on_Sepia_clicked"
        QT_MOC_LITERAL(514, 23),  // "on_nightMoodBtn_clicked"
        QT_MOC_LITERAL(538, 17),  // "on_Invert_clicked"
        QT_MOC_LITERAL(556, 20),  // "on_RotateBtn_clicked"
        QT_MOC_LITERAL(577, 32),  // "on_horizontalSlider_valueChanged"
        QT_MOC_LITERAL(610, 18),  // "on_BlurBtn_clicked"
        QT_MOC_LITERAL(629, 34),  // "on_horizontalSlider_2_valueCh..."
        QT_MOC_LITERAL(664, 19),  // "on_TVEffect_clicked"
        QT_MOC_LITERAL(684, 18),  // "on_SkewBtn_clicked"
        QT_MOC_LITERAL(703, 34),  // "on_horizontalSlider_3_valueCh..."
        QT_MOC_LITERAL(738, 19),  // "on_FrameBtn_clicked"
        QT_MOC_LITERAL(758, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(782, 24),  // "on_radioButton_3_clicked"
        QT_MOC_LITERAL(807, 24)   // "on_radioButton_4_clicked"
    },
    "MainWindow",
    "imageLoaded",
    "",
    "filterFinished",
    "QPushButton*",
    "btn",
    "updateGui",
    "updateToImage",
    "on_BWBtn_clicked",
    "on_ResizeBtn_clicked",
    "on_FlipBtn_clicked",
    "on_CropBtn_clicked",
    "on_pushButton_clicked",
    "on_saveBtn_clicked",
    "on_clearBtn_clicked",
    "on_applyBtn_toggled",
    "checked",
    "on_applyBtn_clicked",
    "on_Infrared_clicked",
    "on_OilPaint_clicked",
    "on_GrayscaleBtn_clicked",
    "on_loadNewImage_clicked",
    "on_mergeBtn_clicked",
    "on_Brightness_valueChanged",
    "value",
    "on_brightnessBtn_clicked",
    "on_EdgeDetection_clicked",
    "on_sunLightBtn_clicked",
    "on_Purple_clicked",
    "on_Sepia_clicked",
    "on_nightMoodBtn_clicked",
    "on_Invert_clicked",
    "on_RotateBtn_clicked",
    "on_horizontalSlider_valueChanged",
    "on_BlurBtn_clicked",
    "on_horizontalSlider_2_valueChanged",
    "on_TVEffect_clicked",
    "on_SkewBtn_clicked",
    "on_horizontalSlider_3_valueChanged",
    "on_FrameBtn_clicked",
    "on_pushButton_2_clicked",
    "on_radioButton_3_clicked",
    "on_radioButton_4_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  236,    2, 0x06,    1 /* Public */,
       3,    1,  237,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  240,    2, 0x0a,    4 /* Public */,
       7,    1,  241,    2, 0x0a,    5 /* Public */,
       8,    0,  244,    2, 0x08,    7 /* Private */,
       9,    0,  245,    2, 0x08,    8 /* Private */,
      10,    0,  246,    2, 0x08,    9 /* Private */,
      11,    0,  247,    2, 0x08,   10 /* Private */,
      12,    0,  248,    2, 0x08,   11 /* Private */,
      13,    0,  249,    2, 0x08,   12 /* Private */,
      14,    0,  250,    2, 0x08,   13 /* Private */,
      15,    1,  251,    2, 0x08,   14 /* Private */,
      17,    0,  254,    2, 0x08,   16 /* Private */,
      18,    0,  255,    2, 0x08,   17 /* Private */,
      19,    0,  256,    2, 0x08,   18 /* Private */,
      20,    0,  257,    2, 0x08,   19 /* Private */,
      21,    0,  258,    2, 0x08,   20 /* Private */,
      22,    0,  259,    2, 0x08,   21 /* Private */,
      23,    1,  260,    2, 0x08,   22 /* Private */,
      25,    0,  263,    2, 0x08,   24 /* Private */,
      26,    0,  264,    2, 0x08,   25 /* Private */,
      27,    0,  265,    2, 0x08,   26 /* Private */,
      28,    0,  266,    2, 0x08,   27 /* Private */,
      29,    0,  267,    2, 0x08,   28 /* Private */,
      30,    0,  268,    2, 0x08,   29 /* Private */,
      31,    0,  269,    2, 0x08,   30 /* Private */,
      32,    0,  270,    2, 0x08,   31 /* Private */,
      33,    1,  271,    2, 0x08,   32 /* Private */,
      34,    0,  274,    2, 0x08,   34 /* Private */,
      35,    1,  275,    2, 0x08,   35 /* Private */,
      36,    0,  278,    2, 0x08,   37 /* Private */,
      37,    0,  279,    2, 0x08,   38 /* Private */,
      38,    1,  280,    2, 0x08,   39 /* Private */,
      39,    0,  283,    2, 0x08,   41 /* Private */,
      40,    0,  284,    2, 0x08,   42 /* Private */,
      41,    0,  285,    2, 0x08,   43 /* Private */,
      42,    0,  286,    2, 0x08,   44 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'imageLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>,
        // method 'updateGui'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateToImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>,
        // method 'on_BWBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ResizeBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_FlipBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CropBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_applyBtn_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_applyBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Infrared_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_OilPaint_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_GrayscaleBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_loadNewImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mergeBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Brightness_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_brightnessBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EdgeDetection_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sunLightBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Purple_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Sepia_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_nightMoodBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Invert_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RotateBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_BlurBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_2_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_TVEffect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SkewBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_3_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_FrameBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imageLoaded(); break;
        case 1: _t->filterFinished((*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[1]))); break;
        case 2: _t->updateGui(); break;
        case 3: _t->updateToImage((*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[1]))); break;
        case 4: _t->on_BWBtn_clicked(); break;
        case 5: _t->on_ResizeBtn_clicked(); break;
        case 6: _t->on_FlipBtn_clicked(); break;
        case 7: _t->on_CropBtn_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_saveBtn_clicked(); break;
        case 10: _t->on_clearBtn_clicked(); break;
        case 11: _t->on_applyBtn_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_applyBtn_clicked(); break;
        case 13: _t->on_Infrared_clicked(); break;
        case 14: _t->on_OilPaint_clicked(); break;
        case 15: _t->on_GrayscaleBtn_clicked(); break;
        case 16: _t->on_loadNewImage_clicked(); break;
        case 17: _t->on_mergeBtn_clicked(); break;
        case 18: _t->on_Brightness_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_brightnessBtn_clicked(); break;
        case 20: _t->on_EdgeDetection_clicked(); break;
        case 21: _t->on_sunLightBtn_clicked(); break;
        case 22: _t->on_Purple_clicked(); break;
        case 23: _t->on_Sepia_clicked(); break;
        case 24: _t->on_nightMoodBtn_clicked(); break;
        case 25: _t->on_Invert_clicked(); break;
        case 26: _t->on_RotateBtn_clicked(); break;
        case 27: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_BlurBtn_clicked(); break;
        case 29: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_TVEffect_clicked(); break;
        case 31: _t->on_SkewBtn_clicked(); break;
        case 32: _t->on_horizontalSlider_3_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->on_FrameBtn_clicked(); break;
        case 34: _t->on_pushButton_2_clicked(); break;
        case 35: _t->on_radioButton_3_clicked(); break;
        case 36: _t->on_radioButton_4_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::imageLoaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPushButton * );
            if (_t _q_method = &MainWindow::filterFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::imageLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::filterFinished(QPushButton * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
