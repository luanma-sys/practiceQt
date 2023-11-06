#include "interface.h"
void query_All_Vprice()//查询菜价库
{
	MysqlConn conn;//建立数据库链接
	conn.connect("root", "123456", "studentsdb", "localhost");


	string sql = "select s2.prodName,s1.proCat,s2.lowPrice,s2.heigPrice,s2.avgPrice,s2.unitInfo,s1.pubDate from xfd_clocal s1, xfd_cprice s2 where s1.prodName = s2.prodName";
	bool flag = conn.query(sql);//查询和输出语句
	while (conn.next())//遍历查询结果
	{
		vector<string> str1;
		for (int i = 0; i < 7; i++)
		{
			cout << conn.value(i) << ",";
			str1.push_back(conn.value(i));
		}
		cout << "\n";
	}
}
//下面3个同理,后两个是定向搜索
void query_All_Vuser()
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");


	string sql = "select * from xfd_cuser";
	bool flag = conn.query(sql);
	while (conn.next())
	{
		for (int i = 0; i < 4; i++)
		{
			cout << conn.value(i) << ",";
		}
		cout << "\n";
	}
}

void query_Vprice(string vegetable)
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");


	vegetable = "'" + vegetable + "'";
	string sql = "select s2.prodName,s1.proCat,s2.lowPrice,s2.heigPrice,s2.avgPrice,s2.unitInfo,s1.pubDate from xfd_clocal s1, xfd_cprice s2 where s1.prodName = s2.prodName and s1.prodName = " + vegetable;
	bool flag = conn.query(sql);
	while (conn.next())
	{
		for (int i = 0; i < 7; i++)
		{
			cout << conn.value(i) << ",";
		}
		cout << "\n";
	}
}

void query_Vuser(string vegetable)
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	vegetable = "'" + vegetable + "'";
	string sql = "select * from xfd_cuser where prodName = " + vegetable;
	bool flag = conn.query(sql);
	while (conn.next())
	{
		for (int i = 0; i < 4; i++)
		{
			cout << conn.value(i) << ",";
		}
		cout << "\n";
	}
}

void insert_Vuser(vector<string> vegetable)//插入数据
{	
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	str_polish(vegetable);

	char sql[1024] = { 0 };
	sprintf(sql, "insert into xfd_cuser values(%s, %s, %s, '123456')", vegetable[0].c_str(), vegetable[1].c_str(), vegetable[2].c_str());
	cout << conn.update(sql)<<"\n";
}

void delete_Vuser(string vegetable)// 删除
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	vegetable = "'" + vegetable + "'";

	string sql = "delete from xfd_cuser where prodName = " + vegetable;

	cout << conn.update(sql);
}

void modify_Vuser(vector<string> vegetable)//容器内第一个数据为目标数据(菜名)，23数据为要修改的数据，修改的数据为库存 和 仓库地点
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	str_polish(vegetable);

	char sql[1024] = { 0 };
	sprintf(sql, "update xfd_cuser set stock = %s,place = %s where prodName = %s;", vegetable[1].c_str(), vegetable[2].c_str(), vegetable[0].c_str());
	cout << conn.update(sql);
}

void catch_vprice()//爬虫
{
	py_catch *py = new py_catch();
	py->readdict();
	delete py;
}

void str_polish(vector<string>& vegetable) //加工字符串
{
	for (int i = 0; i < vegetable.size(); i++)
	{
		vegetable[i] = "'" + vegetable[i] + "'";
	}
}

int query_veget_count()//下面两个为显示数据库数据总数
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	string sql = "select count(*) from xfd_clocal";
	bool flag = conn.query(sql);
	conn.next();//
	return stoi(conn.value(0));//string转换成int
}

int query_user_count()
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	string sql = "select count(*) from xfd_cuser";
	bool flag = conn.query(sql);
	conn.next();//
	return stoi(conn.value(0));

}

void query_two(string s1, string s2)
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");


	s1 = "'" + s1 + "'";
	s2 = "'" + s2 + "'";
	char sql[1024] = { 0 };
	sprintf(sql, "select s2.prodName,s1.proCat,s2.lowPrice,s2.heigPrice,s2.avgPrice,s2.unitInfo,s1.pubDate from xfd_clocal s1, xfd_cprice s2 where s1.prodName = s2.prodName and s1.prodName = %s and s1.pubDate = %s", s1.c_str(), s2.c_str());
	bool flag = conn.query(sql);
	while (conn.next())
	{
		for (int i = 0; i < 4; i++)
		{
			cout << conn.value(i) << ",";
		}
		cout << "\n";
	}

}

/*int user_count()
{
	MysqlConn conn;
	conn.connect("root", "123456", "studentsdb", "localhost");

	string sql = "select count(*) from xfd_cuser";
	bool flag = conn.query(sql);
	conn.next();
	string s = conn.value(0);
	int num = 0;
	for (int i = 0; i < s.size(); ++i) {
		num = 10 * num + (s[i] - '0');
	}

	return num;
}*/
