#include <iostream>
#include <time.h>

using namespace std;

// enum�� ����
enum A
{
	a = 10,
	b,
	c = 20,
	d
};

enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

int main()
{
	srand(time(NULL));

	int a = 1;

	//switch �� - ���ǹ� 

	//while (true)
	//{
	//	cin >> a;

	//	//	   ����
	//	switch (a)
	//	{
	//	case 0:
	//		cout << "0" << endl;
	//		break;
	//	case 1:
	//		cout << "1" << endl;
	//		break;
	//	case 2:
	//		cout << "2" << endl;
	//		break;
	//	default: //�� �� else
	//		cout << "3" << endl;
	//		break;
	//	}
	//}

	//�ڷ��� -> ��������� Ÿ��
	Dir dir = UP;

	switch (dir)
	{
	case LEFT:
		cout << "LEFT" << endl;
		break;
	case RIGHT:
		cout << "RIGHT" << endl;
		break;
	case UP:
		cout << "UP" << endl;
		break;
	case DOWN:
		cout << "DOWN" << endl;
		break;
	}


	int exit;
	cin >> exit;
}