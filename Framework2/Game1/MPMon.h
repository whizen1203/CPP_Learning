#pragma once
enum class MState
{
	MOVE,
	DIE
};

class MPMon
{
public:
	ObRect* col;
	ObImage* move;
	ObImage* die;
	ObCircle* range;

	Vector2 moveDir;
	int damage;
	int hp;
	float timer;

	MState state;
public:
	MPMon();
	~MPMon();
	void Update();
	void Render();

	int RandomDir();
	void ReverseFlip();

	void Move();
	void Die();

	void TakeDamage(int damage);
};

