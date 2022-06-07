#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mytimer = new QTimer;
    //mytimer->start(30000);
    dBus = new idle_linux;
    QString asd;
    asd = "asd";
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(open1()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(open2()));
    connect(mytimer, SIGNAL(timeout()), this, SLOT(twoFunc()));

    //dBus->preventDisplay(asd);
    //dBus->allowDisplay();
}

void MainWindow::open1()
{
    QString asd;
    asd = "asd";
    dBus->preventDisplay(asd);
    //dBus->allowDisplay();
}
void MainWindow::open2()
{
    QString asd;
    asd = "asd";
    //dBus->preventDisplay(asd);
    dBus->allowDisplay();
}

void MainWindow::twoFunc()
{
    open1();
    open2();
}

MainWindow::~MainWindow()
{
    delete ui;
}
