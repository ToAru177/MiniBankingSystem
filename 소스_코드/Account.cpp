#include "MiniBankingCommonDecl.h"
#include "Account.h"
#include "Exception.h"

// 생성자
Account::Account(int idx, int ID, int balance, const char *Name) {
	index = idx;
	accID = ID;
	this->balance = balance;

	MyString tmp = Name;
	cusName = tmp;
}

// 복사 생성자
Account::Account(const Account &copy) {
	accID = copy.accID;
	balance = copy.balance;
	cusName = copy.cusName;
}
// 계좌 번호를 가져오는 함수
int Account::GetID(void) const {
	return accID;
}
// 통장 잔액을 가져오는 함수
int Account::GetBalance(void) const {
	return balance;
}
// 사용자 이름을 가져오는 함수
char * Account::GetName(void) const {
	return this->cusName.GetStringContents();
}
// 입금 기능 
void Account::Deposit(int money) {
	if (money < 0) {
		DepositException expn(money);
		throw expn;
	}

	balance += money;
}
// 출금 기능
void  Account::Withdraw(int money) {

	if (balance < money) {
		// throw 발생 => exception class
		WithdrawException expn(money);
		throw expn;
	}

	balance -= money;
}

// 계좌 정보 출력
void Account::ShowAccountInfo() const {
	cout << "\t\t이름 : " << cusName << endl;
	cout << "\t\t계좌 번호 : " << accID << endl;
	cout << "\t\t잔액 : " << balance << endl;
}
// 소멸자
Account::~Account() {
	//delete cusName.;
}



int Account::GetIndex() const {
	return index;
}
