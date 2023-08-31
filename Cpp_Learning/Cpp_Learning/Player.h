#pragma once

struct Player
{
	string			name;
	int				gold;
	vector<Trump>	hand;
	int				jokbo;
	bool			win;

	void MakeJokbo(bool dealer = 0);
	void Print(bool dealer = 0);
};

