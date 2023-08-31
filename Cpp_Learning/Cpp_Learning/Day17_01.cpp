#include <iostream>
#include <time.h>
#include <string>
#include <math.h>

using namespace std;

int** bingo;

void Swap(int sour1, int sour2, int dest1, int dest2)
{
	int temp = bingo[sour1][sour2];
	bingo[sour1][sour2] = bingo[dest1][dest2];
	bingo[dest1][dest2] = temp;
}

void Shuffle(int size)
{
	for (int i = 0; i < 1000; i++)
	{
		int sour1 = rand() % size;
		int sour2 = rand() % size;
		int dest1 = rand() % size;
		int dest2 = rand() % size;

		Swap(sour1, sour2, dest1, dest2);
	}

}

int main()
{
	srand(time(NULL));

	//빙고판 입력 카운트
	int input, size;
	int count;
	count = 0;

	cout << "사이즈 입력 : ";
	cin >> size;

	//할당
	bingo = new int* [size];
	for (int i = 0; i < size; i++)
	{
		bingo[i] = new int[size];
	}

	//빙고판 만들기
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			bingo[x][y] = y * size + x;
		}
	}

	//빙고판 섞고
	Shuffle(size);

	while (count < 3)
	{
		count = 0;

		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{

				if (bingo[x][y] == -1)	cout << "X" << "\t";
				else
					cout << bingo[x][y] << "\t";
			}
			cout << endl;
		}

		//입력하기
		cin >> input;

		if (input < 0 || input >= pow(size, 2))
		{
			cout << "그건 안됨 ㅅㄱ" << endl;
			continue;
		}

		bool isChecking = false;

		////입력한 애가 X
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (input == bingo[x][y])
				{
					bingo[x][y] = -1;
					isChecking = true;
				}
			}
		}

		if (not isChecking)
		{
			cout << "중복" << endl;
			continue;
		}

		////빙고 몇개인지
		////가로
		for (int y = 0; y < size; y++)
		{
			int countX = 0;

			for (int x = 0; x < size; x++)
			{
				if (bingo[x][y] == -1)
				{
					countX++;
				}
				if (countX == size)
				{
					count++;
				}
			}
		}

		//세로
		for (int x = 0; x < size; x++)
		{
			int countY = 0;
			for (int y = 0; y < size; y++)
			{
				if (bingo[x][y] == -1)
				{
					countY++;
				}
				if (countY == size)
				{
					count++;
				}
			}
		}

		//오른쪽 아래로 대각선
		int countZ = 0;
		for (int i = 0; i < size; i++)
		{
			if (bingo[i][i] == -1)
			{
				countZ++;
			}
			if (countZ == size)
			{
				count++;
			}
		}


		//왼쪽 아래로 대각선
		int countW = 0;
		for (int i = 0; i < size; i++)
		{
			if (bingo[size - 1 - i][i] == -1)
			{
				countW++;
			}
			if (countW == size)
			{
				count++;
			}
		}
		cout << count << "빙고" << endl;
	}

	cin >> input;

	return 0;
}