#include "stdafx.h"

void MakeJokbo(int size, SeotdaPlayer* player)
{
	for (int i = 0; i < size; i++)
	{
		//땡
		if (player[i].card[0].month == player[i].card[1].month)
		{
			//												10
			player[i].jokbo = player[i].card[0].month + (DD1 - 1);
		}
		else if (player[i].card[0].shape == "光" &&
			player[i].card[1].shape == "光") //광땡
		{
			player[i].jokbo = KDD;
		}
		else //끗
		{
			player[i].jokbo = KK0 + (player[i].card[0].month
				+ player[i].card[1].month) % 10;
		}
	}
}

int PlaySeotda()
{
	int size;

	//플레이어 수 입력 확인
	while (true)
	{
		cout << "플레이어 수 입력 : "; cin >> size;

		if (size < 2 || size > 10)
		{
			cout << "플레이어 수 다시 입력!!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}

	//플레이어 만들기
	SeotdaPlayer* player = new SeotdaPlayer[size];

	for (int i = 0; i < size; i++)
	{
		string name;
		cout << i + 1 << "번째 플레이어 이름 : "; cin >> name;
		player[i].name = name;
		player[i].gold = 50000;
	}

	//카드 만들기
	Card deck[CardNum];

	for (int i = 0; i < CardNum; i++)
	{
		deck[i].month = i % 10 + 1;
		deck[i].shape = "月";
	}
	deck[0].shape = deck[2].shape = deck[7].shape = "光";

	int start = 1;
	while (start)
	{
		Shuffle(deck, 20, 1000);

		//패 나누기
		for (int i = 0; i < size; i++)
		{
			player[i].card[0] = deck[i];
			player[i].card[1] = deck[i + 10];
		}

		//플레이어 족보 만들기
		MakeJokbo(size, player);


		//족보 승패
		int max = KK0;
		for (int i = 0; i < size; i++)
		{
			if (max < player[i].jokbo)
			{
				max = player[i].jokbo;
			}
		}

		cout << max << endl;


		//출력
		for (int i = 0; i < size; i++)
		{
			player[i].Print();
		}



		cout << "끝 : 0 , 그 외 계속 -> "; cin >> start;
	}

	return 0;
}