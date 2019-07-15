#ifndef _ACCOUNTHANDLER_H_
#define	_ACCOUNTHANDLER_H_

#include "MiniBankingCommonDecl.h"
#include "Account.h"
#include "AccountArray.h"

typedef Account * ACCOUNT_PTR;

class AccountHandler {
private:
	//계좌를 관리할 배열
	//Account * accArr[NumOfUser];
	AccountArray<ACCOUNT_PTR> accArr;
	//개설된 계좌 수
	int accNum;

public:
	// 생성자
	AccountHandler();
	//AccountHandler(int CusNum);
	// 메뉴 출력
	void ShowMenu(void) const;
	// 계좌 개설
	void MakeAccount(void);
	// 보통예금계좌 개설
	void MakeNormalAccount(void);
	// 신용신뢰계좌 개설
	void MakeHighCreditAccount(void);
	// 계좌 입금
	void DepositMoney(void);
	// 계좌 출금
	void WithdrawMoney(void);
	// 잔액 조회
	void ShowAllAccInfo(void) const;
	// 소멸자
	~AccountHandler();


	// 파일 입력으로 생성된 보통계좌
	void FileMakeNormalAccount(int INDEX, int ID, int balance, const char *Name, double ratio);
	// 파일 입력으로 생성된 신용계좌
	void FileMakeHighCreditAccount(int INDEX, int ID, int balance, char * Name, double ratio, double specialratio);
};

#endif // !_ACCOUNTHANDLER_H_

