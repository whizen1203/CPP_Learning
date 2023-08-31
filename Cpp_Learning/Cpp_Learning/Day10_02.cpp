#include <iostream>
#include <time.h>
#include <string>

using namespace std;

//함수
//반환형 콜네임(매개변수 -> input)
//{
	//return output;
//}
//코드의 중복성 제거

//input O output O
int Add5(int x)
{
	//정의
	x += 5;
	return x;
}

//input X output O
int Return5()
{
	return 5;
}

//void 공허, 빈 
//input X output X
void Print()
{
	cout << "***" << endl;
	cout << "*****" << endl;
	cout << "********" << endl;
	cout << "***********" << endl;
	cout << "***************" << endl;
}

//input O output X
void Print1(int x)
{
	cout << x << endl;
}

int main()
{
	srand(time(NULL));

	int a = 10;

	Print();
	Print();
	Print();
	Print();
	Print();

	Print(); //호출

	Print1(a); //호출

	cout << Return5() << endl; //호출

	cout << Add5(a) << endl; //호출
	cout << Add5(15) << endl; //호출
	cout << Add5(30) << endl; //호출
	cout << Add5(50) << endl; //호출

	int exit;
	cin >> exit;

	//프로그램 종료
	return 0;
}