#include "stdafx.h"

Trump MakeDeck(int number, string shape)
{
	Trump temp;
	temp.number = number;
	temp.shape = shape;

	return temp;
}

int PlayBlackJack()
{
	int input, index;
	int size;

	cout << "사람 수 입력 : "; cin >> size;

	vector<Player> players;
	players.resize(size);

	Player* dealer;
	dealer = new Player;

	//딜러셋팅
	dealer->name = "딜러";

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "플레이어 이름 입력 : "; cin >> players[i].name;
		players[i].gold = 50000;
	}

	vector<Trump> deck;

	for (int i = 0; i < 52 * DECKSIZE; i++)
	{
		string temp;
		int cut = i % 52;
		switch (cut / 13)
		{
		case DIA:
			temp = "◆";
			break;
		case HEART:
			temp = "♥";
			break;
		case SPADE:
			temp = "♠";
			break;
		case CLOVER:
			temp = "♣";
			break;
		}

		deck.push_back(MakeDeck(i % 13 + 1, temp));
	}

	//한판
	while (true)
	{
		Shuffle(deck, 52 * DECKSIZE, 1000);
		index = 0;

		cout << "==================유저 턴==================" << endl;

		for (int i = 0; i < size; i++)
		{
			players[i].hand.clear();
		}
		dealer->hand.clear();

		//플레이어
		for (int i = 0; i < size; i++)
		{
			players[i].hand.push_back(deck[index]);
			index++;
			players[i].hand.push_back(deck[index]);
			index++;

			players[i].MakeJokbo();
			players[i].Print();

			//카드 더 받니?
			while (true)
			{
				cout << "더 받기 : 0, 안받기 : 그 외 -> "; cin >> input;

				if (input != 0)
				{
					players[i].win = true;
					break;
				}

				players[i].hand.push_back(deck[index]);
				index++;

				players[i].MakeJokbo();
				players[i].Print();

				if (players[i].jokbo > 21)
				{
					cout << players[i].name << "버스트" << endl;
					players[i].gold -= 1000;
					players[i].win = false;
					break;
				}
			}
		}
		cout << "==================딜러 턴==================" << endl;

		//딜러
		dealer->win = true;

		dealer->hand.push_back(deck[index]);
		index++;
		dealer->hand.push_back(deck[index]);
		index++;

		dealer->MakeJokbo(true);
		dealer->Print(true);

		while (dealer->jokbo < 17)
		{
			dealer->hand.push_back(deck[index]);
			index++;

			dealer->MakeJokbo(true);
			dealer->Print(true);
		}

		if (dealer->jokbo > 21)
		{
			cout << dealer->name << "버스트" << endl;
			dealer->win = false;

			for (int i = 0; i < size; i++)
			{
				if (players[i].win)
				{
					cout << players[i].name << "딜러 승리!" << endl;
					players[i].gold += 1000;
				}
			}
		}


		//승자 돈
		for (int i = 0; i < size; i++)
		{
			if (players[i].win && dealer->win)
			{
				if (players[i].jokbo > dealer->jokbo)
				{
					cout << players[i].name << "승리했습니다!" << endl;
					players[i].gold += 1000;
				}
				else
				{
					cout << players[i].name << "패배했습니다..." << endl;
					players[i].gold -= 1000;
				}
			}
		}
	}

	return 0;
}
