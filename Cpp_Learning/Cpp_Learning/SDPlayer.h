#pragma once
enum Jokbo
{
	KK0,
	KK9 = 9,
	DD1 = 11,
	DD10 = 20,
	KDD
};

struct SeotdaPlayer
{
	string	name;
	int		gold;
	Card	card[2];
	int		jokbo;

	void Print();
};

