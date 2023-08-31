#include <iostream>
#include <time.h>

using namespace std;

int puzzle[25];

enum Dir
{
	LEFT = 4,
	RIGHT = 6,
	UP = 8,
	DOWN = 2
};

struct Pos
{
	int x;
	int y;
};

//�Լ��� ����� ���Ǹ� ����Ʈ�� ���� �� �ִ�
void Swap(int sour, int dest); //����

void Shuffle();

int ChangeOne(Pos pos);

int main()
{
	srand(time(NULL));

	//���� : �迭25�� , �Է°�	
	int input;
	Pos zeroPos;
	zeroPos.x = 4; zeroPos.y = 4;

	//�迭 �ʱ�ȭ
	for (int i = 0; i < 25; i++)
	{
		puzzle[i] = i;

		//cout << puzzle[i] << "\t";

		//if (i % 5 == 4)
		//{
		//	cout << endl;
		//}
	}

	//0�� ��ġ
	//f12 ������ ���ǵ� ������ ��
	Swap(0, 24);

	//����
	Shuffle();

	while (true)
	{
		//���
		for (int i = 0; i < 25; i++)
		{
			cout << puzzle[i] << "\t";

			if (i % 5 == 4)
			{
				cout << endl;
			}
		}

		//�Է�
		cout << "2 4 8 6 -> "; cin >> input;

		//�����̱�
		if (input == DOWN && zeroPos.y != 4) //�Ʒ�
		{
			Pos down;
			down.x = zeroPos.x;
			down.y = zeroPos.y + 1;

			Swap(ChangeOne(zeroPos), ChangeOne(down));

			zeroPos = down;
		}
		else if (input == UP && zeroPos.y != 0) //��
		{
			//�ٲٱ�
			//Swap(0�� �ε��� , �� �� �ε��� );
			//Swap(zeroPos, �� ���� ��ǥ);

			Pos up;
			up.x = zeroPos.x;
			up.y = zeroPos.y - 1;

			Swap(ChangeOne(zeroPos), ChangeOne(up));

			zeroPos = up;
		}
		else if (input == LEFT && zeroPos.x != 0) //����
		{
			Pos left;
			left.x = zeroPos.x - 1;
			left.y = zeroPos.y;

			Swap(ChangeOne(zeroPos), ChangeOne(left));

			zeroPos = left;
		}
		else if (input == RIGHT && zeroPos.x != 4) //������
		{
			Pos right;
			right.x = zeroPos.x + 1;
			right.y = zeroPos.y;

			Swap(ChangeOne(zeroPos), ChangeOne(right));

			zeroPos = right;
		}
		else
		{
			cout << "�߸� �Է� ��3��" << endl;
			continue;
		}

		system("cls");
	}



	return 0;
}

void Swap(int sour, int dest)
{
	int temp = puzzle[sour];
	puzzle[sour] = puzzle[dest];
	puzzle[dest] = temp;
}

void Shuffle()
{
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % 24;
		int dest = rand() % 24;

		Swap(sour, dest);
	}
}

int ChangeOne(Pos pos)
{
	return pos.y * 5 + pos.x;
}