#pragma once
class Item
{
private:

public:
	int		price;
	string	name;
	int		num;

public:
	Item();

	/*int temp;
	int& a;
	const int b;*/

	//생성자 오버로딩
	Item(string _name);
	Item(int _price);
	Item(string _name, int _price);
	Item(const Item& src); //복사생성자

	// 가상함수 : 재정의가 필요할 때 사용
	// 자식클래스에서 재정의가 일어날 것이라고 예상할 때
	virtual void Print();
	virtual Item* Create();

	//static void Add();

	/*void Print()
	{
		cout << this->name << endl;
	}*/

	//소멸자
	//가상 소멸자 : 자기 것도 잘 해제하기 위해서 -> 가상함수포인터
	virtual ~Item();
};

//상속 
//Weapon은 Item을 상속받는다.
//부모클래스 Item. 자식클래스 Weapon
class Weapon : public Item
{
public:
	int att;

	Weapon();
	Weapon(string _name, int _price, int _att);
	Weapon(const Weapon& src);

	~Weapon() override;

	//override 재정의 키워드
	void Print() override;
	Item* Create() override;
};

class Armor : public Item
{
public:
	int def;

	Armor();
	Armor(string _name, int _price, int _def);
	Armor(const Armor& src);

	~Armor();

	void Print() override;
	Item* Create() override;
};

