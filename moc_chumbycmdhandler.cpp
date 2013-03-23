/****************************************************************************
** Meta object code from reading C++ file 'chumbycmdhandler.h'
**
** Created: Sun Mar 17 05:08:55 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chumbycmdhandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chumbycmdhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChumbyCommandHandler[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      43,   34,   22,   21, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ChumbyCommandHandler[] = {
    "ChumbyCommandHandler\0\0QVariantMap\0"
    "cmd,args\0run(QString,QStringList)\0"
};

const QMetaObject ChumbyCommandHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChumbyCommandHandler,
      qt_meta_data_ChumbyCommandHandler, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChumbyCommandHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChumbyCommandHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChumbyCommandHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChumbyCommandHandler))
        return static_cast<void*>(const_cast< ChumbyCommandHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int ChumbyCommandHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QVariantMap _r = run((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
