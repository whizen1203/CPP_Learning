#pragma once
//template 선언과 정의를 따로 둘 수 없음

//템플릿
template<typename T>
static void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
static void Shuffle(T& deck, int range, int shuffleCount)
{
	for (int i = 0; i < shuffleCount; i++)
	{
		int sour = rand() % range;
		int dest = rand() % range;

		Swap(deck[sour], deck[dest]);
	}
}