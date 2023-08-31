#include <iostream>
#include <time.h>

using namespace std;

//
int main()
{
	srand(time(NULL));

	//카드뭉치 deck
	int deck[52];

	for (int i = 0; i < 52; i++)
	{
		deck[i] = i + 1;
		cout << deck[i] << endl;
	}

	cout << "=============================" << endl;

	//swap 알고리즘 - 서로 바꾸기
	/*deck[0] = deck[1];
	deck[1] = deck[0];*/ //deck[0] 값이 변경됨

	int temp = deck[0];
	deck[0] = deck[1];
	deck[1] = temp;

	//shuffle 셔플 알고리즘
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % 52;
		int dest = rand() % 52;

		int temp = deck[sour];
		deck[sour] = deck[dest];
		deck[dest] = temp;
	}

	cout << "*" << endl;
	cout << "**" << endl;
	cout << "***" << endl;

	int exit;
	cin >> exit;
}