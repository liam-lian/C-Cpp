#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>
#include <QFileDialog>
#include <QDebug>
#include "qt_windows.h"
#include <QFile>
#include <QTextCodec>
#include "connection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QAxObject *cell;
    void generate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();


    void on_StartTime_userDateChanged(const QDate &date);


private:
    Ui::MainWindow *ui;
    QString *name;
    int holiday[800];
    void sethaha();
};

#endif // MAINWINDOW_H
