#pragma once
class Bullet
{
public:
	ObLine arrow;
	bool isFired;
	float scalar;
	Vector2 fireDir;

	float gravity;

	Bullet();
	~Bullet();

	void Update(ObRect player);
	void LateUpdate();
	void Render();

	bool Shoot(ObRect player, float gaugeScale, Vector2 pos);
};

