/****************************************************************************
** Meta object code from reading C++ file 'Keyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../uitest/Keyboard/Keyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AeaQt__ChineseWidget_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AeaQt__ChineseWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AeaQt__ChineseWidget_t qt_meta_stringdata_AeaQt__ChineseWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AeaQt::ChineseWidget"
QT_MOC_LITERAL(1, 21, 14), // "pressedChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "code"
QT_MOC_LITERAL(4, 42, 4), // "text"
QT_MOC_LITERAL(5, 47, 13), // "onItemClicked"
QT_MOC_LITERAL(6, 61, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 78, 4) // "item"

    },
    "AeaQt::ChineseWidget\0pressedChanged\0"
    "\0code\0text\0onItemClicked\0QListWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AeaQt__ChineseWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void AeaQt::ChineseWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChineseWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pressedChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->onItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChineseWidget::*)(const int & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChineseWidget::pressedChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AeaQt::ChineseWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QListWidget::staticMetaObject>(),
    qt_meta_stringdata_AeaQt__ChineseWidget.data,
    qt_meta_data_AeaQt__ChineseWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AeaQt::ChineseWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AeaQt::ChineseWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AeaQt__ChineseWidget.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int AeaQt::ChineseWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
void AeaQt::ChineseWidget::pressedChanged(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_AeaQt__Keyboard_t {
    QByteArrayData data[9];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AeaQt__Keyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AeaQt__Keyboard_t qt_meta_stringdata_AeaQt__Keyboard = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AeaQt::Keyboard"
QT_MOC_LITERAL(1, 16, 14), // "switchCapsLock"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "switchSpecialChar"
QT_MOC_LITERAL(4, 50, 12), // "switchEnOrCh"
QT_MOC_LITERAL(5, 63, 15), // "onButtonPressed"
QT_MOC_LITERAL(6, 79, 4), // "code"
QT_MOC_LITERAL(7, 84, 4), // "text"
QT_MOC_LITERAL(8, 89, 15) // "clearBufferText"

    },
    "AeaQt::Keyboard\0switchCapsLock\0\0"
    "switchSpecialChar\0switchEnOrCh\0"
    "onButtonPressed\0code\0text\0clearBufferText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AeaQt__Keyboard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    2,   42,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,
    QMetaType::Void,

       0        // eod
};

void AeaQt::Keyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Keyboard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->switchCapsLock(); break;
        case 1: _t->switchSpecialChar(); break;
        case 2: _t->switchEnOrCh(); break;
        case 3: _t->onButtonPressed((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->clearBufferText(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AeaQt::Keyboard::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractKeyboard::staticMetaObject>(),
    qt_meta_stringdata_AeaQt__Keyboard.data,
    qt_meta_data_AeaQt__Keyboard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AeaQt::Keyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AeaQt::Keyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AeaQt__Keyboard.stringdata0))
        return static_cast<void*>(this);
    return AbstractKeyboard::qt_metacast(_clname);
}

int AeaQt::Keyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractKeyboard::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
