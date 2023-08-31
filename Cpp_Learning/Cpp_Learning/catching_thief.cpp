#include <iostream>
#include <time.h>
#include <string>

using namespace std;

struct Trump
{
	int number;
	string shape;
};

enum Shape
{
	DIA,
	HEART,
	SPADE,
	CLOVER,
	STAR
};

enum Number
{
	PASS,
	ACE,
	JACK = 11,
	QUEEN,
	KING,
	JOKER
};

Trump deck[53];

void PrintTrump(Trump deck[], int index)
{
	switch (deck[index].number)
	{
	case PASS:
		break;
	case ACE:
		cout << deck[index].shape << "A" << "\t";
		break;
	case JACK:
		cout << deck[index].shape << "J" << "\t";
		break;
	case QUEEN:
		cout << deck[index].shape << "Q" << "\t";
		break;
	case KING:
		cout << deck[index].shape << "K" << "\t";
		cout;
		break;
	case JOKER:
		cout << deck[index].shape << "JOKER" << "\t";
		break;
	default:
		cout << deck[index].shape << deck[index].number << "\t";
		break;
	}

}

void PrintPlayerCard(int dest, Trump deck[])
{
	for (int i = 0; i < dest; i++)
	{
		if (i == 0)
		{
			cout << "Player Card" << endl;
		}

		PrintTrump(deck, i % 18);

	}

	cout << endl;
}

void Swap(int sour, int dest)
{
	Trump temp = deck[sour];
	deck[sour] = deck[dest];
	deck[dest] = temp;
}

void Shuffle()
{
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % 53;
		int dest = rand() % 53;

		Swap(sour, dest);
	}
}

void DiscardSameNumber(int dest, Trump deck[])
{
	for (int i = 0; i < dest; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (deck[i].number == deck[j].number)
			{
				deck[i].number = 0;
				deck[j].number = 0;
			}
		}
	}
}

int FineLastIndex(Trump deck[], int dest)
{
	bool isCheck = false;
	int index = 0;

	for (int i = 0; i < dest; i++)
	{
		isCheck &= isCheck;
		if (deck[i].number != 0)
		{
			isCheck = false;
			break;
		}
		else
		{
			isCheck = true;
		}
	}

	while (!isCheck)
	{
		index = rand() % dest;
		if (deck[index].number != 0)
		{
			isCheck = true;
			return index;
			//break;
		}
	}

	return dest;
}

int FindZeroIndex(Trump deck[])
{
	bool isCheck = false;
	int index = 0;
	while (!isCheck)
	{
		index = rand() % 18;
		if (deck[index].number == 0)
		{
			isCheck = true;
			break;
		}

	}

	return index;
}

bool Check(int dest, Trump deck[])
{
	int count = 0;
	for (int i = 0; i < dest; i++)
	{
		if (deck[i].number != 0)
		{
			return false;
		};
		count = i;
	}

	if (count == dest)
	{
		return true;
	}
}

int main()
{
	srand(time(NULL));

	int input;

	//덱 만들기
	for (int i = 0; i < 52; i++)
	{
		deck[i].number = i % 13 + 1;

		switch (i / 13)
		{
		case DIA:
			deck[i].shape = "◆";
			break;
		case HEART:
			deck[i].shape = "♥";
			break;
		case SPADE:
			deck[i].shape = "♠";
			break;
		case CLOVER:
			deck[i].shape = "♣";
			break;
		}
	}

	//52 조커
	deck[52].number = 14;
	deck[52].shape = "★";

	//덱 셔플
	Shuffle();

	Trump plOne[18];
	Trump plTwo[18];
	Trump plThree[17];

	//카드 나눠주기
	for (int i = 0; i < 53; i++)
	{
		int index = i % 18;
		switch (i / 18)
		{
		case 0:
			plOne[index] = deck[i];
			break;
		case 1:
			plTwo[index] = deck[i];
			break;
		default:
			plThree[index] = deck[i];
			break;
		}
	}

	//카드 출력
	PrintPlayerCard(18, plOne);
	PrintPlayerCard(18, plTwo);
	PrintPlayerCard(17, plThree);

	//같은 카드 버리기
	DiscardSameNumber(18, plOne);
	DiscardSameNumber(18, plTwo);
	DiscardSameNumber(17, plThree);

	while (true)
	{
		cout << "------------도둑 잡기------------" << endl;

		//카드 출력
		PrintPlayerCard(18, plOne);
		PrintPlayerCard(18, plTwo);
		PrintPlayerCard(17, plThree);

		//랜덤으로 넘길카드를 찾고 숫자가 0이면 다시 뽑기
		//한턴 주고 확인 한턴 주고 확인
		Trump pass[3];
		//카드 넘버 초기화
		pass[0].number = 0;
		pass[1].number = 0;
		pass[2].number = 0;
		int index = 0;

		//플레이어1의 카드가 있을 때
		//넘길 카드 정하기
		//카드 주기
		//1 -> 2
		if (!Check(18, plOne))
		{
			index = FineLastIndex(plOne, 18);
			pass[0] = plOne[index];
			plOne[index].number = 0;
		}
		else
		{
			index = FineLastIndex(plThree, 17);
			pass[0] = plThree[index];
			plThree[index].number = 0;
		}

		if (!Check(18, plTwo))
		{
			index = FindZeroIndex(plTwo);
			plTwo[index] = pass[0];
			DiscardSameNumber(18, plTwo);
		}
		else
		{
			index = FindZeroIndex(plThree);
			plThree[index] = pass[0];
			DiscardSameNumber(17, plThree);
		}

		cout << "Player1 -> Player2 : ";
		PrintTrump(pass, 0); cout << endl;
		cout << endl;

		PrintPlayerCard(18, plOne);
		PrintPlayerCard(18, plTwo);
		PrintPlayerCard(17, plThree);
		cout << endl;

		if (Check(18, plOne) && Check(18, plTwo) ||
			Check(18, plTwo) && Check(18, plThree) ||
			Check(18, plOne) && Check(18, plThree))
		{
			cout << "게임 종료" << endl;
			break;
		}
		cin >> input;


		//플레이어2의 카드가 있을 때
		//넘길 카드 정하기
		//카드 주기
		//2 -> 3

		//플레이어2의 카드가 있을 때
		if (!Check(18, plTwo))
		{
			index = FineLastIndex(plTwo, 18);
			pass[0] = plTwo[index];
			plTwo[index].number = 0;
		}
		else
		{
			index = FineLastIndex(plOne, 18);
			pass[0] = plOne[index];
			plOne[index].number = 0;
		}

		if (!Check(18, plThree))
		{
			index = FindZeroIndex(plThree);
			plThree[index] = pass[0];
			DiscardSameNumber(17, plThree);
		}
		else
		{
			index = FindZeroIndex(plOne);
			plOne[index] = pass[0];
			DiscardSameNumber(18, plOne);
		}

		cout << "Player2 -> Player3 : ";
		PrintTrump(pass, 0); cout << endl;
		cout << endl;



		PrintPlayerCard(18, plOne);
		PrintPlayerCard(18, plTwo);
		PrintPlayerCard(17, plThree);
		cout << endl;

		if (Check(18, plOne) && Check(18, plTwo) ||
			Check(18, plTwo) && Check(18, plThree) ||
			Check(18, plOne) && Check(18, plThree))
		{
			cout << "게임 종료" << endl;
			break;
		}
		cin >> input;


		//플레이어3의 카드가 있을 때
		// 2 -> 0
		if (!Check(17, plThree))
		{
			index = FineLastIndex(plThree, 17);
			pass[0] = plThree[index];
			plThree[index].number = 0;
		}
		else
		{
			index = FineLastIndex(plTwo, 18);
			pass[0] = plTwo[index];
			plTwo[index].number = 0;
		}
		if (!Check(18, plOne))
		{
			index = FindZeroIndex(plOne);
			plOne[index] = pass[0];
			DiscardSameNumber(18, plOne);
		}
		else
		{
			index = FindZeroIndex(plTwo);
			plTwo[index] = pass[0];
			DiscardSameNumber(18, plTwo);
		}

		cout << "Player3 -> Player1 : ";
		PrintTrump(pass, 0); cout << endl;
		cout << endl;

		DiscardSameNumber(18, plOne);

		PrintPlayerCard(18, plOne);
		PrintPlayerCard(18, plTwo);
		PrintPlayerCard(17, plThree);
		cout << endl;


		if (Check(18, plOne) && Check(18, plTwo) ||
			Check(18, plTwo) && Check(18, plThree) ||
			Check(18, plOne) && Check(18, plThree))
		{
			cout << "게임 종료" << endl;
			break;
		}

		cin >> input;
	}


	return 0;
}