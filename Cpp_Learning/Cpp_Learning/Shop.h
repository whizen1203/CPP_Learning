#pragma once
class Shop
{
public:
	int input;

	int gold;
	Item* items[6];
	//�߻�ȭ <-> ��üȭ
	//��ĳ����

	vector<Item*> inven;

public:
	void PlayShop();
};

