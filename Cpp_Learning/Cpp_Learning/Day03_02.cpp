#include <iostream>

using namespace std;

//��������(local) : ���� ���� �ִ� ����
//��������(global) : ���� �ۿ� �ִ� ����

int c; //��������

namespace A
{
	int d;
}

using namespace A;

#if 0
int main()
{ //������ ���� ����

	d;
	//A::d;
	//:: ���� ���� ������

	c; //��������

	{
		int a; // ��������
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
	//���� bool : 0(false)����  1(true)��

	//�� ������ > < == !(not) -> true false
	cout << !(3 == 5) << endl;

	//���ǹ� if ���� ~���
	//if (3 < 5)
	//{ //������ �� �̿������� ����
	//	
	//	cout << "�� �Դϴ�" << endl;
	//}
	//else //�׷��� ������, �� �ܿ�~
	//{
	//	cout << "���� �Դϴ�" << endl;
	//}

	//if (3 > 5)
	//{
	//	cout << "�� �Դϴ�" << endl;
	//}
	//else //�׷��� ������, �� �ܿ�~
	//{
	//	cout << "���� �Դϴ�" << endl;
	//}

	int input;
	cin >> input;

	//if (input < 5)
	//{
	//	cout << "5���� �۴�" << endl;
	//}
	//if (input == 5)
	//{
	//	cout << "5 ����" << endl;
	//}
	//if (input > 5)
	//{
	//	cout << "5���� ũ��" << endl;
	//}

	/*if (input < 5)
	{
		cout << "5���� �۴�" << endl;
	}
	else if (input == 5)
	{
		cout << "5 ����" << endl;
	}
	else if (input > 5)
	{
		cout << "5���� ũ��" << endl;
	}*/

	if (input < 5)
	{
		cout << "5���� �۴�" << endl;
	}
	else if (input == 5)
	{
		cout << "5 ����" << endl;
	}
	else
	{
		cout << "5���� ũ��" << endl;
	}

}
#endif