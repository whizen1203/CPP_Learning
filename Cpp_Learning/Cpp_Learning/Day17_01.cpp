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

	//������ �Է� ī��Ʈ
	int input, size;
	int count;
	count = 0;

	cout << "������ �Է� : ";
	cin >> size;

	//�Ҵ�
	bingo = new int* [size];
	for (int i = 0; i < size; i++)
	{
		bingo[i] = new int[size];
	}

	//������ �����
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			bingo[x][y] = y * size + x;
		}
	}

	//������ ����
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

		//�Է��ϱ�
		cin >> input;

		if (input < 0 || input >= pow(size, 2))
		{
			cout << "�װ� �ȵ� ����" << endl;
			continue;
		}

		bool isChecking = false;

		////�Է��� �ְ� X
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
			cout << "�ߺ�" << endl;
			continue;
		}

		////���� �����
		////����
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

		//����
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

		//������ �Ʒ��� �밢��
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


		//���� �Ʒ��� �밢��
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
		cout << count << "����" << endl;
	}

	cin >> input;

	return 0;
}