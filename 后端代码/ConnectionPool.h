#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>
#include "my_mysql.h"
using namespace std;



class ConnectionPool {
public:
	static ConnectionPool* getConnectionPool()//这里的static函数不在cpp头文件中实现是为了避免编译出现问题
	{
		static ConnectionPool pool;
		return &pool;
	}

	ConnectionPool(const ConnectionPool& obj) = delete;//将含参构造函数和拷贝函数删除，防止出现连接池外泄
	ConnectionPool& operator=(const ConnectionPool& obj) = delete;
	shared_ptr<MysqlConn> getConnection();//获得池内的数据库连接

	~ConnectionPool();
private:
	ConnectionPool();//将构造函数隐藏，防止调用构造函数来获得连接
	bool parseJsonFile();//加载json文件
	void produceConnection();//创建线程
	void recycleConnection();//摧毁线程
	void addConnection();//加线程(无判断)

	string m_ip;
	string m_user;
	string m_passwd;
	string m_dbName;
	unsigned short m_port;
	int m_minSize;
	int m_maxSize;
	int m_timeout;//等待获得数据库链接的最大超时时长
	int m_maxIdleTime;//最大摸鱼时长

	queue<MysqlConn*> m_connectionQ;
	mutex m_mutexQ;
	condition_variable m_cond;
};