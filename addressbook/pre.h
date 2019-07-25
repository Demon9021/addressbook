#pragma once

#ifndef ADDRESSBOOK_PRE_H
#define ADDRESSBOOK_PRE_H

#include"mysql.h"
#include<windows.h>
#include"winsock.h"
#include<vector>
#include<string>
#include<iostream>
#pragma comment(lib,"libmySQL.lib")

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;



class prog{
	prog(void);
	~prog(void){  }
public:
	void start_menu();
	void end_menu(MYSQL*);
	void operate_menu();
	void error_num();
};

#define ERROR_NOERROR 0           //错误码：当前没有错误
#define ERROR_FAILINITDB 1          //错误码：数据库初始化失败
#define ERROR_FAILCONDB 2        //错误码：数据库连接失败
#define ERROR_FAILCREDB 3          //错误码：数据库创建失败 
#define ERROR_FAILCRETA 4          //错误码：数据库表创建失败
#define ERROR_FAILTAWER 5         //错误码：数据库表写失败
#define ERROR_FAILTARER 6          //错误码：数据库表读失败


#endif


