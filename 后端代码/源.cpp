#include <memory>
#include "my_mysql.h"
#include "ConnectionPool.h"
#include <iostream>
#include <vector>
#include "py_try.h"
#include <string>
#include "interface.h"
#include <cstdlib>
/*void query()
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	
	string sql = "select count(*) from xfd_clocal";
	bool flag = conn.query(sql);
	while (conn.next())
	{

			cout << conn.value(0) << ",";

	}
}

void widget(ConnectionPool* pool, int begin, int endd)
{
	for (int i = begin; i < endd; i++)
	{
		shared_ptr<MysqlConn> conn = pool->getConnection();
		char sql[1024] = { 0 };
		string s1 = "'男'";
		sprintf(sql, "insert into student_info values(%d, '', %s, '2000-12-12','rua')", i,s1.c_str());
		cout << "开始更新         ";
		conn->update(sql);
		cout << "插入成功\n";
	}
}

void test1()
{
	ConnectionPool* pool = ConnectionPool::getConnectionPool();
	cout << "123/n";
	widget(pool, 1, 50);

	cout << "win-win\n";
}

void test2()
{
	ConnectionPool* pool = ConnectionPool::getConnectionPool();
	vector<thread> v1;
	for (int i = 0; i < 5; i++)
	{
		//v1.push_back(thread(widget, pool, 1240, 1252));
	}

	for (int i = 0; i < 5; i++)
	{
		//v1[i].join();
	}
}

void create()
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

		
	string c_ah = "create table if not exists xfd_person_user(\n\
		user_login varchar(18) not null primary key, \n\
		password varchar(20) comment '密码', \n\
		name varchar(10) comment '昵称')";

	char sql[1024] = { 0 };
	sprintf(sql, c_ah.data());
	cout << conn.update(sql);

}
*/
int main()
{
	while (1)
	{
		cout << "1.显示菜价数据库\n2.显示仓库数据库\n3.增加仓库信息数据\n4.删除仓库数据\n5.修改仓库数据\n6.查询仓库的数据\n7.查询菜价数据库里有多少条数据\n8.爬取数据\n9.查询菜价数据库的数据\n0.退出系统\n";
	
		vector<string>v;	string s1;
		char i;
		cin >> i;
		int index = i - '0';
		switch (index)
		{
		case 1:query_All_Vprice(); break;
		case 2:query_All_Vuser(); break;
		case 3:	cout << "输入菜名\n";	cin >> s1;v.push_back(s1);
				cout << "输入库存\n";	cin >> s1;	v.push_back(s1);
				cout << "输入仓库\n";	cin >> s1;	v.push_back(s1);
				insert_Vuser(v);break;
		case 4:cout << "输入要删除的菜数据\n"; cin >> s1;
			delete_Vuser(s1);	break;
		case 5:cout << "输入要修改菜名\n";	cin >> s1; v.push_back(s1);
			cout << "输入修改后的库存\n";	cin >> s1;	v.push_back(s1);
			cout << "输入修改后的仓库\n";	cin >> s1;	v.push_back(s1);
			modify_Vuser(v);break;
		case 6:cout << "输入菜名\n"; cin >> s1;
			query_Vuser(s1);	break;
		case 7:cout<<query_veget_count()<<"\n"; break;
		case 8:catch_vprice(); break;
		case 9://cout << "输入菜名\n";	cin >> s1;
			query_two("红提", "2022-09-09 00:00:00");	break;
		case 0:return 0; break;
		default:cout << "输入有效数字\n";
		}
		

		system("pause");
		system("cls");
	}
	

	/*query_Vprice("大白菜");
	query_Vuser("大白菜");

	delete_Vuser("大白菜");
	*/
	/*vector<string> vs;
	vs.push_back("羊蝎子");
	vs.push_back("22");
	vs.push_back("莆院文正楼");
	//insert_Vuser(vs);

	modify_Vuser(vs);

	return 0;*/


}