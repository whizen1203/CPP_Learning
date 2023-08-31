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

//함수는 선언과 정의를 떨어트려 놓을 수 있다
void Swap(int sour, int dest); //선언

void Shuffle();

int ChangeOne(Pos pos);

int main()
{
	srand(time(NULL));

	//변수 : 배열25개 , 입력값	
	int input;
	Pos zeroPos;
	zeroPos.x = 4; zeroPos.y = 4;

	//배열 초기화
	for (int i = 0; i < 25; i++)
	{
		puzzle[i] = i;

		//cout << puzzle[i] << "\t";

		//if (i % 5 == 4)
		//{
		//	cout << endl;
		//}
	}

	//0번 위치
	//f12 누르면 정의된 곳으로 감
	Swap(0, 24);

	//섞기
	Shuffle();

	while (true)
	{
		//출력
		for (int i = 0; i < 25; i++)
		{
			cout << puzzle[i] << "\t";

			if (i % 5 == 4)
			{
				cout << endl;
			}
		}

		//입력
		cout << "2 4 8 6 -> "; cin >> input;

		//움직이기
		if (input == DOWN && zeroPos.y != 4) //아래
		{
			Pos down;
			down.x = zeroPos.x;
			down.y = zeroPos.y + 1;

			Swap(ChangeOne(zeroPos), ChangeOne(down));

			zeroPos = down;
		}
		else if (input == UP && zeroPos.y != 0) //위
		{
			//바꾸기
			//Swap(0의 인덱스 , 그 위 인덱스 );
			//Swap(zeroPos, 그 위의 좌표);

			Pos up;
			up.x = zeroPos.x;
			up.y = zeroPos.y - 1;

			Swap(ChangeOne(zeroPos), ChangeOne(up));

			zeroPos = up;
		}
		else if (input == LEFT && zeroPos.x != 0) //왼쪽
		{
			Pos left;
			left.x = zeroPos.x - 1;
			left.y = zeroPos.y;

			Swap(ChangeOne(zeroPos), ChangeOne(left));

			zeroPos = left;
		}
		else if (input == RIGHT && zeroPos.x != 4) //오른쪽
		{
			Pos right;
			right.x = zeroPos.x + 1;
			right.y = zeroPos.y;

			Swap(ChangeOne(zeroPos), ChangeOne(right));

			zeroPos = right;
		}
		else
		{
			cout << "잘못 입력 ㅡ3ㅡ" << endl;
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