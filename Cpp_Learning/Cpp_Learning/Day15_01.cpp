#include <iostream>

using namespace std;

const char* str1 = "*****";
const char* str2 = "     ";

void PrintRT(int i)
{

	cout << str1 + (4 - i) << str2 + (i + 1);

}

void PrintRB(int i)
{

	cout << str1 + i << str2 + (5 - i);

}

void PrintLT(int i)
{

	cout << str2 + (i + 1) << str1 + (4 - i);

}

void PrintLB(int i)
{

	cout << str2 + (5 - i) << str1 + i;

}

int main()
{
	//PrintRT();
	//PrintRB();
	//PrintLB();
	//PrintLT();

	//양각 다이아몬드
	for (int i = 0; i < 5; i++)
	{
		PrintLT(i);
		PrintRT(i);

		cout << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		PrintLB(i);
		PrintRB(i);

		cout << endl;
	}

	//음각 다이아몬드

	for (int i = 0; i < 5; i++)
	{
		PrintRB(i);
		PrintLB(i);

		cout << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		PrintRT(i);
		PrintLT(i);

		cout << endl;
	}

	return 0;
}