#include"pre.h"


void prog::error_num() {
	switch (this->error_num) {
	case ERROR_NOERROR:
		cout << "��ǰû�д���" << endl;
		break;
	case ERROR_FAILINITDB:
		cout << "���ݿ��ʼ��ʧ��!" << endl;
		break;
	case ERROR_FAILCONDB:
		cout << "���ݿ�����ʧ��!" << endl;
		break;
	case ERROR_FAILCREDB:
		cout << "���ݿⴴ��ʧ��!" << endl;
		break;
	default:
		cout << "δ֪����" << endl;
	}

}