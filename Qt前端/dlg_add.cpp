#include "dlg_add.h"
#include "ui_dlg_add.h"
#include <QMessageBox>


dlg_add::dlg_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_add)
{
    ui->setupUi(this);
}

dlg_add::~dlg_add()
{
    delete ui;
}

void dlg_add::on_btn_save_clicked()
{
    vector<string> v1;
      v1[0] = ui->le_veg->text().toStdString();//qstring转string
      v1[1] = ui->le_stock->text().toStdString();
      v1[2] = ui->le_place->text().toStdString();
}

void dlg_add::on_btn_cancel_clicked()
{
    this->hide();
}

vector<string> dlg_add:: getvs()
{
    vector<string> v1;
     v1[0] = ui->le_veg->text().toStdString();//qstring转string
     v1[1] = ui->le_stock->text().toStdString();
      v1[2] = ui->le_place->text().toStdString();
      
    return v1;

}
