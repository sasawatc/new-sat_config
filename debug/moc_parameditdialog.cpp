/****************************************************************************
** Meta object code from reading C++ file 'parameditdialog.h'
**
<<<<<<< HEAD
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
=======
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
>>>>>>> origin/master
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../parameditdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parameditdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
<<<<<<< HEAD
#error "This file was generated using the moc from 5.4.0. It"
=======
#error "This file was generated using the moc from 5.5.0. It"
>>>>>>> origin/master
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParamEditDialog_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParamEditDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParamEditDialog_t qt_meta_stringdata_ParamEditDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ParamEditDialog"
QT_MOC_LITERAL(1, 16, 21), // "onSetParameterClicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14) // "onCloseClicked"

    },
    "ParamEditDialog\0onSetParameterClicked\0"
    "\0onCloseClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParamEditDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParamEditDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParamEditDialog *_t = static_cast<ParamEditDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSetParameterClicked(); break;
        case 1: _t->onCloseClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ParamEditDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ParamEditDialog.data,
      qt_meta_data_ParamEditDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParamEditDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParamEditDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParamEditDialog.stringdata0))
        return static_cast<void*>(const_cast< ParamEditDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ParamEditDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
