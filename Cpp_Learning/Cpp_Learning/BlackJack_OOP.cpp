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

	cout << "��� �� �Է� : "; cin >> size;

	vector<Player> players;
	players.resize(size);

	Player* dealer;
	dealer = new Player;

	//��������
	dealer->name = "����";

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "�÷��̾� �̸� �Է� : "; cin >> players[i].name;
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
			temp = "��";
			break;
		case HEART:
			temp = "��";
			break;
		case SPADE:
			temp = "��";
			break;
		case CLOVER:
			temp = "��";
			break;
		}

		deck.push_back(MakeDeck(i % 13 + 1, temp));
	}

	//����
	while (true)
	{
		Shuffle(deck, 52 * DECKSIZE, 1000);
		index = 0;

		cout << "==================���� ��==================" << endl;

		for (int i = 0; i < size; i++)
		{
			players[i].hand.clear();
		}
		dealer->hand.clear();

		//�÷��̾�
		for (int i = 0; i < size; i++)
		{
			players[i].hand.push_back(deck[index]);
			index++;
			players[i].hand.push_back(deck[index]);
			index++;

			players[i].MakeJokbo();
			players[i].Print();

			//ī�� �� �޴�?
			while (true)
			{
				cout << "�� �ޱ� : 0, �ȹޱ� : �� �� -> "; cin >> input;

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
					cout << players[i].name << "����Ʈ" << endl;
					players[i].gold -= 1000;
					players[i].win = false;
					break;
				}
			}
		}
		cout << "==================���� ��==================" << endl;

		//����
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
			cout << dealer->name << "����Ʈ" << endl;
			dealer->win = false;

			for (int i = 0; i < size; i++)
			{
				if (players[i].win)
				{
					cout << players[i].name << "���� �¸�!" << endl;
					players[i].gold += 1000;
				}
			}
		}


		//���� ��
		for (int i = 0; i < size; i++)
		{
			if (players[i].win && dealer->win)
			{
				if (players[i].jokbo > dealer->jokbo)
				{
					cout << players[i].name << "�¸��߽��ϴ�!" << endl;
					players[i].gold += 1000;
				}
				else
				{
					cout << players[i].name << "�й��߽��ϴ�..." << endl;
					players[i].gold -= 1000;
				}
			}
		}
	}

	return 0;
}
