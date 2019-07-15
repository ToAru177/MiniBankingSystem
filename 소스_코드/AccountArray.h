#ifndef _ACCOUNTARRAY_H_
#define	_ACCOUNTARRAY_H_

#include "Account.h"

#define NumOfUser	100


template <typename T>
class AccountArray {
private:
	T* accArr;	// 개설 계좌 리스트(포인터 배열)
	int arrlen;				// 배열의 요소 수
	

	AccountArray(const AccountArray &arr) {}
	AccountArray& operator=(const AccountArray &arr){}

public:
	// 생성자
	AccountArray(int len = NumOfUser);
	
	// [] 연산자 오버로드
	T& operator[](int idx);

	// [] 연산자 오버로드
	T operator[](int idx) const;

	// 배열 길이 반환
	int GetArrLen() const;

	// 소멸자
	~AccountArray();

};


#endif // !1

