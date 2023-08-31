#include <iostream>
#include <vector> //c++ 라이브러리
//#include <time.h> C스타일 라이브러리

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
	//	  자료형 이름
	vector<int> vec;
	vec.reserve(10);
	//vec.resize(10, 2);
	//vec.push_back(10);
	//vec.push_back(11);

	//vec[0] = 10;
	//cout << vec[0] << endl;

	vec.push_back(0);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(1);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(2);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(3);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(4);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(5);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(6);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(7);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	vec.push_back(8);
	cout << "벡터의 크기 : " << vec.size() << endl;
	cout << "벡터의 내부크기 : " << vec.capacity() << endl;

	return 0;
}