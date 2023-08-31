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
	//���� : �� ī��Ʈ ���ñݾ� ������ �Է°�(���̷ο켼��)

	gold = 50000;
	count = 0;

	//�� �����
	for (int i = 0; i < 52; i++)
	{
		deck[i].number = i % 13 + 1;

		switch (i / 13)
		{
		case DIA:
			deck[i].shape = "��";
			break;
		case HEART:
			deck[i].shape = "��";
			break;
		case SPADE:
			deck[i].shape = "��";
			break;
		case CLOVER:
			deck[i].shape = "��";
			break;
		}

		//cout << deck[i].shape << deck[i].number << endl;
	}

	//�� ����
	Shuffle();

	/*for (int i = 0; i < 52; i++)
	{
		cout << deck[i].shape << deck[i].number << endl;
	}*/

	while (true)
	{
		cout << "------------���� �ο� ����------------" << endl;

		//ī�� ���
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
		cout << "������ : " << gold << endl;

		//����
		cout << "���ñݾ� : "; cin >> betting;

		if (betting < 1000 || betting > gold)
		{
			cout << "����� �Է���" << endl;
			continue;
		}

		//���̷ο켼�� �Է�
		cout << "hi 1 / low 2 / seven 3 : "; cin >> input;

		//���� �Ǵ� - ������ ����
		if (input == 1) //����
		{
			if (deck[count + 5].number > 7)
			{
				cout << "��~��~" << endl;
				gold += betting;
			}
			else
			{
				cout << "��~��~" << endl;
				gold -= betting;
			}
		}
		else if (input == 2) //�ο�
		{
			if (deck[count + 5].number < 7)
			{
				cout << "��~��~" << endl;
				gold += betting;
			}
			else
			{
				cout << "��~��~" << endl;
				gold -= betting;
			}
		}
		else if (input == 3) // ����
		{
			if (deck[count + 5].number == 7)
			{
				cout << "��~��~" << endl;
				gold += (betting * 7);
			}
			else
			{
				cout << "��~��~" << endl;
				gold -= betting;
			}
		}
		else
		{
			cout << "����� �Է���" << endl;
			continue;
		}

		cout << "���� ī�� : ";
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
			cout << "ī�� ���� " << endl;
			//break;

			Shuffle();
			count = 0;
		}
	}

	int exit;
	cin >> exit;
}