#include <iostream>

using namespace std;

int main()
{
	//동적할당
	//힙에 저장
	//크기 상관X
	//malloc realloc calloc 생성 free 해제 - c 스타일
	//new 생성 delete 해제 - c++ 스타일
	//동적 할달은 사용자가 생성하고 사용자가 해제 해야함!!!!!!!

	int a = 10;
	10;

	int* p = new int(3); //생성
	//int p2 = new int(3);
	//int* p = new float(3.0f); //float* p2 = new float(3.0f);
	//new int(5); //XXXXXXXXX 주소 값으로 접근이 불가능

	cout << p << endl;
	cout << *p << endl;

	//주소는 상수! 바꿀 수 없음
	//p = 10;
	*p = 10; //주소에 있는 값을 수정

	delete p; //동적할당 해제

	//delete p; // 없는 주소 접근 불가능!!


	//int* arr = new int[3];

	int size;
	cin >> size;
	//런타임에 할당

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;

		cout << arr[i] << endl;
	}


	int* arr2 = new int[size];
	for (int i = 0; i < size; i++)
	{
		*(arr2 + i) = i;

		cout << arr[i] << endl;
	}

	//둘이 다름
	//*(arr2 + 2); //30
	//*arr2 + 2; //12

	delete[] arr;
	delete[] arr2;


	return 0;
}