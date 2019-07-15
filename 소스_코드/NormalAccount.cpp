#include "MiniBankingCommonDecl.h"
#include "NormalAccount.h"


// 보통예금계좌 생성자
NormalAccount::NormalAccount(int idx, int ID, int balance, const char *Name, double ratio)
	: Account(idx, ID, balance, Name), ratio(ratio)
{	}

// 보통예금계좌 입금
void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
	Account::Deposit(money * (ratio / 100.0));
}

NormalAccount::~NormalAccount() {

	ofstream out("CusInfo_List.txt", ios::app);
	if (!out) { // 열기 실패
		cout << "CusInfo_List.txt 파일을 열 수 없다.";
	}
	
	out << ratio;

	out.close();
}
