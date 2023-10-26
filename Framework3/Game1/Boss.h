#pragma once
enum class B_State
{
	IDLE,
	LOOK = 300,
	MOVE = 200,
	ATTACK = 100
};

class Boss : public Character
{
public:
	ObImage*	img;
	ObCircle*	range[3];
	B_State		state;
	float		distance;
	bool		switching;

public:
	Boss();
	~Boss();
	void Update();
	void Render();

	void Idle();
	void Look();
	void Move();
	void Attack();
};

