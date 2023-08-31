#include <iostream>

using namespace std;

int main()
{
	//포인터 : 메모리 주소를 저장하고 가리키는 도구
	//주소값에 접근하기 위한 도구
	//메모리에 접근할 주소를 저장하는 타입(자료형)
	//4byte(32bit) 8byte(64bit)

	/*float c = 5;
	float* d;
	d = &c;*/
	int* a; //int 형의 주소를 담는 포인터
	int b = 5;
	a = &b;
	//*var : 해당 메모리 주소가 가리키는 값
	//&var : 해당 변수의 주소

	cout << "b의 값 : " << b << endl;
	cout << "b의 주소 값 : " << &b << endl;
	cout << "a의 주소 값 : " << &a << endl;
	cout << "a의 값 : " << a << endl;
	cout << "a의 주소가 가리키는 값 : " << *a << endl;

	cout << "================================" << endl;

	int** c; //int* 형의 주소를 담는 포인터, 더블포인터
	c = &a;

	cout << "c의 값 : " << c << endl;
	cout << "c의 주소 값 : " << &c << endl;
	cout << "c의 주소가 가리키는 값 : " << *c << endl;
	cout << "c의 주소가 가리키는 값의 가리키는 값 : " << **c << endl;

	cout << "================================" << endl;

	int*** d; //int** 형의 주소를 담는 포인터, 삼중포인터
	d = &c;

	int*********************************************************************** e;

	int arr[2];
	arr[0] = 10;
	//*(arr + 0)
	arr[1] = 15;
	//*(arr + 1)
	//arr 배열의 이름은 시작주소

	const char* str1 = "*****"; //const 상수 심볼릭 상수
	const char* str2 = "*****";

	cout << (int*)str1 << endl;
	cout << (int*)str2 << endl;

	cout << str1 << endl;
	cout << str2 << endl;

	cout << str1 + 1 << endl;
	cout << str2 + 1 << endl;


	const char* str1 = "*****";
	const char* str3 = "     ";

	return 0;
}