#include <iostream>
#include <time.h>

using namespace std;

int bingo[5][5];

void Swap(int sour1, int sour2, int dest1, int dest2)
{
	int temp = bingo[sour1][sour2];
	bingo[sour1][sour2] = bingo[dest1][dest2];
	bingo[dest1][dest2] = temp;
}

void Shuffle()
{
	for (int i = 0; i < 1000; i++)
	{
		int sour1 = rand() % 5;
		int sour2 = rand() % 5;
		int dest1 = rand() % 5;
		int dest2 = rand() % 5;

		Swap(sour1, sour2, dest1, dest2);
	}

}

int main()
{
	srand(time(NULL));

	//빙고판 입력 카운트
	int input, count;
	count = 0;

	//빙고판 만들기
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			bingo[x][y] = y * 5 + x;
		}
	}

	//빙고판 섞고
	Shuffle();

	while (true)
	{
		count = 0;

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (bingo[x][y] == -1)																			cout << "X" << "\t";
				else																																									cout << bingo[x][y] << "\t";
			}
			cout << endl;
		}

		//입력하기
		cin >> input;

		if (input < 0 || input > 24)
		{
			continue;
		}

		bool isChecking = false;

		//입력한 애가 X
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (input == bingo[x][y])
				{
					bingo[x][y] = -1;
					isChecking = true;
				}
			}
		}

		// 0 빼고는 다 true
		if (!isChecking)
		{
			cout << "중복" << endl;
			continue;
		}

		//빙고 몇개인지
		//가로
		for (int y = 0; y < 5; y++)
		{
			int countX = 0;

			for (int x = 0; x < 5; x++)
			{
				if (bingo[x][y] == -1)
				{
					countX++;
				}
				if (countX == 5)
				{
					count++;
				}
			}
		}

		//세로
		for (int x = 0; x < 5; x++)
		{
			int countY = 0;
			for (int y = 0; y < 5; y++)
			{
				if (bingo[x][y] == -1)
				{
					countY++;
				}
				if (countY == 5)
				{
					count++;
				}
			}
		}

		//오른쪽 아래로 대각선
		int countZ = 0;
		for (int i = 0; i < 5; i++)
		{
			if (bingo[i][i] == -1)
			{
				countZ++;
			}
			if (countZ == 5)
			{
				count++;
			}
		}


		//왼쪽 아래로 대각선
		int countW = 0;
		for (int i = 0; i < 5; i++)
		{
			if (bingo[4 - i][i] == -1)
			{
				countW++;
			}
			if (countW == 5)
			{
				count++;
			}
		}

		cout << count << "빙고" << endl;

		if (count >= 3)
		{
			break;
		}
	}

	return 0;
}