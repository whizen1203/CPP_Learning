#include <iostream>

using namespace std;

//void Func()
//{
//	cout << "A" << endl;
//}

//디폴트 매개변수
void Func(int a = 10)
{
	cout << a << endl;
}

//void Func(int a)
//{
//	cout << "B" << endl;
//}

void Func(int a, int b = 10)
{
	cout << a << endl;
}

//void Func(int a = 20, int b )
//{
//	cout << a << endl;
//} 

//
//void Func(int a, int b)
//{
//	cout << "D" << endl;
//}

void Func(float a)
{
	cout << "C" << endl;
}

//함수 오버로딩 : 이름은 같지만 입력이 다른 것
int main()
{
	int a = 30;

	Func(3.0f);
	Func(3, 10);

	Func();
	Func(a, 10);


	return 0;
}

