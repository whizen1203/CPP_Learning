#include "stdafx.h"

void MakeJokbo(int size, SeotdaPlayer* player)
{
	for (int i = 0; i < size; i++)
	{
		//��
		if (player[i].card[0].month == player[i].card[1].month)
		{
			//												10
			player[i].jokbo = player[i].card[0].month + (DD1 - 1);
		}
		else if (player[i].card[0].shape == "��" &&
			player[i].card[1].shape == "��") //����
		{
			player[i].jokbo = KDD;
		}
		else //��
		{
			player[i].jokbo = KK0 + (player[i].card[0].month
				+ player[i].card[1].month) % 10;
		}
	}
}

int PlaySeotda()
{
	int size;

	//�÷��̾� �� �Է� Ȯ��
	while (true)
	{
		cout << "�÷��̾� �� �Է� : "; cin >> size;

		if (size < 2 || size > 10)
		{
			cout << "�÷��̾� �� �ٽ� �Է�!!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}

	//�÷��̾� �����
	SeotdaPlayer* player = new SeotdaPlayer[size];

	for (int i = 0; i < size; i++)
	{
		string name;
		cout << i + 1 << "��° �÷��̾� �̸� : "; cin >> name;
		player[i].name = name;
		player[i].gold = 50000;
	}

	//ī�� �����
	Card deck[CardNum];

	for (int i = 0; i < CardNum; i++)
	{
		deck[i].month = i % 10 + 1;
		deck[i].shape = "��";
	}
	deck[0].shape = deck[2].shape = deck[7].shape = "��";

	int start = 1;
	while (start)
	{
		Shuffle(deck, 20, 1000);

		//�� ������
		for (int i = 0; i < size; i++)
		{
			player[i].card[0] = deck[i];
			player[i].card[1] = deck[i + 10];
		}

		//�÷��̾� ���� �����
		MakeJokbo(size, player);


		//���� ����
		int max = KK0;
		for (int i = 0; i < size; i++)
		{
			if (max < player[i].jokbo)
			{
				max = player[i].jokbo;
			}
		}

		cout << max << endl;


		//���
		for (int i = 0; i < size; i++)
		{
			player[i].Print();
		}



		cout << "�� : 0 , �� �� ��� -> "; cin >> start;
	}

	return 0;
}