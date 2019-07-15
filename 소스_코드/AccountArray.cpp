#include "AccountArray.h"
#include "Account.h"
#include "Exception.h"

template <typename T>
AccountArray<T>::AccountArray(int len) {
	accArr = new T[len];
	arrlen = len;
}

template <typename T>
T& AccountArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}

	return accArr[idx];
}

template <typename T>
T AccountArray<T>::operator[](int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}

	return accArr[idx];
}

template <typename T>
int AccountArray<T>::GetArrLen() const {
	return arrlen;
}

template <typename T>
AccountArray<T>::~AccountArray() {
	delete[]accArr;
}
