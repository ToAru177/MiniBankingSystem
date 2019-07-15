#include "MiniBankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "MyString.h"

// �ſ�ŷڰ��� ������
HighCreditAccount::HighCreditAccount(int idx, int ID, int balance, char * Name, double ratio, double specialratio)
	: NormalAccount(idx, ID, balance, Name, ratio), specialratio(specialratio)
{}

// �ſ�ŷڰ��� �Ա�
void HighCreditAccount::Deposit(int money) {
	NormalAccount::Deposit(money);
	Account::Deposit(money * (specialratio / 100.0));
}

HighCreditAccount::~HighCreditAccount() {
	ofstream out("CusInfo_List.txt", ios::app);
	if (!out) { // ���� ����
		cout << "CusInfo_List.txt ������ �� �� ����.";
	}
	
	out << specialratio << ' ';

	out.close();
}

