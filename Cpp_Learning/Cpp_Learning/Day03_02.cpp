#include <iostream>

using namespace std;

//지역변수(local) : 범위 내에 있는 변수
//전역변수(global) : 범위 밖에 있는 변수

int c; //전역변수

namespace A
{
	int d;
}

using namespace A;

#if 0
int main()
{ //스코프 영역 범위

	d;
	//A::d;
	//:: 범위 접근 지정자

	c; //전역변수

	{
		int a; // 지역변수
		{
			int b;

			a;

			c;
		}

		//b;
	}
	//a;
}
#endif

#if 1
int main()
{
	//논리형 bool : 0(false)거짓  1(true)참

	//비교 연산자 > < == !(not) -> true false
	cout << !(3 == 5) << endl;

	//조건문 if 만약 ~라면
	//if (3 < 5)
	//{ //조건이 참 이여야지만 실행
	//	
	//	cout << "참 입니다" << endl;
	//}
	//else //그렇지 않으면, 그 외에~
	//{
	//	cout << "거짓 입니다" << endl;
	//}

	//if (3 > 5)
	//{
	//	cout << "참 입니다" << endl;
	//}
	//else //그렇지 않으면, 그 외에~
	//{
	//	cout << "거짓 입니다" << endl;
	//}

	int input;
	cin >> input;

	//if (input < 5)
	//{
	//	cout << "5보다 작다" << endl;
	//}
	//if (input == 5)
	//{
	//	cout << "5 같다" << endl;
	//}
	//if (input > 5)
	//{
	//	cout << "5보다 크다" << endl;
	//}

	/*if (input < 5)
	{
		cout << "5보다 작다" << endl;
	}
	else if (input == 5)
	{
		cout << "5 같다" << endl;
	}
	else if (input > 5)
	{
		cout << "5보다 크다" << endl;
	}*/

	if (input < 5)
	{
		cout << "5보다 작다" << endl;
	}
	else if (input == 5)
	{
		cout << "5 같다" << endl;
	}
	else
	{
		cout << "5보다 크다" << endl;
	}

}
#endif