#ifndef _ACCOUNTHANDLER_H_
#define	_ACCOUNTHANDLER_H_

#include "MiniBankingCommonDecl.h"
#include "Account.h"
#include "AccountArray.h"

typedef Account * ACCOUNT_PTR;

class AccountHandler {
private:
	//���¸� ������ �迭
	//Account * accArr[NumOfUser];
	AccountArray<ACCOUNT_PTR> accArr;
	//������ ���� ��
	int accNum;

public:
	// ������
	AccountHandler();
	//AccountHandler(int CusNum);
	// �޴� ���
	void ShowMenu(void) const;
	// ���� ����
	void MakeAccount(void);
	// ���뿹�ݰ��� ����
	void MakeNormalAccount(void);
	// �ſ�ŷڰ��� ����
	void MakeHighCreditAccount(void);
	// ���� �Ա�
	void DepositMoney(void);
	// ���� ���
	void WithdrawMoney(void);
	// �ܾ� ��ȸ
	void ShowAllAccInfo(void) const;
	// �Ҹ���
	~AccountHandler();


	// ���� �Է����� ������ �������
	void FileMakeNormalAccount(int INDEX, int ID, int balance, const char *Name, double ratio);
	// ���� �Է����� ������ �ſ����
	void FileMakeHighCreditAccount(int INDEX, int ID, int balance, char * Name, double ratio, double specialratio);
};

#endif // !_ACCOUNTHANDLER_H_

