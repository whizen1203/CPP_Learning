#include <iostream>
#include <vector> //c++ ���̺귯��
//#include <time.h> C��Ÿ�� ���̺귯��

using namespace std;

struct A
{
	int a;

	void Print()
	{

	}
};

int main()
{
	//	  �ڷ��� �̸�
	vector<int> vec;
	vec.reserve(10);
	//vec.resize(10, 2);
	//vec.push_back(10);
	//vec.push_back(11);

	//vec[0] = 10;
	//cout << vec[0] << endl;

	vec.push_back(0);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(1);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(2);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(3);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(4);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(5);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(6);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(7);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	vec.push_back(8);
	cout << "������ ũ�� : " << vec.size() << endl;
	cout << "������ ����ũ�� : " << vec.capacity() << endl;

	return 0;
}