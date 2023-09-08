#pragma once
class GameObject
{
public:
	Vector2 position; //중점
	Vector2 scale; //크기
	float ratation;

	GameObject();
	virtual ~GameObject();

	virtual void Render();
};

