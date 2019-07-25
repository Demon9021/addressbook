#include"pre.h"


void prog::error_num() {
	switch (this->error_num) {
	case ERROR_NOERROR:
		cout << "当前没有错误！" << endl;
		break;
	case ERROR_FAILINITDB:
		cout << "数据库初始化失败!" << endl;
		break;
	case ERROR_FAILCONDB:
		cout << "数据库连接失败!" << endl;
		break;
	case ERROR_FAILCREDB:
		cout << "数据库创建失败!" << endl;
		break;
	default:
		cout << "未知错误！" << endl;
	}

}