#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main()
{
	srand(time(NULL));

	// J Q K A 
	// 문양

	//아스키코드
	//문자형 -> 정수 1byte
	//7비트 + 1비트
	//char a;

	//a = '☆';

	//cout << a << endl;

	char b;
	//b = 'H';
	b = 72;
	cout << b << endl;
	//b = 'I';
	b = 73;
	cout << b << endl;

	wchar_t c; // wide 넓은 2byte
	c = L'☆';
	//변수 <-> 상수
	//리터럴 문자

	//C 스타일 문자열
	//문자열 문자개수 + null
	"Hello";
	"안녕하세요";

	//c++ 문자열
	string d;
	d = "원기야 안녕";
	cout << d << endl;

	wstring e;
	e = L"원기야 안녕";

	//wchar_t arr[7] = { '원', '기' };

	//arr[0] = '원';
	//arr[1] = '기';
	//arr[2] = '야';
	int exit;
	cin >> exit;

}