#include <thread>
#include "py_try.h"
void py_catch::readdict()
{

	Py_SetPythonHome(L"./");//打开python文件目录
	Py_Initialize();//python初始化
	PyObject* mod = PyImport_GetModule(PyUnicode_FromString("__main__"));//获得python文件主模块
	FILE* fp = fopen(name, "r");
	PyRun_AnyFile(fp, name);//这里用c++的fstream会报错
	PyObject* func = PyObject_GetAttrString(mod, "getjson");
	PyObject* var = PyObject_CallObject(func, 0);
	PyObject* key = NULL;
	PyObject* val = NULL;

	for (int py_list_index = 0; py_list_index < 10; py_list_index++)
	{

		PyObject* varr = PyList_GetItem(var, py_list_index);//这里拿到列表里面十个列表中的其中一个
		for (int index = 0; index < 20; index++)
		{
			PyObject* varex = PyList_GetItem(varr, index);//这里拿到列表里的第index个字典
			vector<string> vstring;
			for (int i = 0; i < v1.size(); i++)//拿出字典里的数据
			{
				key = PyUnicode_FromString(v1[i]);
				val = PyDict_GetItem(varex, key);


				PyUnicode_AsWideChar(val, wstr, 100);
				vstring.push_back(py_catch().wideCharToMultiByte(wstr));
			}
			//	Py_XDECREF(varex);

				ConnectionPool* pool = ConnectionPool::getConnectionPool();
				thread(widget, pool, vstring).join();

			for (int i = 0; i < v1.size(); i++)
			{
				vstring.pop_back();
			}
		}
	}


}

py_catch::py_catch()
{
	keyinit();//键值初始化
	const char* name = "get_xinfadi.py";
}


py_catch::~py_catch()
{
	Py_XDECREF(func);
//	Py_XDECREF(mod);
//	Py_Finalize();
}

void py_catch::keyinit()
{
	//v1.push_back("id");//主键
	v1.push_back("prodName");//产品名
	v1.push_back("proCat");
	v1.push_back("lowPrice");//2
	v1.push_back("heigPrice");//
	v1.push_back("avgPrice");//
	v1.push_back("place");//产地 5
	v1.push_back("unitInfo");//单位
	v1.push_back("pubDate");//生产日期 7
}

string py_catch::wideCharToMultiByte(wchar_t* ws)
{
	int bufSize = WideCharToMultiByte(CP_ACP, NULL, ws, -1, NULL, 0, NULL, FALSE);
	//cout << bufSize << endl; 测试宽字符串长度
	char* sp = new char[bufSize];
	WideCharToMultiByte(CP_ACP, NULL, ws, -1, sp, bufSize, NULL, FALSE);
	string s1 = sp;
	s1 = "'" + s1 + "'";
	delete[]sp;
	return s1;
}

void widget(ConnectionPool* pool, vector<string> v1)
{
	shared_ptr<MysqlConn> conn = pool->getConnection();
	char sql[1024] = { 0 };
	sprintf(sql, "insert into xfd_clocal values (NULL,%s, %s, %s, %s)", v1[0].c_str(), v1[1].c_str(), v1[6].c_str(), v1[7].c_str());
	//cout << sql << "\n";
	conn->update(sql);

	sprintf(sql, "insert into xfd_cprice values (NULL,%s, %s, %s, %s, %s)", v1[0].c_str(), v1[2].c_str(), v1[3].c_str(), v1[4].c_str(),v1[6].c_str());
	//cout << sql << "\n";
	conn->update(sql);

	sprintf(sql, "insert into xfd_cuser values (%s, %s, %s, %s)", v1[0].c_str(), "'0'", "'莆田学院大学生创业基地'","'123456'");
//	cout << sql << "\n";
	conn->update(sql);
}
