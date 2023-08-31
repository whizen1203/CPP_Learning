#include "stdafx.h"

void Player::MakeJokbo(bool dealer)
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
					cout << "�ٽ���" << endl;
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

void  Player::Print(bool dealer)
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
		cout << "������ : " << gold << endl;
	}
}