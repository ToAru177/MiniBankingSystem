#ifndef	_HIGHCREDITACCOUNT_H_
#define _HIGHCREDITACCOUNT_H_

#include "NormalAccount.h"
#include "MyString.h"

// 신용신뢰계좌 Entity 클래스
/*
	고객의 신용등급을 A, B, C로 나누고 계좌개설시 이 정보를 등록한다.
	A, B, C 등급별로 각각 기본이율에 7%, 4%, 2%의 이율을 추가로 제공한다.
	계좌개설 과정에서 초기 입금되는 금액에 대해서는 이자를 계산하지 않는다.
	계좌개설 후 별도의 입금과정을 거칠 때에만 이자가 발생하는 것으로 간주한다.
	이자의 계산과정에서 발생하는 소수점 이하의 금액은 무시한다.

*/
class HighCreditAccount : public NormalAccount {
private:
	double specialratio;	// 추가 이율
public:
	// 신용신뢰계좌 생성자
	HighCreditAccount(int idx, int ID, int balance, char * Name, double ratio, double specialratio);
	// 신용신뢰계좌 입금
	void Deposit(int money);
	~HighCreditAccount();

};

#endif // !_HIGHCREDITACCOUNT_H_
