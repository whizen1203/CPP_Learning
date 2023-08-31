#include "stdafx.h"

Item::Item()
{
	cout << "������ ����" << endl;
}

// : ����̴ϼȶ�����
Item::Item(string _name)
	: name(_name), num(1)
{
	//cout << "������ ����" << endl;
	//name = _name;
	//a = temp;
}

Item::Item(int _price)
	: price(_price), num(1)
{
	//cout << "������ ����" << endl;
	//price = _price;
}

Item::Item(string _name, int _price)
	: name(_name), price(_price), num(1)
{
	//cout << "������ ����" << endl;
	//name = _name;
	//price = _price;
}

Item::Item(const Item& src)
{
	this->name = src.name;
	this->price = src.price;
	num = src.num;
}

void Item::Print()
{
	cout << name << "\t" << price << "\t" << num << endl;
}

Item* Item::Create()
{
	return new Item(*this);
}

//void Item::Add()
//{
//	this->num++;
//}

Item::~Item()
{
	cout << "�Ҹ��� ����" << endl;
}

Weapon::Weapon()
{
	//cout << "���� ����" << endl;
}

Weapon::Weapon(string _name, int _price, int _att)
	: Item(_name, _price), att(_att)
{
	/*cout << "���� ����" << endl;
	name = _name;
	price = _price;
	att = _att;*/
}

Weapon::Weapon(const Weapon& src)
{
	name = src.name;
	price = src.price;
	att = src.att;
	num = src.num;
}

Weapon::~Weapon()
{
	cout << "���� �Ҹ�" << endl;
}

void Weapon::Print()
{
	cout << name << "\t" << price << "\t" << att <<
		"\t" << num << endl;
}

Item* Weapon::Create()
{
	return new Weapon(*this);
}

Armor::Armor()
{
	//cout << "�� ����" << endl;
}

Armor::Armor(string _name, int _price, int _def)
	: Item(_name, _price), def(_def)
{
	/*cout << "�� ����" << endl;
	name = _name;
	price = _price;
	def = _def;*/
}

Armor::Armor(const Armor& src)
{
	name = src.name;
	price = src.price;
	def = src.def;
	num = src.num;
}

Armor::~Armor()
{
	cout << "�� �Ҹ�" << endl;
}

void Armor::Print()
{
	cout << name << "\t" << price << "\t"
		<< def << "\t" << num << endl;
}

Item* Armor::Create()
{
	return new Armor(*this);
}
