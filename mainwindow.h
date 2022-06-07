#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <idle_linux.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    idle_linux *dBus;
    QTimer *mytimer;
private slots:
    void open1();
    void open2();
    void twoFunc();
};

#endif // MAINWINDOW_H
