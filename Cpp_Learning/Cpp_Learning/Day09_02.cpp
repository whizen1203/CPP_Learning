#include <iostream>
#include <time.h>
#include <string>

using namespace std;

//����ü struct
//����� ���� Ÿ�� - �ʷϻ�
//�ٸ� �ڷ������� ���� �� �ִ�
struct Class6
{
	//��� ����
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

	//. ������ٿ�����
	//student.name[0]; XXXXXXXXXX
	//student[0] = 10; XXXXXXXXXX
	student[0].name = "�Ѽ���";
	student[0].age = 20;

	student[1].name = "������";
	student[1].age = 4;

	student[2].name = "�����";
	student[2].age = 18;

	cout << student[0].name << "\t" << student[0].age << endl;
	cout << student[1].name << "\t" << student[1].age << endl;
	cout << student[2].name << "\t" << student[2].age << endl;


	//Ʈ���� 

	Trump deck[52];

	for (int i = 0; i < 52; i++)
	{
		deck[i].number = i % 13 + 1;
		deck[i].shape = "��";

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