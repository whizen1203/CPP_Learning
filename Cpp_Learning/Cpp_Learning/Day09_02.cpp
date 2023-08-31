#include <iostream>
#include <time.h>
#include <string>

using namespace std;

//구조체 struct
//사용자 정의 타입 - 초록색
//다른 자료형들을 묶을 수 있다
struct Class6
{
	//멤버 변수
	string name;
	int age;
};

struct Trump
{
	int number;
	string shape;
};

int main()
{
	srand(time(NULL));

	Class6 student[3];

	//. 멤버접근연산자
	//student.name[0]; XXXXXXXXXX
	//student[0] = 10; XXXXXXXXXX
	student[0].name = "한석희";
	student[0].age = 20;

	student[1].name = "문원기";
	student[1].age = 4;

	student[2].name = "이재숙";
	student[2].age = 18;

	cout << student[0].name << "\t" << student[0].age << endl;
	cout << student[1].name << "\t" << student[1].age << endl;
	cout << student[2].name << "\t" << student[2].age << endl;


	//트럼프 

	Trump deck[52];

	for (int i = 0; i < 52; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].shape = "♧";

		switch (deck[i].number)
		{
		case 1:
			cout << deck[i].shape << "\t" << "A" << endl;
			break;
		case 11:
			cout << deck[i].shape << "\t" << "J" << endl;
			break;
		case 12:
			cout << deck[i].shape << "\t" << "Q" << endl;
			break;
		case 13:
			cout << deck[i].shape << "\t" << "K" << endl;
			break;
		default:
			cout << deck[i].shape << "\t" << deck[i].number << endl;
			break;
		}
	}


	int exit;
	cin >> exit;
}