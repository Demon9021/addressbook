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

#define ERROR_NOERROR 0           //�����룺��ǰû�д���
#define ERROR_FAILINITDB 1          //�����룺���ݿ��ʼ��ʧ��
#define ERROR_FAILCONDB 2        //�����룺���ݿ�����ʧ��
#define ERROR_FAILCREDB 3          //�����룺���ݿⴴ��ʧ�� 
#define ERROR_FAILCRETA 4          //�����룺���ݿ����ʧ��
#define ERROR_FAILTAWER 5         //�����룺���ݿ��дʧ��
#define ERROR_FAILTARER 6          //�����룺���ݿ���ʧ��


#endif


