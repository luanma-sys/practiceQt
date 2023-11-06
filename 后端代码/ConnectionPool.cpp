#include "ConnectionPool.h"
#include <fstream>
#include <thread>
#include "json/json.h"//要在源目录下面加dll文件，否则报错
using namespace Json;

/*ConnectionPool* ConnectionPool::getConnectionPool()
{
	static ConnectionPool pool;
	return &pool;
}*/


shared_ptr<MysqlConn> ConnectionPool::getConnection()
{
	unique_lock<mutex> locker(m_mutexQ);
	while (m_connectionQ.empty())
	{
		if (cv_status::timeout == m_cond.wait_for(locker, chrono::milliseconds(m_timeout)))
		{
			if (m_connectionQ.empty())
			{
				cout << "continue\n";
				continue;
			}
		}
	}
	shared_ptr<MysqlConn> connptr(m_connectionQ.front(), [this](MysqlConn* conn) {
		lock_guard<mutex> locker(m_mutexQ);//确保刷新的时间是conn的
		conn->refreshAliveTime();
		m_connectionQ.push(conn);//用完换回来
		});//lambda为智能指针的析构函数

	m_connectionQ.pop();
	m_cond.notify_all();//唤醒生产者线程的锁

	return connptr;
}

ConnectionPool::~ConnectionPool()
{
	while (!m_connectionQ.empty())
	{
		MysqlConn* conn = m_connectionQ.front();
		m_connectionQ.pop();
		delete conn;
	}
}

ConnectionPool::ConnectionPool()
{
	if (!parseJsonFile())
	{
		return;
	}

	for (int i = 0; i < m_minSize; ++i)
	{
		addConnection();
	}
	thread producer(&ConnectionPool::produceConnection,this);
	thread recycler(&ConnectionPool::recycleConnection,this);
	producer.detach();
	recycler.detach();
}

bool ConnectionPool::parseJsonFile()//这个函数有一个bug会导致程序崩溃，好像被我修复了
{
	ifstream ifs("dbconf.json");
	Reader rd;
	Value root;
	rd.parse(ifs, root);

	if (root.isObject())
	{
		m_ip = root["ip"].asString();
		m_port = root["port"].asInt();
		m_user = root["userName"].asString();
		m_passwd = root["password"].asString();
		m_dbName = root["dbName"].asString();
		m_minSize = root["minSize"].asInt();
		m_maxSize = root["maxSize"].asInt();
		m_maxIdleTime = root["maxIdleTime"].asInt();
		m_timeout = root["timeout"].asInt();
		return true;
	}
	
	return false;
}

void ConnectionPool::produceConnection()
{
	while (true)
	{
		unique_lock<mutex> locker(m_mutexQ);
		while (m_connectionQ.size() >= m_minSize)//用while而不用if是为了保护线程池
		{
			m_cond.wait(locker);
		}
		addConnection();
		m_cond.notify_all();//唤醒消费者线程的锁
	}
}

void ConnectionPool::recycleConnection()
{
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(1));
		lock_guard<mutex> locker(m_mutexQ);
		while (m_connectionQ.size() > m_minSize)
		{
			MysqlConn* conn = m_connectionQ.front();
			if (conn->getAliveTime() >= m_maxIdleTime)
			{
				m_connectionQ.pop();
				delete conn;
			}
			else
			{
				break;
			}
		}
	}
}

void ConnectionPool::addConnection()
{
	MysqlConn* conn = new MysqlConn;
	conn->connect(m_user, m_passwd, m_dbName, m_ip, m_port);
	conn->refreshAliveTime();
	m_connectionQ.push(conn);
}
