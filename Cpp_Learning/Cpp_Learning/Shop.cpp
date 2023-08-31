#include "stdafx.h"

void Shop::PlayShop()
{
	items[0] = new Item("의미 없는 아이템들이다아아  ", 300);
	items[1] = new Item("상점 지금 오류 있습니다. 나중에 고칠 예정입니다. ", 100);
	items[2] = new Weapon("게이밍 소드", 2000, 100);
	items[3] = new Weapon("망치 나가신다", 5000, 1);
	items[4] = new Armor("게임하고 싶다", 2000, 30);
	items[5] = new Armor("아머드 코어 재밌다던데", 3000, 70);

	//items[0]->Add();

	gold = 10000;

	while (true)
	{
		cout << "소지금 : " << gold << endl;
		cout << "1. 구매 2. 판매"; cin >> input;

		if (input == 1) //구매
		{
			//상점 목록
			for (int i = 0; i < 6; i++)
			{
				cout << i << " ";
				items[i]->Print();
			}

			cout << "구매할 물품의 번호를 입력 : "; cin >> input;

			//얕은 복사
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
		else //판매
		{
			//인벤
			for (int i = 0; i < inven.size(); i++)
			{
				cout << i << " ";
				inven[i]->Print();
			}

			cout << "판매할 물품의 번호를 입력 : "; cin >> input;

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


	//다운캐스팅 명시가 필요!
	//delete (Weapon*)items[2];
	//delete (Weapon*)items[3];
	//delete (Armor*)items[4];

	for (int i = 0; i < 6; i++)
	{
		delete items[i];
	}
}
