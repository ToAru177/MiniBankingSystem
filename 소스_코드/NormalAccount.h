#pragma once

#include "Account.h"
#include "MyString.h"

// 보통예금계좌 Entity 클래스
/*
	보통예금계좌 클래스는 이율정보를 등록할 수 있도록 한다.
*/
class NormalAccount : public Account {
private:
	double ratio;	// 이율
public:
	// 보통예금계좌 생성자
	NormalAccount(int idx, int ID, int balance, const char *Name, double ratio);
	// 보통예금계좌 입금
	void Deposit(int money);
	~NormalAccount();
};
