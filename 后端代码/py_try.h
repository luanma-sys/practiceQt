#pragma once
#include <iostream>
#include <fstream>
#include "json/json.h"
#include <Python.h>
#include <string>
#include <vector>

#include "ConnectionPool.h"
//#include "my_mysql.h"

using namespace Json;
using namespace std;



class py_catch
{
public:
	void readdict();//不知道为什么这个玩意在函数中可以传地址给二重指针，而在类中不能传地址给二重指针，所以我直接不传改成调用类内变量
	//上面这个函数可以得到python接口中给的字典数据，并调用widget进行数据库操作
	PyObject* var = NULL;

	~py_catch();//析构函数和构造函数
	py_catch();
	string wideCharToMultiByte(wchar_t* ws);//将python中得到的宽字符串转换成字符串

private:
	void keyinit();//初始化主键

	PyObject* mod = NULL;
	const char* name = "get_xinfadi.py";
	FILE* fp = NULL;
	PyObject* func = NULL;//以上四步为使用python接口前的初始化

	wchar_t wstr[101] = { 0 };
	vector<const char*> v1;//这两个本来是全局变量，但在类内调用这两个全局变量会报链接错误
};
void widget(ConnectionPool* pool, vector<string> v1);//类似触发器功能,用于sql插入
