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

	//������ �Է� ī��Ʈ
	int input, count;
	count = 0;

	//������ �����
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			bingo[x][y] = y * 5 + x;
		}
	}

	//������ ����
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

		//�Է��ϱ�
		cin >> input;

		if (input < 0 || input > 24)
		{
			continue;
		}

		bool isChecking = false;

		//�Է��� �ְ� X
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

		// 0 ����� �� true
		if (!isChecking)
		{
			cout << "�ߺ�" << endl;
			continue;
		}

		//���� �����
		//����
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

		//����
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

		//������ �Ʒ��� �밢��
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


		//���� �Ʒ��� �밢��
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

		cout << count << "����" << endl;

		if (count >= 3)
		{
			break;
		}
	}

	return 0;
}