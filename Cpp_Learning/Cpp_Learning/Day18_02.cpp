#include <iostream>
#include <vector> //c++ ���̺귯��
//#include <time.h> C��Ÿ�� ���̺귯��

using namespace std;

int main()
{
	vector<int> vec;

	vec.push_back(3); //3�� �ڿ� �߰�
	vec.emplace_back(4); //4�� �ڿ� �߰�

	//insert : ���� ��ġ�� ����, �Ű������� iter
	vec.insert(vec.begin(), 10);
	//vec.insert(vec.begin() + 2, 10);

	//erase : ���� ��ġ ����, �Ű������� iter
	vec.erase(vec.begin());

	//begin : ��ȯ���� ó�� iter
	cout << *(vec.begin() + 1) << endl;

	//end : ��ȯ���� �� + 1 iter
	//cout << *vec.end() << endl;


	//front : ó�� ���� �� ��������
	vec.front() = 5;
	cout << vec.front() << endl;

	//back : ������ ���� �� ��������
	vec.back() = 10;
	cout << vec.back() << endl;

	//size -> �迭�� ũ��

	//resize -> �迭�� ���, �ʱ�ȭ
	vec.resize(10, 2); //10���� �迭�� 2�� �ʱ�ȭ
	vec.resize(10); //10���� �迭�� 0�� �ʱ�ȭ

	//reserve : ����ũ��

	//capacity //�迭�� ���� ũ��, ���� ����(���� �����ϴ� ����)

	//clear : �迭 ũ�� ����
	vec.clear();
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	//shrink_to_fit : �迭 ���ι��� ����
	vec.shrink_to_fit();
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	return 0;
}