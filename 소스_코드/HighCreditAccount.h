#ifndef	_HIGHCREDITACCOUNT_H_
#define _HIGHCREDITACCOUNT_H_

#include "NormalAccount.h"
#include "MyString.h"

// �ſ�ŷڰ��� Entity Ŭ����
/*
	���� �ſ����� A, B, C�� ������ ���°����� �� ������ ����Ѵ�.
	A, B, C ��޺��� ���� �⺻������ 7%, 4%, 2%�� ������ �߰��� �����Ѵ�.
	���°��� �������� �ʱ� �ԱݵǴ� �ݾ׿� ���ؼ��� ���ڸ� ������� �ʴ´�.
	���°��� �� ������ �Աݰ����� ��ĥ ������ ���ڰ� �߻��ϴ� ������ �����Ѵ�.
	������ ���������� �߻��ϴ� �Ҽ��� ������ �ݾ��� �����Ѵ�.

*/
class HighCreditAccount : public NormalAccount {
private:
	double specialratio;	// �߰� ����
public:
	// �ſ�ŷڰ��� ������
	HighCreditAccount(int idx, int ID, int balance, char * Name, double ratio, double specialratio);
	// �ſ�ŷڰ��� �Ա�
	void Deposit(int money);
	~HighCreditAccount();

};

#endif // !_HIGHCREDITACCOUNT_H_
