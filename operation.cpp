#include"MySQLinterface.h"
#include"Contacts.h"

operation::operation() {  }
operation::~operation() {  }

void operation::Initial(string& dbname,string &tablename) {
	mysql.ConnectDB();
	mysql.CreateDB(dbname);
	mysql.CreateTable(tablename);
}
void operation::Change() {

}
void operation::Delete() {

}
void operation::Entry() {
	mysql.WriteDataToDB()
}
void operation::Inquire(string&dbname,string&tablename,string &name) {
	mysql.ReadDataFromDB( tablename, name);

}
