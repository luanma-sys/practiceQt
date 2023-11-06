#include "my_mysql.h"

MysqlConn::MysqlConn()
{
	m_conn = mysql_init(NULL);//初始化mysql
	mysql_set_character_set(m_conn, "utf8");//设置mysql编码
}

MysqlConn::~MysqlConn()//释放已经申请的mysql资源
{
	if (m_conn != NULL)
		mysql_close(m_conn);//关闭mysql
	freeResult();
}

bool MysqlConn::connect(string user, string passwd, string dbName, string ip, unsigned short port)//连接mysql数据库
{
	MYSQL* ptr = mysql_real_connect(m_conn, ip.c_str(), user.c_str(), passwd.c_str(), dbName.c_str(), port, NULL, 0);//连接数据库
	return ptr!=NULL;
}

bool MysqlConn::update(string sql)//更新数据
{
	if(mysql_query(m_conn,sql.c_str()))//如果执行失败返回0，if里面为执行sql的函数
		return false;
	return true;
}

bool MysqlConn::query(string sql)//查询
{
	freeResult();//清空数据,防止上一次操作的结果污染变量

	if (mysql_query(m_conn, sql.c_str()))//如果执行失败返回0
		return false;

	m_result = mysql_store_result(m_conn);//获得查询后的结果
	return true;
}

bool MysqlConn::next()//如果还有数据(行)没拿出来就返回true
{
	if (m_result != NULL)
	{
		m_row = mysql_fetch_row(m_result);//得到数据
		if (m_row != NULL)
			return true;

	}
	return false;
}

string MysqlConn::value(int index)//配合上一个函数使用，拿出数据行里的指定列数数据,配合循环可以拿出每一列数据
{
	int rowNum = mysql_num_fields(m_result);//得到数据行的列数
	if (index >= rowNum || index < 0)
		return string();

	char* val = m_row[index];
	unsigned long length = mysql_fetch_lengths(m_result)[index];//得到指定列的数据
	return string(val,length);
}

bool MysqlConn::transaction()//开始一段事务操作
{
	return mysql_autocommit(m_conn,false);//false为禁止自动提交
}

bool MysqlConn::commit()
{
	return mysql_commit(m_conn);//提交事务
}

bool MysqlConn::rollback()
{
	return mysql_rollback(m_conn);//回滚数据
}

void MysqlConn::refreshAliveTime()
{
	m_alivetime = steady_clock::now();//获得时间
}

long long MysqlConn::getAliveTime()//执行的时间
{
	nanoseconds res = steady_clock::now() - m_alivetime;//得到运行到这里的时间减去一开始的时间
	milliseconds millsec = duration_cast<milliseconds>(res);//转换时间单位
	return millsec.count();//返回
}

void MysqlConn::freeResult()
{
	if (m_result)
	{
		mysql_free_result(m_result);//释放还存在的数据
		m_result = NULL;
	}
}
