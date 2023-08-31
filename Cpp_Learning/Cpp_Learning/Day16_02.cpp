#include <iostream>

using namespace std;

#if 0
int main()
{
	int a = 3;

	int* b;
	b = &a;

	//참조형 참조자 reference type
	//선언과 동시에 정의
	//원본X
	//독립성X
	int& c = a;

	cout << a << endl;
	cout << c << endl;

	a = 7;

	cout << a << endl;
	cout << c << endl;

	cout << &a << endl;
	cout << &c << endl;

	c = 10;

	cout << a << endl;
	cout << c << endl;

	int d = 15;
	c = d;

	cout << a << endl;
	cout << c << endl;

	*b = 20;
	cout << a << endl;
	cout << c << endl;

	return 0;
}
#endif

//x = a;
void Add5(int x)
{
	x += 5;

	//cout << x << endl;
}

void Add6(int& x)
{
	x += 6;
}

void Add7(int* x)
{
	*x += 7;
}

//함수 호출 방식
int main()
{
	int a = 10;

	//call by value 값에 의한 호출
	//값을 복사해서 넘김
	Add5(a);
	cout << a << endl;

	//call by reference 참조에 의한 호출
	//주소를 공유, 원본값을 수정
	Add6(a);
	cout << a << endl;

	//call by pointer(aaddrreess) 주소에 의한 호출
	Add7(&a);
	cout << a << endl;

	return 0;
}