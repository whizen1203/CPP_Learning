#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//덱 소지금 베팅금액 
	int gold, bet;
	int deck[52];
	int count = 0;
	gold = 50000;

	//덱 만들기
	for (int i = 0; i < 52; i++)
	{
		deck[i] = i % 13 + 1; // 1 2 3 ... 13 1 2 3 ... 13
		//deck[i] = i / 4 + 1; // 1 1 1 1 2 2 2 2 3 3 3 3 ....
	}

	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 13; j++)
	//	{
	//		deck[i * 13 + j] = j + 1;
	//	}
	//}

	//덱 섞기 - 셔플
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % 52;
		int dest = rand() % 52;

		int temp = deck[sour];
		deck[sour] = deck[dest];
		deck[dest] = temp;
	}

	/*for (int i = 0; i < 52; i++)
	{
		cout << deck[i] << endl;
	}*/

	while (true)
	{
		//정렬
		if (deck[count] > deck[count + 1])
		{
			int temp = deck[count];
			deck[count] = deck[count + 1];
			deck[count + 1] = temp;
		}

		//세장 뽑기
		cout << deck[count] << " , " << deck[count + 1] << " , ?" << endl;

		cout << "소지금 : " << gold << endl;
		//베팅
		cout << "베팅금액 : ";  cin >> bet;

		if (bet < 1000 || bet > gold)
		{
			cout << "다시 입력!!!!!!!!! *\\ /* " << endl;
			continue;
		}

		//히든카드 판별 //금액 정산
		if (deck[count] < deck[count + 2] && deck[count + 2] < deck[count + 1])
		{
			cout << "승리~" << endl;
			gold += (bet * 2);
		}
		else
		{
			cout << "ㅋ패배ㅋ" << endl;
			gold -= bet;
		}

		//히든카드 출력
		cout << "히든카드 : " << deck[count + 2] << endl;
		cout << "==========================================" << endl;

		count += 3;

		if (count >= 51 || gold < 1000)
		{
			cout << "게임 끝" << endl;
			break;
		}
	}

	int exit;
	cin >> exit;
}