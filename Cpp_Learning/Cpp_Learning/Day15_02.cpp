#include <iostream>

using namespace std;

int main()
{
	//�����Ҵ�
	//���� ����
	//ũ�� ���X
	//malloc realloc calloc ���� free ���� - c ��Ÿ��
	//new ���� delete ���� - c++ ��Ÿ��
	//���� �Ҵ��� ����ڰ� �����ϰ� ����ڰ� ���� �ؾ���!!!!!!!

	int a = 10;
	10;

	int* p = new int(3); //����
	//int p2 = new int(3);
	//int* p = new float(3.0f); //float* p2 = new float(3.0f);
	//new int(5); //XXXXXXXXX �ּ� ������ ������ �Ұ���

	cout << p << endl;
	cout << *p << endl;

	//�ּҴ� ���! �ٲ� �� ����
	//p = 10;
	*p = 10; //�ּҿ� �ִ� ���� ����

	delete p; //�����Ҵ� ����

	//delete p; // ���� �ּ� ���� �Ұ���!!


	//int* arr = new int[3];

	int size;
	cin >> size;
	//��Ÿ�ӿ� �Ҵ�

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;

		cout << arr[i] << endl;
	}


	int* arr2 = new int[size];
	for (int i = 0; i < size; i++)
	{
		*(arr2 + i) = i;

		cout << arr[i] << endl;
	}

	//���� �ٸ�
	//*(arr2 + 2); //30
	//*arr2 + 2; //12

	delete[] arr;
	delete[] arr2;


	return 0;
}