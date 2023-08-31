#include <iostream>
#include <string>

using namespace std;

//객체란 '멤버함수와 변수(데이터)'의 묶음
//구조체		변수
//type		객체
//Trump		deck
//Player	player, dealer

//접근 제한자
//public : 외부 접근 가능, 공개
//private : 외부 접근 불가능, 비공개

struct Trump
{
	//struct 의 기본접근제한자 public
public: //private
	string shape;
	int number;

	void Print()
	{
		cout << number << endl;
	}
};

class Trump2
{
	//class 의 기본접근제한자 private
private: //public
	string shape;
	int number;

	void Print()
	{
		cout << number << endl;
	}
};

int main()
{
	Trump card1;
	card1.shape;
	card1.number;

	Trump2 card2;
	card2.shape;	//이거 뭐 만들다 넣었더라? 블랙잭 만들다 말았던 흔적이던가?
	card2.Print();


	return 0;
}