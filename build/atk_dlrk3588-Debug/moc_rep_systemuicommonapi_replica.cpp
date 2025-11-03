/****************************************************************************
** Meta object code from reading C++ file 'rep_systemuicommonapi_replica.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../uitest/rep_systemuicommonapi_replica.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rep_systemuicommonapi_replica.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SystemUICommonApiReplica_t {
    QByteArrayData data[12];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemUICommonApiReplica_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemUICommonApiReplica_t qt_meta_stringdata_SystemUICommonApiReplica = {
    {
QT_MOC_LITERAL(0, 0, 24), // "SystemUICommonApiReplica"
QT_MOC_LITERAL(1, 25, 17), // "RemoteObject Type"
QT_MOC_LITERAL(2, 43, 17), // "SystemUICommonApi"
QT_MOC_LITERAL(3, 61, 22), // "RemoteObject Signature"
QT_MOC_LITERAL(4, 84, 40), // "a26e2f775637e9e2a03a37f9a5a15..."
QT_MOC_LITERAL(5, 125, 17), // "serverSendVariant"
QT_MOC_LITERAL(6, 143, 0), // ""
QT_MOC_LITERAL(7, 144, 7), // "appName"
QT_MOC_LITERAL(8, 152, 4), // "type"
QT_MOC_LITERAL(9, 157, 3), // "cmd"
QT_MOC_LITERAL(10, 161, 7), // "variant"
QT_MOC_LITERAL(11, 169, 15) // "onServerVariant"

    },
    "SystemUICommonApiReplica\0RemoteObject Type\0"
    "SystemUICommonApi\0RemoteObject Signature\0"
    "a26e2f775637e9e2a03a37f9a5a159dd8fb897bf\0"
    "serverSendVariant\0\0appName\0type\0cmd\0"
    "variant\0onServerVariant"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemUICommonApiReplica[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       2,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    4,   28,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    4,   37,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,    7,    8,    9,   10,

       0        // eod
};

void SystemUICommonApiReplica::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SystemUICommonApiReplica *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->serverSendVariant((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4]))); break;
        case 1: _t->onServerVariant((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SystemUICommonApiReplica::*)(const QString & , int , int , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemUICommonApiReplica::serverSendVariant)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SystemUICommonApiReplica::staticMetaObject = { {
    QMetaObject::SuperData::link<QRemoteObjectReplica::staticMetaObject>(),
    qt_meta_stringdata_SystemUICommonApiReplica.data,
    qt_meta_data_SystemUICommonApiReplica,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SystemUICommonApiReplica::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemUICommonApiReplica::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SystemUICommonApiReplica.stringdata0))
        return static_cast<void*>(this);
    return QRemoteObjectReplica::qt_metacast(_clname);
}

int SystemUICommonApiReplica::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QRemoteObjectReplica::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SystemUICommonApiReplica::serverSendVariant(const QString & _t1, int _t2, int _t3, QVariant _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
