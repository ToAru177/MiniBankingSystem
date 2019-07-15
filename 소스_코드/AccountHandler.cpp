#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Account.h"
#include "MyString.h"
#include "Exception.h"
#include "AccountArray.cpp"


const int NAME_LEN = 20;

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };


AccountHandler::AccountHandler() : accNum(0) { }

//AccountHandler::AccountHandler(int CusNum) : accNum(CusNum) {	}

// 메뉴 출력
void AccountHandler::ShowMenu(void) const
{
	cout << "\t\t=========== Menu ===========" << endl;
	cout << "\t\t\t1. 계좌개설" << endl;
	cout << "\t\t\t2. 입    금" << endl;
	cout << "\t\t\t3. 출    금" << endl;
	cout << "\t\t\t4. 전체고객 잔액조회" << endl;
	cout << "\t\t\t5. 종    료" << endl;
	cout << "\t\t============================" << endl;
}

// 계좌 개설
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
	cout << "\t\t======== 계좌종류 선택 ========" << endl;
	cout << "\t\t1. 보통예금계좌" << endl;
	cout << "\t\t2. 신용신뢰계좌" << endl;
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

// 보통예금계좌 개설
void AccountHandler::MakeNormalAccount(void) {
	int id;					// 계좌 번호
	int balance;			// 잔액
	char name[NAME_LEN];	// 고객 명
	double ratio;			// 이율

	cout << "\t\t======= 보통예금계좌 개설 =======" << endl;

	cout << "\t\t이름 : ";	cin >> name;
	cout << "\t\t계좌 번호 : ";	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id) {
			cout << "\t\t사용 중인 계좌번호 입니다." << endl;
			cout << "\t\t===============================" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout << "\t\t잔액 : ";	cin >> balance;
	cout << "\t\t이율 : ";	cin >> ratio;

	accArr[accNum] = new NormalAccount(NORMAL, id, balance, name, ratio);

	accNum++;

	cout << "\t\t계좌개설 완료" << endl;
	cout << "\t\t===============================" << endl;

	getchar();
	getchar();
}

// 신용신뢰계좌 개설
void AccountHandler::MakeHighCreditAccount(void) {
	int id;					// 계좌 번호
	int balance;			// 잔액
	char name[NAME_LEN];	// 고객 명
	double ratio;				// 이율
	double specialratio;		// 추가 이율
	char grade;				// 신용등급 구분 문자

	cout << "\t\t======= 신용신뢰계좌 개설 =======" << endl;

	cout << "\t\t이름 : ";	cin >> name;
	cout << "\t\t계좌 번호 : ";	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id) {
			cout << "\t\t사용 중인 계좌번호 입니다." << endl;
			cout << "\t\t===============================" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout << "\t\t잔액 : ";	cin >> balance;
	cout << "\t\t이율 : ";	cin >> ratio;
	cout << "\t\t신용 등급 (A, B, C) : ";	cin >> grade;

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
		cout << "\t\tA, B, C 이외의 문자는 입력 할 수 없습니다." << endl;
		cout << "\t\t===============================" << endl;
		getchar();
		getchar();
		return;
	}
	
	accArr[accNum] = new HighCreditAccount(CREDIT, id, balance, name, ratio, specialratio);

	accNum++;

	cout << "\t\t계좌개설 완료" << endl;
	cout << "\t\t===============================" << endl;

	getchar();
	getchar();
}


// 입금
void AccountHandler::DepositMoney(void) {
	int	money;	// 입금액
	int id;		// 계좌 번호

	cout << "\t\t========== 입 금 ==========" << endl;
	cout << "\t\t계좌 번호 : "; cin >> id;
	cout << "\t\t입금 액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			try {
				accArr[i]->Deposit(money);
				cout << "\t\t입금 완료 되었습니다." << endl;
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

	cout << "\t\t잘못된 계좌번호입니다." << endl;
	cout << "\t\t===========================" << endl;
	getchar();
	getchar();
}

// 출금
void AccountHandler::WithdrawMoney(void) {
	int money;
	int id;

	cout << "\t\t========== 출 금 ==========" << endl;
	cout << "\t\t계좌번호 : "; cin >> id;
	cout << "\t\t출금 액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{

		if (accArr[i]->GetID() == id)
		{
			try {
				accArr[i]->Withdraw(money);
				cout << "\t\t출금이 완료 되었습니다." << endl;
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

	cout << "\t\t잘못된 계좌번호 입니다." << endl;
	cout << "\t\t===========================" << endl;
	getchar();
	getchar();
}

// 전체고객 잔액 조회
void AccountHandler::ShowAllAccInfo(void) const {

	cout << "\t\t========== 잔액 조회 ==========" << endl;

	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccountInfo();
		cout << endl;
	}
	cout << "\t\t===============================" << endl;
	getchar();
	getchar();
}

// 소멸자
AccountHandler::~AccountHandler() {

	

	for (int i = 0; i < accNum; i++)
	{
		if (i == 0) {
			ofstream out("CusInfo_List.txt");
			if (!out) { // 열기 실패
				cout << "CusInfo_List.txt 파일을 열 수 없다.";
			}
			out << accArr[i]->GetIndex() << ' ' << accArr[i]->GetID() << ' ' << accArr[i]->GetName() << ' ' << accArr[i]->GetBalance() << ' ';
			out.close();
		}

		else {
			ofstream out("CusInfo_List.txt", ios::app);
			if (!out) { // 열기 실패
				cout << "CusInfo_List.txt 파일을 열 수 없다.";
			}
			out << endl << accArr[i]->GetIndex() << ' ' << accArr[i]->GetID() << ' ' << accArr[i]->GetName() << ' ' << accArr[i]->GetBalance() << ' ';
			out.close();
		}

		delete accArr[i];

	}

}

// 파일 입력으로 생성된 보통계좌
void AccountHandler::FileMakeNormalAccount(int INDEX, int ID, int balance, const char *Name, double ratio) {

	accArr[accNum] = new NormalAccount(INDEX, ID, balance, Name, ratio);

	accNum++;
}

// 파일 입력으로 생성된 신용계좌
void AccountHandler::FileMakeHighCreditAccount(int INDEX, int ID, int balance, char * Name, double ratio, double specialratio) {

	accArr[accNum] = new HighCreditAccount(INDEX, ID, balance, Name, ratio, specialratio);

	accNum++;
}