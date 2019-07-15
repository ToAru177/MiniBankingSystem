#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include "MiniBankingCommonDecl.h"

#define STR_MAX 1000

class MyString {
private:
	char *mystring_contents;	// ���ڿ� ����
	int mystring_length;		// ���ڿ� ���� ���� ����

public:
	// �� ���� ������
	MyString();
	// ���ڿ� ������
	MyString(const char *str);
	// ���ڿ� ������
	MyString(MyString &ref);
	// ���ڿ� ���� ��ȯ
	int GetStringLength(void) const;
	// ���ڿ� ��ȯ
	char * GetStringContents(void) const;
	// �Ҹ���
	~MyString();
	
	// "=" ������ �����ε�
	MyString& operator=(const MyString &ref);

	// "==" ������ �����ε�
	// strcmp() ���
	int operator==(MyString &ref) const;

	// "<<" ������ �����ε�
	friend ostream& operator<<(ostream& out, const MyString &str);
	// ">>" ������ �����ε�
	friend istream& operator>>(istream& in, MyString &str);

	//friend class Account;

};



#endif // !_MYSTRING_H_

