#pragma once
#include <string>
#include <iostream>
#include <mysql.h>
#include <chrono>
using namespace std;
using namespace chrono;

class  MysqlConn{
public:
	MysqlConn();//构造函数和析构函数  在c++调用数据库是需要改变编码，这个问题我已经在构造函数中解决
	~MysqlConn();

	bool connect(string user, string passwd, string dbName, string ip, unsigned short port = 3306);//连接数据库函数，最后为默认ip接口

	bool update(string sql);//更新数据
	bool query(string sql);//查询数据
	bool next();//遍历得到的结果集
	string value(int index);//得到结果集 中的字段

	bool transaction();//事务操作，三个都是
	bool commit();
	bool rollback();
	
	void refreshAliveTime();//刷新起始的空闲时间
	long long getAliveTime();//计算链接存活的总时长
private:
	void freeResult();//回收资源
	MYSQL* m_conn = NULL;
	MYSQL_RES* m_result = NULL;//获得查询结果
	MYSQL_ROW m_row = NULL;//获得查询结果里的每个数据
	steady_clock::time_point m_alivetime;//统计时间工具变量
};