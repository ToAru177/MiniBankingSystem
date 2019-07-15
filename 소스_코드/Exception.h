#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

class AccountExeption {
public:
	// ������ �����Լ�
	virtual void ShowExceptionReason();
};

// �Ա� ���� class
class DepositException : public AccountExeption {
private:
	int DepositMoney;
public:
	DepositException(int money);
	void ShowExceptionReason() const;
};

// ��� ���� class
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
