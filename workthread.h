#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include "commontype.h"

class WorkThread : public QThread
{
    Q_OBJECT

public:
    WorkThread(QObject *parent = nullptr);
    void run() override;

signals:
    void SendDoneInfo(const QString &info, const FigureData &figure_datatablemap);
};

#endif // WORKTHREAD_H
