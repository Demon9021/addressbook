#include "MySQLinterface.h"

MySQLinterface::MySQLinterface(void)
{
	m_sock = NULL;
	m_SQLResultSet = NULL;
	m_IsConnect = FALSE;
	mysql_library_init(0, NULL, NULL);
	if (mysql_init(m_sock) == NULL) {
		printf("���ݿ��ʼ��ʧ��\n");
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
	cout << "���������ݿ��û���:" << endl;
	cin >> username;
	cout << "���������ݿ�����:" << endl;
	cin >> password;
	if (mysql_real_connect(m_sock, host, username, password, NULL, 0, NULL, 0) == NULL)
	{
		printf("���ݿ�����ʧ��\n");
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
	string sqlbuf1 = "INSERT INTO";
	string sqlbuf2 = "VALUES(";
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
		cout << "��ӳɹ���" << endl;
		return 1;
}
	else{
		this->error_num = ERROR_FAILTAWER;
		return 0;
	}


}
BOOL MySQLinterface::ReadDataFromDB(string& sqlbuf, string& tablename, string& name, string& birthdate, string& phonenumber, string& email, string& originizename) {
	string sqlbuf1 = "SELECT * FROM";
	sqlbuf = sqlbuf1 + tablename;
	if (mysql_query(m_sock, sqlbuf.c_str()) == 0)
	{

	}

}
void MySQLinterface::CloseMySQL() {
	mysql_close(m_sock);
}

