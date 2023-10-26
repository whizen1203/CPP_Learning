#pragma once
enum Direction
{
	L,
	T,
	R,
	B,
	LT,
	RT,
	LB,
	RB
};

class Character
{
public:
	ObRect*		col;
	Direction	dir;
	Vector2		moveDir;
	int			frameY[8];
	Vector2		target;

public:
	void LookAtTarget(Vector2 target, ObImage* img);
};

