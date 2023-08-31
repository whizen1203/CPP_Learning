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

	//������ �����ε�
	Item(string _name);
	Item(int _price);
	Item(string _name, int _price);
	Item(const Item& src); //���������

	// �����Լ� : �����ǰ� �ʿ��� �� ���
	// �ڽ�Ŭ�������� �����ǰ� �Ͼ ���̶�� ������ ��
	virtual void Print();
	virtual Item* Create();

	//static void Add();

	/*void Print()
	{
		cout << this->name << endl;
	}*/

	//�Ҹ���
	//���� �Ҹ��� : �ڱ� �͵� �� �����ϱ� ���ؼ� -> �����Լ�������
	virtual ~Item();
};

//��� 
//Weapon�� Item�� ��ӹ޴´�.
//�θ�Ŭ���� Item. �ڽ�Ŭ���� Weapon
class Weapon : public Item
{
public:
	int att;

	Weapon();
	Weapon(string _name, int _price, int _att);
	Weapon(const Weapon& src);

	~Weapon() override;

	//override ������ Ű����
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

