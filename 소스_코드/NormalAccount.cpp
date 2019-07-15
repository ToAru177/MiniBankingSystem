#include "MiniBankingCommonDecl.h"
#include "NormalAccount.h"


// ���뿹�ݰ��� ������
NormalAccount::NormalAccount(int idx, int ID, int balance, const char *Name, double ratio)
	: Account(idx, ID, balance, Name), ratio(ratio)
{	}

// ���뿹�ݰ��� �Ա�
void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
	Account::Deposit(money * (ratio / 100.0));
}

NormalAccount::~NormalAccount() {

	ofstream out("CusInfo_List.txt", ios::app);
	if (!out) { // ���� ����
		cout << "CusInfo_List.txt ������ �� �� ����.";
	}
	
	out << ratio;

	out.close();
}
