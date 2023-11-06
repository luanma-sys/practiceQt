#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlg_add.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlError>
#include <QDebug>

#undef slots
#include "interface.h" //这个导致链接错误
#include "my_mysql.h"
#include "ConnectionPool.h"
#include "py_try.h"
#include "interface.cpp"
#undef slots Q_SLOTS
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_dlgLogin.show();

    auto f = [&](){
        this->show();
    };
    connect(&m_dlgLogin,&page_login::sendLoginSuccess,this,f);

    //------------------------------------数据库连接
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

   // connect(ui->btn_veget, &QPushButton::clicked, this,&MainWindow::on_btn_veget_clicked);
    //本来想建议起点击切换界面的连接，但测试的时候不需要这行代码也能切换，可能是系统帮我补全代码了？


    /*ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QStringList l;
    l<<"数据库信息";

    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pf);

    l.clear();
    l<<"菜价";
    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf,l);

    l.clear();
    l<<"仓库";
    QTreeWidgetItem *p2 = new QTreeWidgetItem(pf,l);

    pf->addChild(p1);
    pf->addChild(p2);
    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(0);*/
    //上面代码用于定义树构建，目前没用了

    updateTable();
    updateTable_veget();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}




void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    QStringList l;
    l << "菜名" << "库存" << "仓库";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setRowCount(query_user_count());
  //  ui->tableWidget->setRowCount(2);
     /*ui->tableWidget->setItem(1,0,new QTableWidgetItem("2"));
     ui->tableWidget->setItem(1,1,new QTableWidgetItem("122"));
     ui->tableWidget->setItem(1,2,new QTableWidgetItem("26"));
     ui->tableWidget->setItem(1,3,new QTableWidgetItem("52"));
     ui->tableWidget->setItem(1,4,new QTableWidgetItem("42"));
     ui->tableWidget->setItem(1,5,new QTableWidgetItem("23"));
     ui->tableWidget->setItem(1,6,new QTableWidgetItem("22"));*/

    MysqlConn conn;//建立数据库链接
    conn.connect("root", "123456", "studentsdb", "localhost");


    string sql = "select * from xfd_cuser";
    bool flag = conn.query(sql);//查询和输出语句
    for (int j = 0; conn.next();j++)//遍历查询结果
    {
        for (int i = 0; i < 7; i++)
        {
            cout << conn.value(i) << ",";
            //str1.push_back(conn.value(i));
            string s1 = conn.value(i);
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(QString::fromStdString(s1)));
        }
        cout << "\n";
    }

}

void MainWindow::updateTable_veget()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(7);
    QStringList l;
    l << "菜名" << "品种" << "最低价" << "最高价" << "平均价" << "单位" << "日期";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_2->setRowCount(query_veget_count());

    MysqlConn conn;//建立数据库链接
    conn.connect("root", "123456", "studentsdb", "localhost");


    string sql = "select s2.prodName,s1.proCat,s2.lowPrice,s2.heigPrice,s2.avgPrice,s2.unitInfo,s1.pubDate from xfd_clocal s1, xfd_cprice s2 where s1.prodName = s2.prodName";
    bool flag = conn.query(sql);//查询和输出语句
    for (int j = 0; conn.next(); j++)//遍历查询结果
    {
        for (int i = 0; i < 7; i++)
        {
            cout << conn.value(i) << ",";
            //str1.push_back(conn.value(i));
            string s1 = conn.value(i);
            ui->tableWidget_2->setItem(j, i, new QTableWidgetItem(QString::fromStdString(s1)));
        }
        cout << "\n";
    }
}

void MainWindow::on_btn_add_clicked()
{
//    m_dlgadd.setType(true);//这里的函数为一个界面两种功能，1为增加数据，0为修改数据 //现在成废案了
 //    m_dlgadd.exec();
    vector<string> v1;
    v1.push_back(ui->le_veget->text().toStdString());
    v1.push_back(ui->le_stock->text().toStdString());
    v1.push_back(ui->le_place->text().toStdString());
    insert_Vuser(v1);

    QMessageBox::question(this, "插入成功", "插入成功");
     updateTable();
 //    m_dlgadd.hide();
}

void MainWindow::on_pushButton_4_clicked()
{//废弃触发器，为qt运行太慢生成的废品

}

void MainWindow::on_btn_mofidy_clicked()
{
//    m_dlgadd.setType(false);//同上，成废案了


 //    m_dlgadd.exec();
    vector<string> v1;
    v1.push_back(ui->le_veget->text().toStdString());
    v1.push_back(ui->le_stock->text().toStdString());
    v1.push_back(ui->le_place->text().toStdString());
    modify_Vuser(v1);

    QMessageBox::question(this, "更改成功", "更改成功");
     updateTable();
 //    m_dlgadd.hide();
}

void MainWindow::on_btn_del_clicked()
{
    int i = ui->tableWidget->currentRow();
    //下面语句如果没有获取到数据会报错
    //QString s1 = ui->tableWidget->item(i,0)->text();

    string name = ui->tableWidget->item(i, 0)->text().toStdString();
    delete_Vuser(name);


    updateTable();
    QMessageBox::information(NULL,"信息","删除成功");

}

void MainWindow::on_btn_veget_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_btn_local_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_btn_findveget_clicked()
{
    String s1 = ui->le_search_2->text().toStdString();//这里vs可能会报错，找不到le_search_2，无视即可
    if (0 == s1.size())
    {
        updateTable_veget();
        return;
    }

    s1 = "'" + s1 + "'";

    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(7);
    QStringList l;
    l << "菜名" << "品种" << "最低价" << "最高价" << "平均价" << "单位" << "日期";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_2->setRowCount(query_veget_count());

    MysqlConn conn;//建立数据库链接
    conn.connect("root", "123456", "studentsdb", "localhost");


    string sql = "select s2.prodName,s1.proCat,s2.lowPrice,s2.heigPrice,s2.avgPrice,s2.unitInfo,s1.pubDate from xfd_clocal s1, xfd_cprice s2 where s1.prodName = s2.prodName";
    sql = sql + " and s1.prodName = " + s1;
    bool flag = conn.query(sql);//查询和输出语句
    for (int j = 0; conn.next(); j++)//遍历查询结果
    {
        for (int i = 0; i < 7; i++)
        {
            cout << conn.value(i) << ",";
            //str1.push_back(conn.value(i));
            string s1 = conn.value(i);
            ui->tableWidget_2->setItem(j, i, new QTableWidgetItem(QString::fromStdString(s1)));
        }
        cout << "\n";
    }
   // QMessageBox::question(this, "find", "find");
    //测试用代码
}

void MainWindow::on_btn_finduser_clicked()
{
    String s1 = ui->le_search_1->text().toStdString();//这里vs可能会报错，找不到le_search_1，无视即可
    if (0 == s1.size())
    {
        updateTable();
        return;
    }

    s1 = "'" + s1 + "'";


    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    QStringList l;
    l << "菜名" << "库存" << "仓库";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setRowCount(query_user_count());
    //  ui->tableWidget->setRowCount(2);
       /*ui->tableWidget->setItem(1,0,new QTableWidgetItem("2"));
       ui->tableWidget->setItem(1,1,new QTableWidgetItem("122"));
       ui->tableWidget->setItem(1,2,new QTableWidgetItem("26"));
       ui->tableWidget->setItem(1,3,new QTableWidgetItem("52"));
       ui->tableWidget->setItem(1,4,new QTableWidgetItem("42"));
       ui->tableWidget->setItem(1,5,new QTableWidgetItem("23"));
       ui->tableWidget->setItem(1,6,new QTableWidgetItem("22"));*/

    MysqlConn conn;//建立数据库链接
    conn.connect("root", "123456", "studentsdb", "localhost");


    string sql = "select * from xfd_cuser";

    sql = sql + " where prodName = " + s1;
    bool flag = conn.query(sql);//查询和输出语句
    for (int j = 0; conn.next(); j++)//遍历查询结果
    {
        for (int i = 0; i < 3; i++)
        {
            cout << conn.value(i) << ",";
            //str1.push_back(conn.value(i));
            string s1 = conn.value(i);
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(QString::fromStdString(s1)));
        }
        cout << "\n";
    }
  //  QMessageBox::question(this, "good", "good");依旧是测试用代码
}

void MainWindow::on_btn_catch_clicked()
{
    catch_vprice();
    updateTable_veget();
}












