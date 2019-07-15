#include "MyString.h"

// 한 문자 생성자
MyString::MyString() {
	mystring_contents = NULL;
	mystring_length = 0;
}

// 문자열 생성자
MyString::MyString(const char *str) {
	mystring_length = strlen(str) + 1;
	mystring_contents = new char[mystring_length];
	strcpy(mystring_contents, str);
}

// 문자열 복사자
MyString::MyString(MyString &ref) {
	//delete[]this->mystring_contents;

	this->mystring_length = strlen(ref.mystring_contents) + 1;
	this->mystring_contents = new char[mystring_length];
	strcpy(this->mystring_contents, ref.mystring_contents);
}

// 문자열 길이 반환
int MyString::GetStringLength(void) const {
	return mystring_length;
}

// 문자열 반환
char * MyString::GetStringContents(void) const {
	return mystring_contents;
}

// 소멸자
MyString::~MyString() {
	delete[]mystring_contents;
}

//  "=" 연산자 오버로딩
MyString& MyString:: operator=(const MyString &ref) {

	if (mystring_contents != NULL)
		delete[]mystring_contents;

	mystring_length = ref.mystring_length;
	mystring_contents = new char[mystring_length];
	strcpy(mystring_contents, ref.mystring_contents);

	return *this;

}


// "==" 연산자 오버로딩
// strcmp() 기능
int MyString::operator==(MyString &ref) const {
	if (strcmp(this->mystring_contents, ref.mystring_contents))
		return 1;
	else
		return -1;
}

// "<<" 연산자 오버로딩
ostream& operator<<(ostream& out, const MyString &str) {

	out << str.mystring_contents;

	return out;
}

// ">>" 연산자 오버로딩
istream& operator>>(istream& in, MyString &str) {
	char *tmp = new char[STR_MAX];
	in >> tmp;

	delete []str.mystring_contents;

	str.mystring_length = strlen(tmp) + 1;
	str.mystring_contents = new char[str.mystring_length];
	strcpy(str.mystring_contents, tmp);

	delete[]tmp;

	return in;
}


