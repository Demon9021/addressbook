#pragma once
#include"pre.h"

class MySQLinterface
{
public:
	MYSQLinterface(void);
	~MYSQLinterface(void) {   };
public:

	BOOL ConnectDB();
	int ExecuteQuery(string& strSQL);

private:
	MYSQL* m_sock;
	MYSQL_RES* m_SQLResultSet;
protected:
	int m_IsConnect;

};


