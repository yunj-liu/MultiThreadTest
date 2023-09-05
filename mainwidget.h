#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "workthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void getThreadDoneInfo(const QString &info, const FigureData &figure_datatablemap);

private:
    Ui::MainWidget *ui;
    QLabel *statusLabel;
    QPushButton *quitButton;
    WorkThread *thread = nullptr;
};
#endif // MAINWIDGET_H
