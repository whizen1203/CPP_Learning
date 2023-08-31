#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//일차원배열
	int arr[25];
	//이차원배열
	int puzzle[5][5];

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			puzzle[x][y] = y * 5 + x;

			cout << puzzle[x][y] << "\t";
		}
		cout << endl;
	}

	cout << "========================================" << endl;

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			puzzle[x][y] = y * 5 + x;

			cout << puzzle[x][y] << "\t";
		}
		cout << endl;
	}

	int exit;
	cin >> exit;

	return 0;
}