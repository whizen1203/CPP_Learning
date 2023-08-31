#include <iostream>
#include <time.h>

using namespace std;

#if 0
int main()
{
	//지시자 break, continue -> 내가 속한 바로 위 반복문이 기준
	//break 깨다 부수다 -> 탈출
	//continue 밑에 코드 실행X, 반복문으로 돌아감

	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == 1)
			{
				break;
				//continue;
			}
			cout << i << endl;
		}
	}


	int exit;
	cin >> exit;
}
#endif

#if 1 //형(type) 변환 : (type casting)
int main()
{
	//묵시적, 암시적, 명시적

	int a = 2100000000; // 4byte
	// 0000 0000 0000 0000 0000 0000 0000 0000
	short b = 100; //정수 2byte
	// 0000 0000 0000 0000

	//a = b; //가능
	b = a; //되긴하지만 값이 이상함

	cout << a << endl;
	cout << b << endl;

	//캐스팅 유의점
	//1. 크기 -> 짤림
	//2. 저장방식
	//실수 <-> 정수, 부호있는 <-> 부호없는

	int c = 10;
	float d = 5.5f;

	c = (int)d;
	cout << c << endl;

	unsigned int e = -100;
	cout << e << endl;

	int input;
	float sum;
	cin >> input;

	sum = (float)input / 3;
	cout << sum << endl;

	int exit;
	cin >> exit;
}
#endif