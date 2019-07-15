#include "Exception.h"
#include "MiniBankingCommonDecl.h"

void AccountExeption::ShowExceptionReason() {}

DepositException::DepositException(int money) : DepositMoney(money)
{	}

void DepositException::ShowExceptionReason() const {
	cout << "\t\t���� �޼��� : " << DepositMoney << "�� �ԱݺҰ�!!" << endl;
}

WithdrawException::WithdrawException(int money)
{
	balance = money;
}

void WithdrawException::ShowExceptionReason() const {
	cout << "\t\t���� �޼��� : �ܾ� " << balance << ", �ܾ� ����!!" << endl;
}

MakeAccountException::MakeAccountException(int accNum) {
	num = accNum;
}

void MakeAccountException::ShowExceptionReason() const {
	cout << endl << endl;
	cout << "\t\t===============================================" << endl;
	cout << "\t\t�ִ� �ο� ���� �Ѿ� ���°����� �Ұ��� �մϴ�." << endl;
	cout << "\t\t===============================================" << endl;
}