#include <iostream>

using namespace std;

//�ݺ���
int main()
{

	//cin >> a;

	// while ~���ȿ�
	// ������ true �� �� �ݺ�
	/*while (a > 10)
	{
		cout << "1" << endl;
	}*/

	//���ѷ���

	//cout << a << endl;
	//cout << a-- << endl;
	//cout << a << endl;

	//bool b; // 1 0

	int a = 10;
	//�������� -> &&(and) ||(or)  

	//&&(and) �׸��� -> �� �� �� �̿��߸� ��
	// 1 && 1 -> 1
	// 1 && 0 -> 0
	// 0 && 1 -> 0
	// 0 && 0 -> 0

	//||(or) �Ǵ� -> �ϳ��� ���̸� ��
	// 1 || 1 -> 1
	// 1 || 0 -> 1
	// 0 || 1 -> 1
	// 0 || 0 -> 0

	cout << ((5 > 3) && (5 < 3)) << endl;
	cout << ((5 > 3) && (5 > 3)) << endl;
	cout << ((5 > 3) || (5 > 3)) << endl;
	cout << ((5 > 3) || (5 < 3)) << endl;
}