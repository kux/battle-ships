/****************************************************************************
** Meta object code from reading C++ file 'qtview.h'
**
** Created: Sat Dec 13 06:52:30 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtView[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      11,    8,    7,    7, 0x08,
      28,    7,    7,    7, 0x08,
      37,    7,    7,    7, 0x08,
      46,    7,    7,    7, 0x08,
      57,    7,    7,    7, 0x08,
      68,    7,    7,    7, 0x08,
      80,    7,    7,    7, 0x08,
      93,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QtView[] = {
    "QtView\0\0id\0gridClicked(int)\0attack()\0"
    "moveup()\0movedown()\0moveleft()\0"
    "moveright()\0rotateleft()\0rotateright()\0"
};

const QMetaObject QtView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QtView,
      qt_meta_data_QtView, 0 }
};

const QMetaObject *QtView::metaObject() const
{
    return &staticMetaObject;
}

void *QtView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtView))
        return static_cast<void*>(const_cast< QtView*>(this));
    if (!strcmp(_clname, "View"))
        return static_cast< View*>(const_cast< QtView*>(this));
    return QDialog::qt_metacast(_clname);
}

int QtView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gridClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: attack(); break;
        case 2: moveup(); break;
        case 3: movedown(); break;
        case 4: moveleft(); break;
        case 5: moveright(); break;
        case 6: rotateleft(); break;
        case 7: rotateright(); break;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
