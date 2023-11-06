#pragma once
#include "py_try.h"
//#include "ConnectionPool.h"
//#include "my_mysql.h"
#include <string>
#include <vector>
using namespace std;

//vector<vector<string>> veget;
//vector<vector<string>> user;

void query_All_Vprice();//查询所有菜价数据

void query_All_Vuser();//查询所有用户数据

void query_Vprice(string vegetable);//查询目标菜价

void query_Vuser(string vegetable);//查询仓库内蔬菜信息

void insert_Vuser(vector<string> vegetable);//插入仓库数据

void delete_Vuser(string vegetable);//删除仓库数据

void modify_Vuser(vector<string> vegetable);//修改仓库数据

void catch_vprice();//爬取数据


void str_polish(vector<string>& vegetable);//把字符串加工成方便用于实现sql语句的字符串
int query_veget_count();//统计菜的数量，用于确定到底有多少数据需要显示，提前确定好前端显示容器的大小
int query_user_count();//跟上面一样，但是用来确定用户数量的


void query_two(string s1, string s2);