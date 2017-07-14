/****************************************************************************
** Meta object code from reading C++ file 'controlroomdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controlroomdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlroomdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControlRoomDialog_t {
    QByteArrayData data[14];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlRoomDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlRoomDialog_t qt_meta_stringdata_ControlRoomDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ControlRoomDialog"
QT_MOC_LITERAL(1, 18, 24), // "on_dsp_dial_valueChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5), // "value"
QT_MOC_LITERAL(4, 50, 23), // "on_dh_dial_valueChanged"
QT_MOC_LITERAL(5, 74, 23), // "on_fs_dial_valueChanged"
QT_MOC_LITERAL(6, 98, 23), // "on_start_button_clicked"
QT_MOC_LITERAL(7, 122, 29), // "on_com_box_currentTextChanged"
QT_MOC_LITERAL(8, 152, 4), // "arg1"
QT_MOC_LITERAL(9, 157, 22), // "on_load_button_clicked"
QT_MOC_LITERAL(10, 180, 22), // "on_save_button_clicked"
QT_MOC_LITERAL(11, 203, 23), // "on_clear_button_clicked"
QT_MOC_LITERAL(12, 227, 24), // "on_delete_button_clicked"
QT_MOC_LITERAL(13, 252, 12) // "update_chart"

    },
    "ControlRoomDialog\0on_dsp_dial_valueChanged\0"
    "\0value\0on_dh_dial_valueChanged\0"
    "on_fs_dial_valueChanged\0on_start_button_clicked\0"
    "on_com_box_currentTextChanged\0arg1\0"
    "on_load_button_clicked\0on_save_button_clicked\0"
    "on_clear_button_clicked\0"
    "on_delete_button_clicked\0update_chart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlRoomDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ControlRoomDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlRoomDialog *_t = static_cast<ControlRoomDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dsp_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_dh_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_fs_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_start_button_clicked(); break;
        case 4: _t->on_com_box_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_load_button_clicked(); break;
        case 6: _t->on_save_button_clicked(); break;
        case 7: _t->on_clear_button_clicked(); break;
        case 8: _t->on_delete_button_clicked(); break;
        case 9: _t->update_chart(); break;
        default: ;
        }
    }
}

const QMetaObject ControlRoomDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ControlRoomDialog.data,
      qt_meta_data_ControlRoomDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ControlRoomDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlRoomDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControlRoomDialog.stringdata0))
        return static_cast<void*>(const_cast< ControlRoomDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ControlRoomDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
