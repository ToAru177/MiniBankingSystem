#pragma once

#include "Account.h"
#include "MyString.h"

// ���뿹�ݰ��� Entity Ŭ����
/*
	���뿹�ݰ��� Ŭ������ ���������� ����� �� �ֵ��� �Ѵ�.
*/
class NormalAccount : public Account {
private:
	double ratio;	// ����
public:
	// ���뿹�ݰ��� ������
	NormalAccount(int idx, int ID, int balance, const char *Name, double ratio);
	// ���뿹�ݰ��� �Ա�
	void Deposit(int money);
	~NormalAccount();
};
