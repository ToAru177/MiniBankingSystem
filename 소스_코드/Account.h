#ifndef _ACCOUNT_H_
#define	_ACCOUNT_H_

#include "MyString.h"

class Account
{
private:
	int accID;	//계좌번호
	int balance; //잔액
	//char *cusName;
	MyString cusName;

	// 계좌 구분 변수
	// 1 : 보통 계좌
	// 2 : 신용 계좌
	int index;	

public:

	// 생성자
	Account(int idx, int ID, int balance, const char *Name);
	// 복사 생성자
	Account(const Account &copy);
	// 계좌 번호를 가져오는 함수
	int GetID(void) const;
	// 통장 잔액을 가져오는 함수
	int GetBalance(void) const;
	// 사용자 이름을 가져오는 함수
	char * GetName(void) const;
	// 입금 기능 
	virtual void Deposit(int money);
	// 출금 기능
	void  Withdraw(int money);
	// 계좌 정보 출력
	void ShowAccountInfo() const;
	// 소멸자
	virtual ~Account();
	//friend class MyString;
	
	// index 반환
	int GetIndex() const;
	
};

#endif // !_ACCOUNT_H_
