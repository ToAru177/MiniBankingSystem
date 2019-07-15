
/*
	1. 시스템명 : BankingSystme
	2. 버전     : 6.0
	3. 담당자   : 김유민
	4. 내용
	   4.1 OOP(객체지향) 단계별 프로젝트의 기본 틀 구성
	   4.2 보통예금계좌, 신용예금계좌 추가
	   4.3 가상 함수 적용
	   4.3.5 클래스를 분할 하여 관리
	   4.4 문자열 처리하는 MyString class 추가
	   4.5 예외처리 & 파일 입출력 추가 - 파일 입력 구문 클래스로 구현
		4.5.1 파일 저장 형식
			  f_index(계좌 구분) id(계좌번호) balance(잔액) name(이름) specialratio(추가이율->신용계좌만 있음) ratio(이율)
	   4.6 배열클래스를 "클래스 템플릿"으로 변경하여 MiniBankingSystem에 적용.

*/


#include "MiniBankingCommonDecl.h"
#include <fstream>
#include "AccountHandler.h"
#include "FileInput.h"


#define NAME_LEN 20


// 메뉴용 열거자
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };


int main(void)
{
	AccountHandler handle;

	ifstream in("CusInfo_List.txt");
	if (in) {
		FileIO file;

		file.input(handle, in);
	}
	
	in.close();

	int choice;

	while (1)
	{
		system("cls");
		handle.ShowMenu();

		cout << "\t\t선택 >> ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			system("cls");
			handle.MakeAccount();
			break;
		case DEPOSIT:
			system("cls");
			handle.DepositMoney();
			break;
		case WITHDRAW:
			system("cls");
			handle.WithdrawMoney();
			break;
		case INQUIRE:
			system("cls");
			handle.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;

		default:
			cout << "\t\t없는 메뉴입니다. 다시 선택해주세요." << endl;
			getchar();
			getchar();
		}


	}
	return 0;
}
