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
	CLOVER
};

enum Number
{
	ACE = 1,
	JACK = 11,
	QUEEN,
	KING
};

Trump deck[52];

void PrintTrump(int index)
{
	switch (deck[index].number)
	{
	case ACE:
		cout << deck[index].shape << "A";
		break;
	case JACK:
		cout << deck[index].shape << "J";
		break;
	case QUEEN:
		cout << deck[index].shape << "Q";
		break;
	case KING:
		cout << deck[index].shape << "K";
		break;
	default:
		cout << deck[index].shape << deck[index].number;
		break;
	}
}

void Shuffle()
{
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % 52;
		int dest = rand() % 52;

		Trump temp = deck[sour];
		deck[sour] = deck[dest];
		deck[dest] = temp;
	}
}

int main()
{
	srand(time(NULL));

	int count, betting, gold, input;
	//변수 : 덱 카운트 베팅금액 소지금 입력값(하이로우세븐)

	gold = 50000;
	count = 0;

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

		//cout << deck[i].shape << deck[i].number << endl;
	}

	//덱 셔플
	Shuffle();

	/*for (int i = 0; i < 52; i++)
	{
		cout << deck[i].shape << deck[i].number << endl;
	}*/

	while (true)
	{
		cout << "------------하이 로우 세븐------------" << endl;

		//카드 출력
		for (int i = 0; i < 5; i++)
		{
			PrintTrump(i + count);
			cout << "\t";
			/*switch (deck[i + count].number)
			{
			case ACE:
				cout << deck[i + count].shape << "A" << "\t";
				break;
			case JACK:
				cout << deck[i + count].shape << "J" << "\t";
				break;
			case QUEEN:
				cout << deck[i + count].shape << "Q" << "\t";
				break;
			case KING:
				cout << deck[i + count].shape << "K" << "\t";
				break;
			default:
				cout << deck[i + count].shape << deck[i + count].number << "\t";
				break;
			}*/
		}
		cout << " ? " << endl;
		cout << "소지금 : " << gold << endl;

		//베팅
		cout << "베팅금액 : "; cin >> betting;

		if (betting < 1000 || betting > gold)
		{
			cout << "제대로 입력해" << endl;
			continue;
		}

		//하이로우세븐 입력
		cout << "hi 1 / low 2 / seven 3 : "; cin >> input;

		//승패 판단 - 소지금 차감
		if (input == 1) //하이
		{
			if (deck[count + 5].number > 7)
			{
				cout << "승~리~" << endl;
				gold += betting;
			}
			else
			{
				cout << "패~배~" << endl;
				gold -= betting;
			}
		}
		else if (input == 2) //로우
		{
			if (deck[count + 5].number < 7)
			{
				cout << "승~리~" << endl;
				gold += betting;
			}
			else
			{
				cout << "패~배~" << endl;
				gold -= betting;
			}
		}
		else if (input == 3) // 세븐
		{
			if (deck[count + 5].number == 7)
			{
				cout << "승~리~" << endl;
				gold += (betting * 7);
			}
			else
			{
				cout << "패~배~" << endl;
				gold -= betting;
			}
		}
		else
		{
			cout << "제대로 입력해" << endl;
			continue;
		}

		cout << "히든 카드 : ";
		PrintTrump(5 + count);
		cout << endl;
		/*switch (deck[5 + count].number)
		{
		case ACE:
			cout << deck[5 + count].shape << "A" << endl;
			break;
		case JACK:
			cout << deck[5 + count].shape << "J" << endl;
			break;
		case QUEEN:
			cout << deck[5 + count].shape << "Q" << endl;
			break;
		case KING:
			cout << deck[5 + count].shape << "K" << endl;
			break;
		default:
			cout << deck[5 + count].shape << deck[5 + count].number << endl;
			break;
		}*/

		count += 6;
		if (count > 47)
		{
			cout << "카드 소진 " << endl;
			//break;

			Shuffle();
			count = 0;
		}
	}

	int exit;
	cin >> exit;
}