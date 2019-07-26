#include "MySQLinterface.h"

MySQLinterface::MySQLinterface(void)
{
	m_sock = NULL;
	m_SQLResultSet = NULL;
	m_IsConnect = FALSE;
	mysql_library_init(0, NULL, NULL);
	if (mysql_init(m_sock) == NULL) {
		printf("数据库初始化失败\n");
		this->error_num = ERROR_FAILINITDB;
	}
}
MySQLinterface::~MySQLinterface(void)
{
	if (m_sock) {
	}
	m_sock = NULL;
	m_SQLResultSet = NULL;
}
BOOL MySQLinterface::ConnectDB(){
	char* username;
	char* password;
	char* host = (char*)"localhost";
	cout << "请输入数据库用户名:" << endl;
	cin >> username;
	cout << "请输入数据库密码:" << endl;
	cin >> password;
	if (mysql_real_connect(m_sock, host, username, password, NULL, 0, NULL, 0) == NULL)
	{
		printf("数据库连接失败\n");
		this->error_num = ERROR_FAILCONDB;
		return 0;
	}
	else
		return 1;
}
BOOL MySQLinterface::CreateDB(string& dbname) {
	string queryStr ="CREATE DATABASES ";
	queryStr += dbname;
	if (mysql_query(m_sock, queryStr.c_str()) == 0)
	{
		return 1;
	}
	else {
		this->error_num = ERROR_FAILCREDB;
		return 0;
	}
}
BOOL MySQLinterface::CreateTable(string& tablename) {
	string queryStr = "CREATE TABLE";
	queryStr += tablename;
	if (mysql_query(m_sock, queryStr.c_str()) == 0)
	{
		return 1;
	}
	else {
		this->error_num = ERROR_FAILCRETA;
		return 0;
	}
}
BOOL MySQLinterface::WriteDataToDB(string& sqlbuf, string& tablename,string& name, string& birthdate, string& phonenumber, string& email, string& originizename) {
	string sqlbuf1 = "INSERT INTO ";
	string sqlbuf2 = " VALUES(";
	sqlbuf= sqlbuf1 + tablename + sqlbuf2;
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), name.c_str());
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), ",");
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), birthdate.c_str());
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), ",");
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), phonenumber.c_str());
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), ",");
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), email.c_str());
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), ",");
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), originizename.c_str());
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), ")");

	if (mysql_query(m_sock, sqlbuf.c_str) == 0)
	{
		mysql_commit(m_sock);
		cout << "添加成功！" << endl;
		return 1;
}
	else{
		this->error_num = ERROR_FAILTAWER;
		return 0;
	}


}
string * MySQLinterface::ReadDataFromDB(string& tablename, string& name) {
	static string parameter_buff[4];
	parameter_buff[0] = name;
	string sqlbuf1 = "SELECT * FROM";
	string sqlbuf = sqlbuf1 + tablename;
	if (mysql_query(m_sock, sqlbuf.c_str()) == 0)
	{
		printf("数据获取失败！\n");
		this->error_num = ERROR_FAILOBTDA;
		return 0;
	}
	
		unsigned uLine = 0,  uField = 0;
		MYSQL_ROW row;
		MYSQL_FIELD* pFieLd(NULL);
		if (!(m_SQLResultSet = mysql_store_result(m_sock)))
		{
			printf("内容获取失败！\n");
			this->error_num = ERROR_FAILOBTCO;
			return 0;
		}
		uLine = (unsigned)mysql_num_rows(m_SQLResultSet);
		uField = (unsigned)mysql_num_fields(m_SQLResultSet);
		for (int i = 0 ; i < (int)uLine ; i++)
		{
			row = mysql_fetch_row(m_SQLResultSet);
			for (int j = 0; j < (int)uField; j++)
			{
				parameter_buff[j] = row[j];
			}
			mysql_free_result(m_SQLResultSet);
			return parameter_buff;
		}
}
BOOL MySQLinterface::DeleteDataFromDB(string& sqlbuf, string& tablename,  string& del_name) {
	string sqlbuf1 = "DELETE FROM ";
	string sqlbuf2 = " WHERE name=";
	sqlbuf = sqlbuf1 + tablename + sqlbuf2;
	strcat((char*)sqlbuf.c_str(), "'");
	strcat((char*)sqlbuf.c_str(), del_name.c_str());
	strcat((char*)sqlbuf.c_str(), "'");

	if (mysql_query(m_sock, sqlbuf.c_str()))
	{
		printf("内容获取失败！\n");
		this->error_num = ERROR_FAILOBTCO;
		return 0;
	}
	mysql_commit(m_sock);
	cout << "删除成功！" << endl;
}
void MySQLinterface::CloseMySQL() {
	mysql_close(m_sock);
}
