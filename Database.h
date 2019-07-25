#pragma once
#include"pre.h"
class DataAccess {
public:
	DataAccess(void);
	~DataAccess(void);
private:
	MYSQL* sock;
	MYSQL_RES* m_pSQLResultSet;
protected:
	bool m_bIsconnect;
public:
	bool ConnectDB(const string& strHost, const int nPort, const string& strDBName, const string& strUserName, const string& strPassword);
	bool ExecuteQuery(string& strSQL);
};
