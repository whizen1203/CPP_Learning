#include <iostream>
#include <string>
#include <vector> //c++ 라이브러리
//#include <time.h> C스타일 라이브러리

using namespace std;

struct Trump
{
	int number;
	string shape;

	void Print()
	{
		cout << shape << number << endl;
	}
};

Trump MakeDeck(int number, string shape)
{
	Trump temp;
	temp.number = number;
	temp.shape = shape;

	return temp;
}

int main()
{
	vector<Trump> deck;

	// 1. 임시변수를 이용하는 방법
	Trump temp;
	temp.number = 10;
	temp.shape = "★";

	deck.push_back(temp);
	//deck[0].number = ;

	//2. 함수를 이용하는 방법
	deck.push_back(MakeDeck(5, "★"));

	//3. resize 잡고 인덱스로 접근해서 초기화

	//cout << deck.size() << endl;
	deck[0].Print();
	deck[1].Print();


	return 0;
}