#include <iostream>

using namespace std;

#if 0
int main()
{
	int a = 3;

	int* b;
	b = &a;

	//������ ������ reference type
	//����� ���ÿ� ����
	//����X
	//������X
	int& c = a;

	cout << a << endl;
	cout << c << endl;

	a = 7;

	cout << a << endl;
	cout << c << endl;

	cout << &a << endl;
	cout << &c << endl;

	c = 10;

	cout << a << endl;
	cout << c << endl;

	int d = 15;
	c = d;

	cout << a << endl;
	cout << c << endl;

	*b = 20;
	cout << a << endl;
	cout << c << endl;

	return 0;
}
#endif

//x = a;
void Add5(int x)
{
	x += 5;

	//cout << x << endl;
}

void Add6(int& x)
{
	x += 6;
}

void Add7(int* x)
{
	*x += 7;
}

//�Լ� ȣ�� ���
int main()
{
	int a = 10;

	//call by value ���� ���� ȣ��
	//���� �����ؼ� �ѱ�
	Add5(a);
	cout << a << endl;

	//call by reference ������ ���� ȣ��
	//�ּҸ� ����, �������� ����
	Add6(a);
	cout << a << endl;

	//call by pointer(aaddrreess) �ּҿ� ���� ȣ��
	Add7(&a);
	cout << a << endl;

	return 0;
}