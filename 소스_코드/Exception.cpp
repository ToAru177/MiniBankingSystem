#include "Exception.h"
#include "MiniBankingCommonDecl.h"

void AccountExeption::ShowExceptionReason() {}

DepositException::DepositException(int money) : DepositMoney(money)
{	}

void DepositException::ShowExceptionReason() const {
	cout << "\t\t예외 메세지 : " << DepositMoney << "는 입금불가!!" << endl;
}

WithdrawException::WithdrawException(int money)
{
	balance = money;
}

void WithdrawException::ShowExceptionReason() const {
	cout << "\t\t예외 메세지 : 잔액 " << balance << ", 잔액 부족!!" << endl;
}

MakeAccountException::MakeAccountException(int accNum) {
	num = accNum;
}

void MakeAccountException::ShowExceptionReason() const {
	cout << endl << endl;
	cout << "\t\t===============================================" << endl;
	cout << "\t\t최대 인원 수를 넘어 계좌개설이 불가능 합니다." << endl;
	cout << "\t\t===============================================" << endl;
}