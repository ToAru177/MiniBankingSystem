#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

class AccountExeption {
public:
	// 완전한 가상함수
	virtual void ShowExceptionReason();
};

// 입금 예외 class
class DepositException : public AccountExeption {
private:
	int DepositMoney;
public:
	DepositException(int money);
	void ShowExceptionReason() const;
};

// 출금 예외 class
class WithdrawException : public AccountExeption {
private:
	int balance;
public:
	WithdrawException(int money);
	void ShowExceptionReason() const;
};

class MakeAccountException : public AccountExeption {
	int num;
public:
	MakeAccountException(int accNum);
	void ShowExceptionReason() const;
};

#endif // !_EXCEPTION_H_
