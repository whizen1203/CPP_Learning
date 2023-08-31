#include <iostream>
#define MAX 20

using namespace std;

void Swap()
{
	int temp;
}

void Call()
{
	//재귀함수 -> 종료조건!!
	Call();
}

int main()
{
	//메모리 구조
	//메모리 : 프로그램이 기억해야하는 걸 저장

	//코드 : read only
	//컴파일 타임에 필요한 메모리를 저장하는 공간
	//코드 함수 리터럴 매크로 
	//MAX = 10;
	cout << MAX << endl;

	//스택 : 함수가 호출될 때 사용되는 메모리
	//매개변수input 반환값output 지역변수 
	//스택프레임 LIFO last in first out
	//Call(); stack overflow
	//스택 예약크기 (1MB)
	//크기가 작다, 크기를 가늠할 수 있어야 함
	//정적 할당

	//int arr[10000000000000000000000000000000000000000000000];
	int size;
	cin >> size;
	//int arr[size];
	int arr[10];


	//할당 : 나눠주는 것
	//정적 할당 : 컴파일 타임
	//동적 할당 : 런타임
	//정적 <-> 동적


	//힙
	//동적 할당
	//크기가 비교적 크다 -> 스택이 안쓰는 나머지 공간
	//메모리 주소값으로 접근해야 함


	//포인터 : 메모리 주소를 저장하고 가리키는 도구
	//주소값에 접근하기 위한 도구
	//메모리에 접근할 주소를 저장하는 타입(자료형)

	return 0;
}