#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main()
{
	srand(time(NULL));

	// J Q K A 
	// ����

	//�ƽ�Ű�ڵ�
	//������ -> ���� 1byte
	//7��Ʈ + 1��Ʈ
	//char a;

	//a = '��';

	//cout << a << endl;

	char b;
	//b = 'H';
	b = 72;
	cout << b << endl;
	//b = 'I';
	b = 73;
	cout << b << endl;

	wchar_t c; // wide ���� 2byte
	c = L'��';
	//���� <-> ���
	//���ͷ� ����

	//C ��Ÿ�� ���ڿ�
	//���ڿ� ���ڰ��� + null
	"Hello";
	"�ȳ��ϼ���";

	//c++ ���ڿ�
	string d;
	d = "����� �ȳ�";
	cout << d << endl;

	wstring e;
	e = L"����� �ȳ�";

	//wchar_t arr[7] = { '��', '��' };

	//arr[0] = '��';
	//arr[1] = '��';
	//arr[2] = '��';
	int exit;
	cin >> exit;

}