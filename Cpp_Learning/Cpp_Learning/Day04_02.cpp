#include <iostream>

using namespace std;

//반복문
int main()
{

	//cin >> a;

	// while ~동안에
	// 조건이 true 일 때 반복
	/*while (a > 10)
	{
		cout << "1" << endl;
	}*/

	//무한루프

	//cout << a << endl;
	//cout << a-- << endl;
	//cout << a << endl;

	//bool b; // 1 0

	int a = 10;
	//논리연산자 -> &&(and) ||(or)  

	//&&(and) 그리고 -> 둘 다 참 이여야만 참
	// 1 && 1 -> 1
	// 1 && 0 -> 0
	// 0 && 1 -> 0
	// 0 && 0 -> 0

	//||(or) 또는 -> 하나라도 참이면 참
	// 1 || 1 -> 1
	// 1 || 0 -> 1
	// 0 || 1 -> 1
	// 0 || 0 -> 0

	cout << ((5 > 3) && (5 < 3)) << endl;
	cout << ((5 > 3) && (5 > 3)) << endl;
	cout << ((5 > 3) || (5 > 3)) << endl;
	cout << ((5 > 3) || (5 < 3)) << endl;
}