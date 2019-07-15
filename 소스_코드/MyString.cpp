#include "MyString.h"

// �� ���� ������
MyString::MyString() {
	mystring_contents = NULL;
	mystring_length = 0;
}

// ���ڿ� ������
MyString::MyString(const char *str) {
	mystring_length = strlen(str) + 1;
	mystring_contents = new char[mystring_length];
	strcpy(mystring_contents, str);
}

// ���ڿ� ������
MyString::MyString(MyString &ref) {
	//delete[]this->mystring_contents;

	this->mystring_length = strlen(ref.mystring_contents) + 1;
	this->mystring_contents = new char[mystring_length];
	strcpy(this->mystring_contents, ref.mystring_contents);
}

// ���ڿ� ���� ��ȯ
int MyString::GetStringLength(void) const {
	return mystring_length;
}

// ���ڿ� ��ȯ
char * MyString::GetStringContents(void) const {
	return mystring_contents;
}

// �Ҹ���
MyString::~MyString() {
	delete[]mystring_contents;
}

//  "=" ������ �����ε�
MyString& MyString:: operator=(const MyString &ref) {

	if (mystring_contents != NULL)
		delete[]mystring_contents;

	mystring_length = ref.mystring_length;
	mystring_contents = new char[mystring_length];
	strcpy(mystring_contents, ref.mystring_contents);

	return *this;

}


// "==" ������ �����ε�
// strcmp() ���
int MyString::operator==(MyString &ref) const {
	if (strcmp(this->mystring_contents, ref.mystring_contents))
		return 1;
	else
		return -1;
}

// "<<" ������ �����ε�
ostream& operator<<(ostream& out, const MyString &str) {

	out << str.mystring_contents;

	return out;
}

// ">>" ������ �����ε�
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


