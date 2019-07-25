#pragma once

#ifndef ADDRESSBOOK_CONTACTS_H
#define ADDRESSBOOK_CONTACTS_H

#include"pre.h"

struct contacts {                         //��ϵ������
	string name;
	string birthdate;
	string phonenumber;
	string email;
	string originizename;
};
           
class operation {                         //������������
public:
	operation();
	~operation(){  }
	void Initial();
	void Entry();
	void Inquire();
	void Change();
	void Delete();
};
enum category {                         //ͨѶ¼��ǩö��
	classmate,
    colleague,
	family,
	friends
}; 

struct contact_node {
	contacts* info;                         //�ýڵ���ϵ����Ϣ
	contact_node* next;                //ָ����һ����ϵ�˽ڵ�ָ��
}; 


#endif