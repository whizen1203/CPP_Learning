#include <iostream>
#include <string>

using namespace std;

//��ü�� '����Լ��� ����(������)'�� ����
//����ü		����
//type		��ü
//Trump		deck
//Player	player, dealer

//���� ������
//public : �ܺ� ���� ����, ����
//private : �ܺ� ���� �Ұ���, �����

struct Trump
{
	//struct �� �⺻���������� public
public: //private
	string shape;
	int number;

	void Print()
	{
		cout << number << endl;
	}
};

class Trump2
{
	//class �� �⺻���������� private
private: //public
	string shape;
	int number;

	void Print()
	{
		cout << number << endl;
	}
};

int main()
{
	Trump card1;
	card1.shape;
	card1.number;

	Trump2 card2;
	card2.shape;	//�̰� �� ����� �־�����? ���� ����� ���Ҵ� �����̴���?
	card2.Print();


	return 0;
}