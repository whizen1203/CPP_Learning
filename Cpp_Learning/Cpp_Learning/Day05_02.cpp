#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//�迭 
	//type name[n]  n -> ����, index 0 ~ (n - 1) 
	int arr[5]; //����
	//�������� ����, ����, ���� �ڷ���

	//����
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	//arr[5] = 6; ���� ����! access error

	//ȣ��
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;
	//cout << arr[5] << endl;
	//cout << arr[6] << endl;
	//cout << arr[100000] << endl;

	//�ݺ��� for
	//   �ʱⰪ;���ǽ�;������
	for (int i = 0; i < 5; i++)
	{
		cout << i << endl;
	}

	// 0 3 6 9 12
	for (int i = 0; i < 5; i++)
	{
		cout << i * 3 << endl;
	}

	cout << " ================================" << endl;

	int arr2[100];

	for (int i = 0; i < 100; i++)
	{
		arr2[i] = i + 1;
		cout << arr2[i] << endl;
	}

	/*for (int i = 0; i < 100; i++)
	{
		cout << arr2[i] << endl;
	}*/
}