#include <iostream>
#include <string>
#include <vector> //c++ ���̺귯��
//#include <time.h> C��Ÿ�� ���̺귯��

using namespace std;

struct Trump
{
	int number;
	string shape;

	void Print()
	{
		cout << shape << number << endl;
	}
};

Trump MakeDeck(int number, string shape)
{
	Trump temp;
	temp.number = number;
	temp.shape = shape;

	return temp;
}

int main()
{
	vector<Trump> deck;

	// 1. �ӽú����� �̿��ϴ� ���
	Trump temp;
	temp.number = 10;
	temp.shape = "��";

	deck.push_back(temp);
	//deck[0].number = ;

	//2. �Լ��� �̿��ϴ� ���
	deck.push_back(MakeDeck(5, "��"));

	//3. resize ��� �ε����� �����ؼ� �ʱ�ȭ

	//cout << deck.size() << endl;
	deck[0].Print();
	deck[1].Print();


	return 0;
}