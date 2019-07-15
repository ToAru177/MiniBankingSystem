#ifndef _ACCOUNTARRAY_H_
#define	_ACCOUNTARRAY_H_

#include "Account.h"

#define NumOfUser	100


template <typename T>
class AccountArray {
private:
	T* accArr;	// ���� ���� ����Ʈ(������ �迭)
	int arrlen;				// �迭�� ��� ��
	

	AccountArray(const AccountArray &arr) {}
	AccountArray& operator=(const AccountArray &arr){}

public:
	// ������
	AccountArray(int len = NumOfUser);
	
	// [] ������ �����ε�
	T& operator[](int idx);

	// [] ������ �����ε�
	T operator[](int idx) const;

	// �迭 ���� ��ȯ
	int GetArrLen() const;

	// �Ҹ���
	~AccountArray();

};


#endif // !1

