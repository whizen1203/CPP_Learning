#include <iostream>

using namespace std;

//void Func()
//{
//	cout << "A" << endl;
//}

//����Ʈ �Ű�����
void Func(int a = 10)
{
	cout << a << endl;
}

//void Func(int a)
//{
//	cout << "B" << endl;
//}

void Func(int a, int b = 10)
{
	cout << a << endl;
}

//void Func(int a = 20, int b )
//{
//	cout << a << endl;
//} 

//
//void Func(int a, int b)
//{
//	cout << "D" << endl;
//}

void Func(float a)
{
	cout << "C" << endl;
}

//�Լ� �����ε� : �̸��� ������ �Է��� �ٸ� ��
int main()
{
	int a = 30;

	Func(3.0f);
	Func(3, 10);

	Func();
	Func(a, 10);


	return 0;
}

