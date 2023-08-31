#include <iostream>

using namespace std;

void Add4(int* arr)
{
	arr[2];
	*(arr + 2);
}

void Add3(int arr[])
{
	arr[2];
}

void Add2(int arr[][5])
{
	arr[2][2];
}

void Add1(int** arr)
{
	arr[4][1];
}

int main()
{
	//器牢磐 : 林家甫 啊府虐绰 蔼
	int* p; //int 屈狼 林家

	int arr3[5];
	int arr2[5][5];
	int** arr; //int* 屈狼 林家

	Add4(p);
	Add3(arr3);
	Add2(arr2);
	Add1(arr);

	arr = new int* [5];


	for (int i = 0; i < 5; i++)
	{
		arr[i] = new int[5];
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			arr[x][y] = y * 5 + x;
		}
	}

	cout << arr << endl; //林家
	cout << arr[0] << endl; //林家
	cout << arr[0][0] << endl; //蔼

	cout << *arr << endl; //林家
	cout << **arr << endl; //蔼

	arr[2][3] = 15;
	cout << *(*(arr + 2) + 3) << endl;

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << arr[x][y] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}