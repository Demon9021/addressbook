#include"MYSQLinterface.h"


void prog::start_menu() {
	system("cls");
	cout << "Connection to SQL\n";
	printf(" -------------------------------------------------- - \n");
	printf("                欢迎使用通讯录管理系统                \n");
	printf(" -------------------------------------------------- - \n");
    printf("      [1].进入通讯录管理系统       [0].退出系统:");
}
void prog::end_menu(MYSQL* sock)
{
	mysql.CloseMySQL();
	system("cls");
    
	printf(" --------------------------------------------------\n");
	printf("                      退出系统！                    \n");
	printf(" --------------------------------------------------\n");
	system("pause");
	exit(0);
}
void prog::operate_menu()
{
	system("cls");
	printf(" --------------------------------------------------------------------\n");
	printf("                               选择操作                              \n");
	printf("    [4].查询联系人     [5].添加联系人    [6].删除联系人    [0].退出系统    \n");
	printf(" --------------------------------------------------------------------\n");
}

