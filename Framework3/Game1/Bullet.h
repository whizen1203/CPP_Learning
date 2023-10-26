#pragma once
class Bullet
{
public:
	ObLine*		missile;
	ObCircle*	missilePet;

	Vector2		fireDir;
	float		scalar;
	float		gravity;

public:
	Bullet();
	~Bullet();
	void Update(ObRect player);
	void LateUpdate();
	void Render();
	bool Shoot(Vector2 fireDir, Vector2 firePos, float scalar);
};

