#include "MiniBankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "MyString.h"

// 신용신뢰계좌 생성자
HighCreditAccount::HighCreditAccount(int idx, int ID, int balance, char * Name, double ratio, double specialratio)
	: NormalAccount(idx, ID, balance, Name, ratio), specialratio(specialratio)
{}

// 신용신뢰계좌 입금
void HighCreditAccount::Deposit(int money) {
	NormalAccount::Deposit(money);
	Account::Deposit(money * (specialratio / 100.0));
}

HighCreditAccount::~HighCreditAccount() {
	ofstream out("CusInfo_List.txt", ios::app);
	if (!out) { // 열기 실패
		cout << "CusInfo_List.txt 파일을 열 수 없다.";
	}
	
	out << specialratio << ' ';

	out.close();
}

