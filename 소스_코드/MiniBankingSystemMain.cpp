
/*
	1. �ý��۸� : BankingSystme
	2. ����     : 6.0
	3. �����   : ������
	4. ����
	   4.1 OOP(��ü����) �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
	   4.2 ���뿹�ݰ���, �ſ뿹�ݰ��� �߰�
	   4.3 ���� �Լ� ����
	   4.3.5 Ŭ������ ���� �Ͽ� ����
	   4.4 ���ڿ� ó���ϴ� MyString class �߰�
	   4.5 ����ó�� & ���� ����� �߰� - ���� �Է� ���� Ŭ������ ����
		4.5.1 ���� ���� ����
			  f_index(���� ����) id(���¹�ȣ) balance(�ܾ�) name(�̸�) specialratio(�߰�����->�ſ���¸� ����) ratio(����)
	   4.6 �迭Ŭ������ "Ŭ���� ���ø�"���� �����Ͽ� MiniBankingSystem�� ����.

*/


#include "MiniBankingCommonDecl.h"
#include <fstream>
#include "AccountHandler.h"
#include "FileInput.h"


#define NAME_LEN 20


// �޴��� ������
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

		cout << "\t\t���� >> ";
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
			cout << "\t\t���� �޴��Դϴ�. �ٽ� �������ּ���." << endl;
			getchar();
			getchar();
		}


	}
	return 0;
}
