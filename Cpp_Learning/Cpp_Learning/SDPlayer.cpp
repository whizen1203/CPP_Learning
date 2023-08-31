#include "stdafx.h"

void SeotdaPlayer::Print()
{
	cout << name << "\t" <<
		card[0].month << card[0].shape << "\t" <<
		card[1].month << card[1].shape << "\t" <<
		gold << "\t";

	if (jokbo == KDD)
	{
		cout << "±¤¶¯" << endl;
	}
	else if (jokbo > KK9)
	{
		cout << (jokbo - 10) << "¶¯" << endl;
	}
	else
	{
		cout << jokbo << "²ý" << endl;
	}
}
