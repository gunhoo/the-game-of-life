/****************************************************************************
** Meta object code from reading C++ file 'gameoflifeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameoflifeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameoflifeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameOfLifeView_t {
    QByteArrayData data[17];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameOfLifeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameOfLifeView_t qt_meta_stringdata_GameOfLifeView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GameOfLifeView"
QT_MOC_LITERAL(1, 15, 16), // "newButtonClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "openButtonClicked"
QT_MOC_LITERAL(4, 51, 17), // "saveButtonClicked"
QT_MOC_LITERAL(5, 69, 19), // "saveAsButtonClicked"
QT_MOC_LITERAL(6, 89, 23), // "saveResultButtonClicked"
QT_MOC_LITERAL(7, 113, 17), // "quitButtonClicked"
QT_MOC_LITERAL(8, 131, 16), // "runButtonClicked"
QT_MOC_LITERAL(9, 148, 17), // "stopButtonClicked"
QT_MOC_LITERAL(10, 166, 17), // "nextButtonClicked"
QT_MOC_LITERAL(11, 184, 19), // "resizeButtonClicked"
QT_MOC_LITERAL(12, 204, 18), // "clearButtonClicked"
QT_MOC_LITERAL(13, 223, 16), // "setCellNumberRow"
QT_MOC_LITERAL(14, 240, 3), // "row"
QT_MOC_LITERAL(15, 244, 16), // "setCellNumberCol"
QT_MOC_LITERAL(16, 261, 3) // "col"

    },
    "GameOfLifeView\0newButtonClicked\0\0"
    "openButtonClicked\0saveButtonClicked\0"
    "saveAsButtonClicked\0saveResultButtonClicked\0"
    "quitButtonClicked\0runButtonClicked\0"
    "stopButtonClicked\0nextButtonClicked\0"
    "resizeButtonClicked\0clearButtonClicked\0"
    "setCellNumberRow\0row\0setCellNumberCol\0"
    "col"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameOfLifeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void GameOfLifeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameOfLifeView *_t = static_cast<GameOfLifeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newButtonClicked(); break;
        case 1: _t->openButtonClicked(); break;
        case 2: _t->saveButtonClicked(); break;
        case 3: _t->saveAsButtonClicked(); break;
        case 4: _t->saveResultButtonClicked(); break;
        case 5: _t->quitButtonClicked(); break;
        case 6: _t->runButtonClicked(); break;
        case 7: _t->stopButtonClicked(); break;
        case 8: _t->nextButtonClicked(); break;
        case 9: _t->resizeButtonClicked(); break;
        case 10: _t->clearButtonClicked(); break;
        case 11: _t->setCellNumberRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setCellNumberCol((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GameOfLifeView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameOfLifeView.data,
      qt_meta_data_GameOfLifeView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameOfLifeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameOfLifeView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameOfLifeView.stringdata0))
        return static_cast<void*>(const_cast< GameOfLifeView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GameOfLifeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
