#pragma once
class GameObject
{
public:
	Vector2 position; //����
	Vector2 scale; //ũ��
	float ratation;

	GameObject();
	virtual ~GameObject();

	virtual void Render();
};

