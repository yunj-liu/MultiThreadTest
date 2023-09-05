#ifndef COMMONTYPE_H
#define COMMONTYPE_H
#include <QWidget>

typedef QPair<QPointF, QString> Data;  //need include QWidget
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;
typedef QHash<QString, DataTable> FigureData;

#endif // COMMONTYPE_H
