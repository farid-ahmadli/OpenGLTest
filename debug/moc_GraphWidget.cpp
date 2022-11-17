/****************************************************************************
** Meta object code from reading C++ file 'GraphWidget.h'
**
** Created: Wed 20. Jan 17:38:50 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GraphWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GraphWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   12,   13,   12, 0x0a,
      35,   29,   12,   12, 0x0a,
      61,   59,   51,   12, 0x0a,
      95,   88,   12,   12, 0x0a,
     110,   12,   12,   12, 0x0a,
     123,   12,   12,   12, 0x0a,
     149,  140,   13,   12, 0x0a,
     176,  140,   13,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GraphWidget[] = {
    "GraphWidget\0\0bool\0isActive()\0value\0"
    "showTitle(bool)\0QPointF\0p\0"
    "pixelPosToViewPos(QPointF)\0scroll\0"
    "setScroll(int)\0clearScene()\0"
    "plotGraph(Graph)\0filename\0"
    "savePlotImage(std::string)\0"
    "savePlot2SVG(std::string)\0"
};

const QMetaObject GraphWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GraphWidget,
      qt_meta_data_GraphWidget, 0 }
};

const QMetaObject *GraphWidget::metaObject() const
{
    return &staticMetaObject;
}

void *GraphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphWidget))
        return static_cast<void*>(const_cast< GraphWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GraphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = isActive();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: showTitle((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: { QPointF _r = pixelPosToViewPos((*reinterpret_cast< const QPointF(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPointF*>(_a[0]) = _r; }  break;
        case 3: setScroll((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: clearScene(); break;
        case 5: plotGraph((*reinterpret_cast< const Graph(*)>(_a[1]))); break;
        case 6: { bool _r = savePlotImage((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = savePlot2SVG((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
