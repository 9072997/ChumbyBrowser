/****************************************************************************
** Meta object code from reading C++ file 'chumbypage.h'
**
** Created: Sun Mar 17 19:12:00 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chumbypage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chumbypage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChumbyPage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChumbyPage[] = {
    "ChumbyPage\0\0addCommandHandlerToFrame()\0"
    "addWidgetHandlerToFrame()\0"
};

const QMetaObject ChumbyPage::staticMetaObject = {
    { &QWebPage::staticMetaObject, qt_meta_stringdata_ChumbyPage,
      qt_meta_data_ChumbyPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChumbyPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChumbyPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChumbyPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChumbyPage))
        return static_cast<void*>(const_cast< ChumbyPage*>(this));
    return QWebPage::qt_metacast(_clname);
}

int ChumbyPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addCommandHandlerToFrame(); break;
        case 1: addWidgetHandlerToFrame(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
