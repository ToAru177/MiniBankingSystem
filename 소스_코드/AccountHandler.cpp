#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Account.h"
#include "MyString.h"
#include "Exception.h"
#include "AccountArray.cpp"


const int NAME_LEN = 20;

// �ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// ������ ����
enum { NORMAL = 1, CREDIT = 2 };


AccountHandler::AccountHandler() : accNum(0) { }

//AccountHandler::AccountHandler(int CusNum) : accNum(CusNum) {	}

// �޴� ���
void AccountHandler::ShowMenu(void) const
{
	cout << "\t\t=========== Menu ===========" << endl;
	cout << "\t\t\t1. ���°���" << endl;
	cout << "\t\t\t2. ��    ��" << endl;
	cout << "\t\t\t3. ��    ��" << endl;
	cout << "\t\t\t4. ��ü�� �ܾ���ȸ" << endl;
	cout << "\t\t\t5. ��    ��" << endl;
	cout << "\t\t============================" << endl;
}

// ���� ����
void AccountHandler::MakeAccount(void)
{
	try {
		if (accNum == NumOfUser){
			MakeAccountException expn(accNum);
			throw expn;
		}
	}

	catch (MakeAccountException &expn) {
		expn.ShowExceptionReason();
		getchar();
		getchar();
		return;
	}

	

	int sel;
	cout << "\t\t======== �������� ���� ========" << endl;
	cout << "\t\t1. ���뿹�ݰ���" << endl;
	cout << "\t\t2. �ſ�ŷڰ���" << endl;
	cout << "\t\t===============================" << endl;
	cout << "\t\t>> "; cin >> sel;


	if (sel == NORMAL) {
		system("cls");
		AccountHandler::MakeNormalAccount();
	}

	else if (sel == CREDIT) {
		system("cls");
		AccountHandler::MakeHighCreditAccount();
	}

}

// ���뿹�ݰ��� ����
void AccountHandler::MakeNormalAccount(void) {
	int id;					// ���� ��ȣ
	int balance;			// �ܾ�
	char name[NAME_LEN];	// �� ��
	double ratio;			// ����

	cout << "\t\t======= ���뿹�ݰ��� ���� =======" << endl;

	cout << "\t\t�̸� : ";	cin >> name;
	cout << "\t\t���� ��ȣ : ";	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id) {
			cout << "\t\t��� ���� ���¹�ȣ �Դϴ�." << endl;
			cout << "\t\t===============================" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout << "\t\t�ܾ� : ";	cin >> balance;
	cout << "\t\t���� : ";	cin >> ratio;

	accArr[accNum] = new NormalAccount(NORMAL, id, balance, name, ratio);

	accNum++;

	cout << "\t\t���°��� �Ϸ�" << endl;
	cout << "\t\t===============================" << endl;

	getchar();
	getchar();
}

// �ſ�ŷڰ��� ����
void AccountHandler::MakeHighCreditAccount(void) {
	int id;					// ���� ��ȣ
	int balance;			// �ܾ�
	char name[NAME_LEN];	// �� ��
	double ratio;				// ����
	double specialratio;		// �߰� ����
	char grade;				// �ſ��� ���� ����

	cout << "\t\t======= �ſ�ŷڰ��� ���� =======" << endl;

	cout << "\t\t�̸� : ";	cin >> name;
	cout << "\t\t���� ��ȣ : ";	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id) {
			cout << "\t\t��� ���� ���¹�ȣ �Դϴ�." << endl;
			cout << "\t\t===============================" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout << "\t\t�ܾ� : ";	cin >> balance;
	cout << "\t\t���� : ";	cin >> ratio;
	cout << "\t\t�ſ� ��� (A, B, C) : ";	cin >> grade;

	switch (grade) {
	case 'A':
	case 'a':
		specialratio = LEVEL_A;
		break;

	case 'B':
	case 'b':
		specialratio = LEVEL_B;
		break;

	case 'C':
	case 'c':
		specialratio = LEVEL_C;
		break;
		
	default:
		cout << "\t\tA, B, C �̿��� ���ڴ� �Է� �� �� �����ϴ�." << endl;
		cout << "\t\t===============================" << endl;
		getchar();
		getchar();
		return;
	}
	
	accArr[accNum] = new HighCreditAccount(CREDIT, id, balance, name, ratio, specialratio);

	accNum++;

	cout << "\t\t���°��� �Ϸ�" << endl;
	cout << "\t\t===============================" << endl;

	getchar();
	getchar();
}


// �Ա�
void AccountHandler::DepositMoney(void) {
	int	money;	// �Աݾ�
	int id;		// ���� ��ȣ

	cout << "\t\t========== �� �� ==========" << endl;
	cout << "\t\t���� ��ȣ : "; cin >> id;
	cout << "\t\t�Ա� �� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			try {
				accArr[i]->Deposit(money);
				cout << "\t\t�Ա� �Ϸ� �Ǿ����ϴ�." << endl;
				cout << "\t\t===========================" << endl;
			}

			catch (DepositException &expn) {
				expn.ShowExceptionReason();
				cout << "\t\t===========================" << endl;
			}

			getchar();
			getchar();
			return;
		}

	}

	cout << "\t\t�߸��� ���¹�ȣ�Դϴ�." << endl;
	cout << "\t\t===========================" << endl;
	getchar();
	getchar();
}

// ���
void AccountHandler::WithdrawMoney(void) {
	int money;
	int id;

	cout << "\t\t========== �� �� ==========" << endl;
	cout << "\t\t���¹�ȣ : "; cin >> id;
	cout << "\t\t��� �� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{

		if (accArr[i]->GetID() == id)
		{
			try {
				accArr[i]->Withdraw(money);
				cout << "\t\t����� �Ϸ� �Ǿ����ϴ�." << endl;
				cout << "\t\t===========================" << endl;
			}

			catch (WithdrawException &expn) {
				expn.ShowExceptionReason();
				cout << "\t\t===========================" << endl;
			}

			getchar();
			getchar();
			return;
		}
	}

	cout << "\t\t�߸��� ���¹�ȣ �Դϴ�." << endl;
	cout << "\t\t===========================" << endl;
	getchar();
	getchar();
}

// ��ü�� �ܾ� ��ȸ
void AccountHandler::ShowAllAccInfo(void) const {

	cout << "\t\t========== �ܾ� ��ȸ ==========" << endl;

	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccountInfo();
		cout << endl;
	}
	cout << "\t\t===============================" << endl;
	getchar();
	getchar();
}

// �Ҹ���
AccountHandler::~AccountHandler() {

	

	for (int i = 0; i < accNum; i++)
	{
		if (i == 0) {
			ofstream out("CusInfo_List.txt");
			if (!out) { // ���� ����
				cout << "CusInfo_List.txt ������ �� �� ����.";
			}
			out << accArr[i]->GetIndex() << ' ' << accArr[i]->GetID() << ' ' << accArr[i]->GetName() << ' ' << accArr[i]->GetBalance() << ' ';
			out.close();
		}

		else {
			ofstream out("CusInfo_List.txt", ios::app);
			if (!out) { // ���� ����
				cout << "CusInfo_List.txt ������ �� �� ����.";
			}
			out << endl << accArr[i]->GetIndex() << ' ' << accArr[i]->GetID() << ' ' << accArr[i]->GetName() << ' ' << accArr[i]->GetBalance() << ' ';
			out.close();
		}

		delete accArr[i];

	}

}

// ���� �Է����� ������ �������
void AccountHandler::FileMakeNormalAccount(int INDEX, int ID, int balance, const char *Name, double ratio) {

	accArr[accNum] = new NormalAccount(INDEX, ID, balance, Name, ratio);

	accNum++;
}

// ���� �Է����� ������ �ſ����
void AccountHandler::FileMakeHighCreditAccount(int INDEX, int ID, int balance, char * Name, double ratio, double specialratio) {

	accArr[accNum] = new HighCreditAccount(INDEX, ID, balance, Name, ratio, specialratio);

	accNum++;
}