#include <iostream>

using namespace std;

int main()
{
	//������ : �޸� �ּҸ� �����ϰ� ����Ű�� ����
	//�ּҰ��� �����ϱ� ���� ����
	//�޸𸮿� ������ �ּҸ� �����ϴ� Ÿ��(�ڷ���)
	//4byte(32bit) 8byte(64bit)

	/*float c = 5;
	float* d;
	d = &c;*/
	int* a; //int ���� �ּҸ� ��� ������
	int b = 5;
	a = &b;
	//*var : �ش� �޸� �ּҰ� ����Ű�� ��
	//&var : �ش� ������ �ּ�

	cout << "b�� �� : " << b << endl;
	cout << "b�� �ּ� �� : " << &b << endl;
	cout << "a�� �ּ� �� : " << &a << endl;
	cout << "a�� �� : " << a << endl;
	cout << "a�� �ּҰ� ����Ű�� �� : " << *a << endl;

	cout << "================================" << endl;

	int** c; //int* ���� �ּҸ� ��� ������, ����������
	c = &a;

	cout << "c�� �� : " << c << endl;
	cout << "c�� �ּ� �� : " << &c << endl;
	cout << "c�� �ּҰ� ����Ű�� �� : " << *c << endl;
	cout << "c�� �ּҰ� ����Ű�� ���� ����Ű�� �� : " << **c << endl;

	cout << "================================" << endl;

	int*** d; //int** ���� �ּҸ� ��� ������, ����������
	d = &c;

	int*********************************************************************** e;

	int arr[2];
	arr[0] = 10;
	//*(arr + 0)
	arr[1] = 15;
	//*(arr + 1)
	//arr �迭�� �̸��� �����ּ�

	const char* str1 = "*****"; //const ��� �ɺ��� ���
	const char* str2 = "*****";

	cout << (int*)str1 << endl;
	cout << (int*)str2 << endl;

	cout << str1 << endl;
	cout << str2 << endl;

	cout << str1 + 1 << endl;
	cout << str2 + 1 << endl;


	const char* str1 = "*****";
	const char* str3 = "     ";

	return 0;
}