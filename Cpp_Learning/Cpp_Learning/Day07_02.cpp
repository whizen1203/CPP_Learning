#include <iostream>
#include <time.h>

using namespace std;

#if 0
int main()
{
	//������ break, continue -> ���� ���� �ٷ� �� �ݺ����� ����
	//break ���� �μ��� -> Ż��
	//continue �ؿ� �ڵ� ����X, �ݺ������� ���ư�

	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == 1)
			{
				break;
				//continue;
			}
			cout << i << endl;
		}
	}


	int exit;
	cin >> exit;
}
#endif

#if 1 //��(type) ��ȯ : (type casting)
int main()
{
	//������, �Ͻ���, �����

	int a = 2100000000; // 4byte
	// 0000 0000 0000 0000 0000 0000 0000 0000
	short b = 100; //���� 2byte
	// 0000 0000 0000 0000

	//a = b; //����
	b = a; //�Ǳ������� ���� �̻���

	cout << a << endl;
	cout << b << endl;

	//ĳ���� ������
	//1. ũ�� -> ©��
	//2. ������
	//�Ǽ� <-> ����, ��ȣ�ִ� <-> ��ȣ����

	int c = 10;
	float d = 5.5f;

	c = (int)d;
	cout << c << endl;

	unsigned int e = -100;
	cout << e << endl;

	int input;
	float sum;
	cin >> input;

	sum = (float)input / 3;
	cout << sum << endl;

	int exit;
	cin >> exit;
}
#endif