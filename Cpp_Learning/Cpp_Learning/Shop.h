#pragma once
class Shop
{
public:
	int input;

	int gold;
	Item* items[6];
	//추상화 <-> 구체화
	//업캐스팅

	vector<Item*> inven;

public:
	void PlayShop();
};

