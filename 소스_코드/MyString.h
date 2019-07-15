#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include "MiniBankingCommonDecl.h"

#define STR_MAX 1000

class MyString {
private:
	char *mystring_contents;	// 문자열 저장
	int mystring_length;		// 문자열 길이 저장 변수

public:
	// 한 문자 생성자
	MyString();
	// 문자열 생성자
	MyString(const char *str);
	// 문자열 복사자
	MyString(MyString &ref);
	// 문자열 길이 반환
	int GetStringLength(void) const;
	// 문자열 반환
	char * GetStringContents(void) const;
	// 소멸자
	~MyString();
	
	// "=" 연산자 오버로딩
	MyString& operator=(const MyString &ref);

	// "==" 연산자 오버로딩
	// strcmp() 기능
	int operator==(MyString &ref) const;

	// "<<" 연산자 오버로딩
	friend ostream& operator<<(ostream& out, const MyString &str);
	// ">>" 연산자 오버로딩
	friend istream& operator>>(istream& in, MyString &str);

	//friend class Account;

};



#endif // !_MYSTRING_H_

