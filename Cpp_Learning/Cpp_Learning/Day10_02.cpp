#include <iostream>
#include <time.h>
#include <string>

using namespace std;

//�Լ�
//��ȯ�� �ݳ���(�Ű����� -> input)
//{
	//return output;
//}
//�ڵ��� �ߺ��� ����

//input O output O
int Add5(int x)
{
	//����
	x += 5;
	return x;
}

//input X output O
int Return5()
{
	return 5;
}

//void ����, �� 
//input X output X
void Print()
{
	cout << "***" << endl;
	cout << "*****" << endl;
	cout << "********" << endl;
	cout << "***********" << endl;
	cout << "***************" << endl;
}

//input O output X
void Print1(int x)
{
	cout << x << endl;
}

int main()
{
	srand(time(NULL));

	int a = 10;

	Print();
	Print();
	Print();
	Print();
	Print();

	Print(); //ȣ��

	Print1(a); //ȣ��

	cout << Return5() << endl; //ȣ��

	cout << Add5(a) << endl; //ȣ��
	cout << Add5(15) << endl; //ȣ��
	cout << Add5(30) << endl; //ȣ��
	cout << Add5(50) << endl; //ȣ��

	int exit;
	cin >> exit;

	//���α׷� ����
	return 0;
}