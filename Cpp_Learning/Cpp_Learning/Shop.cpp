#include "stdafx.h"

void Shop::PlayShop()
{
	items[0] = new Item("�ǹ� ���� �����۵��̴پƾ�  ", 300);
	items[1] = new Item("���� ���� ���� �ֽ��ϴ�. ���߿� ��ĥ �����Դϴ�. ", 100);
	items[2] = new Weapon("���̹� �ҵ�", 2000, 100);
	items[3] = new Weapon("��ġ �����Ŵ�", 5000, 1);
	items[4] = new Armor("�����ϰ� �ʹ�", 2000, 30);
	items[5] = new Armor("�Ƹӵ� �ھ� ��մٴ���", 3000, 70);

	//items[0]->Add();

	gold = 10000;

	while (true)
	{
		cout << "������ : " << gold << endl;
		cout << "1. ���� 2. �Ǹ�"; cin >> input;

		if (input == 1) //����
		{
			//���� ���
			for (int i = 0; i < 6; i++)
			{
				cout << i << " ";
				items[i]->Print();
			}

			cout << "������ ��ǰ�� ��ȣ�� �Է� : "; cin >> input;

			//���� ����
			//inven.push_back(items[input]);

			/*Item item = Item("d", 10);
			Item item2 = Item(item);*/

			/*inven.push_back(new Item(*items[input]));
			inven.push_back(new Weapon(*items[input]));*/

			bool isChecking = false;
			for (int i = 0; i < inven.size(); i++)
			{
				if (inven[i]->name == items[input]->name)
				{
					inven[i]->num++;
					isChecking = true;
					break;
				}
			}

			if (!isChecking)
			{
				//inven.push_back(items[input]);
				inven.push_back(items[input]->Create());
			}
			gold -= items[input]->price;
		}
		else //�Ǹ�
		{
			//�κ�
			for (int i = 0; i < inven.size(); i++)
			{
				cout << i << " ";
				inven[i]->Print();
			}

			cout << "�Ǹ��� ��ǰ�� ��ȣ�� �Է� : "; cin >> input;

			gold += inven[input]->price;

			bool isChecking = false;
			for (int i = 0; i < inven.size(); i++)
			{
				if (inven[i]->name == items[input]->name)
				{
					inven[i]->num--;
					isChecking = true;
					break;
				}
			}

			if (inven[input]->num == 0)
			{
				delete inven[input];
				inven.erase(inven.begin() + input);
			}

		}
	}


	//�ٿ�ĳ���� ��ð� �ʿ�!
	//delete (Weapon*)items[2];
	//delete (Weapon*)items[3];
	//delete (Armor*)items[4];

	for (int i = 0; i < 6; i++)
	{
		delete items[i];
	}
}
