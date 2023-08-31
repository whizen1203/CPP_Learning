#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//�� ������ ���ñݾ� 
	int gold, bet;
	int deck[52];
	int count = 0;
	gold = 50000;

	//�� �����
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

	//�� ���� - ����
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
		//����
		if (deck[count] > deck[count + 1])
		{
			int temp = deck[count];
			deck[count] = deck[count + 1];
			deck[count + 1] = temp;
		}

		//���� �̱�
		cout << deck[count] << " , " << deck[count + 1] << " , ?" << endl;

		cout << "������ : " << gold << endl;
		//����
		cout << "���ñݾ� : ";  cin >> bet;

		if (bet < 1000 || bet > gold)
		{
			cout << "�ٽ� �Է�!!!!!!!!! *\\ /* " << endl;
			continue;
		}

		//����ī�� �Ǻ� //�ݾ� ����
		if (deck[count] < deck[count + 2] && deck[count + 2] < deck[count + 1])
		{
			cout << "�¸�~" << endl;
			gold += (bet * 2);
		}
		else
		{
			cout << "���й褻" << endl;
			gold -= bet;
		}

		//����ī�� ���
		cout << "����ī�� : " << deck[count + 2] << endl;
		cout << "==========================================" << endl;

		count += 3;

		if (count >= 51 || gold < 1000)
		{
			cout << "���� ��" << endl;
			break;
		}
	}

	int exit;
	cin >> exit;
}