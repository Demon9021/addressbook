#pragma once

#ifndef ADDRESSBOOK_CONTACTS_H
#define ADDRESSBOOK_CONTACTS_H

#include"pre.h"

struct contacts {                         //联系人属性
	string name;
	string birthdate;
	string phonenumber;
	string email;
	string originizename;
};
           
class operation {                         //操作函数集合
public:
	operation();
	~operation(){  }
	void Initial(string & ,string &);
	void Entry();
	void Inquire(string &,string&,string& );
	void Change();
	void Delete();
}operate;
enum category {                         //通讯录标签枚举
	classmate,
    colleague,
	family,
	friends
}; 

struct contact_node {
	contacts* info;                         //该节点联系人信息
	contact_node* next;                //指向下一个联系人节点指针
}; 


#endif
