#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#define DECKSIZE 4

using namespace std;

enum Shape
{
	DIA,
	HEART,
	SPADE,
	CLOVER
};

enum NUM
{
	A = 1,
	J = 11,
	Q,
	K
};

struct Trump
{
	string	shape;
	int		number;

	void Print()
	{
		
		switch (number)
		{
		case A:
			cout << shape << "A" << "\t";
			break;
		case J:
			cout << shape << "J" << "\t";
			break;
		case Q:
			cout << shape << "Q" << "\t";
			break;
		case K:
			cout << shape << "K" << "\t";
			break;
		default:
			cout << shape << number << "\t";
			break;
		}
	}
};

struct Player
{
	string			name;
	int				gold;
	vector<Trump>	hand;
	int				jokbo;
	bool			win;

	void MakeJokbo(bool dealer = 0)
	{
		jokbo = 0;

		int ace;
		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i].number > 10)
			{
				jokbo += 10;
			}
			else if (hand[i].number == 1)
			{
				if (!dealer)
				{
					cout << name << endl;
					for (int i = 0; i < hand.size(); i++)
					{
						hand[i].Print();
					}

					cout << "1. A->1 2.A->11  :  "; cin >> ace;
					if (ace == 1)
					{
						jokbo += 1;
					}
					else if (ace == 2)
					{
						jokbo += 11;
					}
					else
					{
						cout << "�ٽ��ϱ�" << endl;
						i--;
						continue;
					}
				}
				else
				{
					jokbo += 11;
				}
			}
			else
			{
				jokbo += hand[i].number;
			}
		}
	}

	void Print(bool dealer = 0)
	{
		cout << "�̸� : " << name << endl;
		cout << "�� :" << "\t";
		for (int i = 0; i < hand.size(); i++)
		{
			hand[i].Print();
		}

		cout << "�� : " << jokbo << endl;

		if (!dealer)
		{
			cout << endl << "������ : " << gold << endl;
		}
	}
};

Trump MakeDeck(int number, string shape)
{
	Trump temp;
	temp.number = number;
	temp.shape = shape;

	return temp;
}

void Swap(int sour, int dest, vector<Trump>& deck)
{
	Trump temp = deck[sour];
	deck[sour] = deck[dest];
	deck[dest] = temp;
}

void Shuffle(vector<Trump>& deck)
{
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % (52 * DECKSIZE);
		int dest = rand() % (52 * DECKSIZE);

		Swap(sour, dest, deck);
	}
}

int main()
{
	srand(time(NULL));

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
		Shuffle(deck);
		index = 0;

		cout << endl << "==================���� ��==================" << endl;

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
					cout << players[i].name << "�¸�!" << endl;
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
					cout << players[i].name << "�¸�!" << endl;
					players[i].gold += 1000;
				}
				else
				{
					cout << players[i].name << "�й�" << endl;
					players[i].gold -= 1000;
				}
			}
		}
	}

	/*for (int i = 0; i < deck.size(); i++)
	{
		deck[i].Print();
	}*/

	return 0;
}