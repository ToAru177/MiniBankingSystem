#ifndef _ACCOUNT_H_
#define	_ACCOUNT_H_

#include "MyString.h"

class Account
{
private:
	int accID;	//���¹�ȣ
	int balance; //�ܾ�
	//char *cusName;
	MyString cusName;

	// ���� ���� ����
	// 1 : ���� ����
	// 2 : �ſ� ����
	int index;	

public:

	// ������
	Account(int idx, int ID, int balance, const char *Name);
	// ���� ������
	Account(const Account &copy);
	// ���� ��ȣ�� �������� �Լ�
	int GetID(void) const;
	// ���� �ܾ��� �������� �Լ�
	int GetBalance(void) const;
	// ����� �̸��� �������� �Լ�
	char * GetName(void) const;
	// �Ա� ��� 
	virtual void Deposit(int money);
	// ��� ���
	void  Withdraw(int money);
	// ���� ���� ���
	void ShowAccountInfo() const;
	// �Ҹ���
	virtual ~Account();
	//friend class MyString;
	
	// index ��ȯ
	int GetIndex() const;
	
};

#endif // !_ACCOUNT_H_
