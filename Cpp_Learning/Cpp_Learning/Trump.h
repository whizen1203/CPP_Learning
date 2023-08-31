#pragma once
enum Shape
{
	DIA,
	HEART,
	SPADE,
	CLOVER
};

enum NUM
{
	A = 1,
	J = 11,
	Q,
	K
};

struct Trump
{
	string	shape;
	int		number;

	void Print();
};

