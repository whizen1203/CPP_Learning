#include "stdafx.h"

int main()
{
	srand(time(NULL));

	int input;
	Shop shop;
	//Shop A = Shop(shop);

	while (true)
	{
		cout << "�÷����� ������ �������ּ��� ����� �輸�� �����";
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
			cout << "�ٽ� �������ּ���!" << endl;
			continue;
		}
	}

	int exit;
	cin >> exit;


	return 0;
}