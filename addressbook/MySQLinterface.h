#pragma once
#include"pre.h"

class MySQLinterface {
public:
	 MySQLinterface();
	~MySQLinterface(){   }
    BOOL ConnectDB();
	BOOL CreateDB(string&);
	BOOL CreateTable(string &);
	BOOL WriteDataToDB(string&,string&,string&,string&,string&,string&,string&);
	BOOL ReadDataFromDB(string&, string&, string&, string&, string&, string&, string&);
	BOOL DeleteDataFromDB();
	void    CloseMySQL();
public:	
	int error_num;

private:
	MYSQL* m_sock;
	MYSQL_RES* m_SQLResultSet;
protected:
	BOOL m_IsConnect;
}mysql;