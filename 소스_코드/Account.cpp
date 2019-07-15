#include "MiniBankingCommonDecl.h"
#include "Account.h"
#include "Exception.h"

// ������
Account::Account(int idx, int ID, int balance, const char *Name) {
	index = idx;
	accID = ID;
	this->balance = balance;

	MyString tmp = Name;
	cusName = tmp;
}

// ���� ������
Account::Account(const Account &copy) {
	accID = copy.accID;
	balance = copy.balance;
	cusName = copy.cusName;
}
// ���� ��ȣ�� �������� �Լ�
int Account::GetID(void) const {
	return accID;
}
// ���� �ܾ��� �������� �Լ�
int Account::GetBalance(void) const {
	return balance;
}
// ����� �̸��� �������� �Լ�
char * Account::GetName(void) const {
	return this->cusName.GetStringContents();
}
// �Ա� ��� 
void Account::Deposit(int money) {
	if (money < 0) {
		DepositException expn(money);
		throw expn;
	}

	balance += money;
}
// ��� ���
void  Account::Withdraw(int money) {

	if (balance < money) {
		// throw �߻� => exception class
		WithdrawException expn(money);
		throw expn;
	}

	balance -= money;
}

// ���� ���� ���
void Account::ShowAccountInfo() const {
	cout << "\t\t�̸� : " << cusName << endl;
	cout << "\t\t���� ��ȣ : " << accID << endl;
	cout << "\t\t�ܾ� : " << balance << endl;
}
// �Ҹ���
Account::~Account() {
	//delete cusName.;
}



int Account::GetIndex() const {
	return index;
}
