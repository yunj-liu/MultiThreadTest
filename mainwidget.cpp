#include "mainwidget.h"
#include "./ui_mainwidget.h"
#include <QHBoxLayout>


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , thread(new WorkThread(this))
{
    ui->setupUi(this);
    statusLabel = new QLabel;
    statusLabel->setWordWrap(true);
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);

    statusLabel->setText(tr("程序正在启动,请等待..."));
    connect(quitButton, &QPushButton::clicked, this, &MainWidget::close);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    //WorkThread *thread = new WorkThread(this);
    connect(thread, &WorkThread::SendDoneInfo, this, &MainWidget::getThreadDoneInfo);
    connect(thread, &WorkThread::finished, thread, &WorkThread::deleteLater);
    thread->start();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::getThreadDoneInfo(const QString &info, const FigureData &figure_datatablemap){
    QString str = QString::number(figure_datatablemap[tr("figure1")].at(0).at(0).first.x());
    statusLabel->setText(tr("Dll计算已经完成") + str);
}

