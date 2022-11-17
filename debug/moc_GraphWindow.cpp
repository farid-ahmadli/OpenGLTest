/****************************************************************************
** Meta object code from reading C++ file 'GraphWindow.h'
**
** Created: Wed 20. Jan 17:38:57 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GraphWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GraphWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      22,   13,   12,   12, 0x08,
      55,   12,   12,   12, 0x08,
      90,   86,   12,   12, 0x08,
     139,   12,   12,   12, 0x08,
     162,   12,   12,   12, 0x08,
     185,   12,   12,   12, 0x08,
     210,   12,   12,   12, 0x08,
     233,   12,   12,   12, 0x08,
     255,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GraphWindow[] = {
    "GraphWindow\0\0position\0"
    "on_hsbLineGraph_sliderMoved(int)\0"
    "on_actionShowTitle_triggered()\0pos\0"
    "on_graphScene_customContextMenuRequested(QPoint)\0"
    "on_saveGraph_clicked()\0on_editGraph_clicked()\0"
    "on_removeGraph_clicked()\0"
    "on_plotGraph_clicked()\0on_addGraph_clicked()\0"
    "on_loadGraph_clicked()\0"
};

const QMetaObject GraphWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GraphWindow,
      qt_meta_data_GraphWindow, 0 }
};

const QMetaObject *GraphWindow::metaObject() const
{
    return &staticMetaObject;
}

void *GraphWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphWindow))
        return static_cast<void*>(const_cast< GraphWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int GraphWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_hsbLineGraph_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_actionShowTitle_triggered(); break;
        case 2: on_graphScene_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: on_saveGraph_clicked(); break;
        case 4: on_editGraph_clicked(); break;
        case 5: on_removeGraph_clicked(); break;
        case 6: on_plotGraph_clicked(); break;
        case 7: on_addGraph_clicked(); break;
        case 8: on_loadGraph_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
