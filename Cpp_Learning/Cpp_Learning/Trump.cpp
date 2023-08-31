#include "stdafx.h"

void Trump::Print()
{
	switch (number)
	{
	case A:
		cout << shape << "A" << "\t";
		break;
	case J:
		cout << shape << "J" << "\t";
		break;
	case Q:
		cout << shape << "Q" << "\t";
		break;
	case K:
		cout << shape << "K" << "\t";
		break;
	default:
		cout << shape << number << "\t";
		break;
	}
}