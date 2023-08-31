#include "stdafx.h"

int main()
{
	srand(time(NULL));

	int input;
	Shop shop;
	//Shop A = Shop(shop);

	while (true)
	{
		cout << "플레이할 게임을 선택해주세요 ①블랙잭 ②섯다 ③상점";
		cin >> input;

		if (input == 1)
		{
			PlayBlackJack();
			break;
		}
		else if (input == 2)
		{
			PlaySeotda();
			break;
		}
		else if (input == 3)
		{
			shop.PlayShop();
			break;
		}
		else
		{
			cout << "다시 선택해주세요!" << endl;
			continue;
		}
	}

	int exit;
	cin >> exit;


	return 0;
}