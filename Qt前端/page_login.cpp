#include "page_login.h"
#include "ui_page_login.h"
page_login::page_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_login)
{
    ui->setupUi(this);
}

page_login::~page_login()
{
    delete ui;
}

void page_login::on_btn_login_clicked()
{
        this->hide();
        emit sendLoginSuccess();
}

void page_login::on_btn_exit_clicked()
{
    exit(0);
}
