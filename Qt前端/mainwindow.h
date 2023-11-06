#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include "page_login.h"
#include <QMainWindow>
#include "dlg_add.h"
#include <vector>
#include <string>
//#include "interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_exit_clicked();

   // void on_pushButton_5_clicked();

    void on_btn_add_clicked();

    void on_pushButton_4_clicked();

    void on_btn_mofidy_clicked();

    void on_btn_del_clicked();

    void on_btn_veget_clicked();

    void on_btn_local_clicked();

    void on_btn_findveget_clicked();

    void on_btn_finduser_clicked();

    void on_btn_catch_clicked();
public:
    void updateTable();//刷新数据

    void updateTable_veget();

private:
    Ui::MainWindow *ui;
    page_login m_dlgLogin;
    dlg_add m_dlgadd;

};
#endif // MAINWINDOW_H
