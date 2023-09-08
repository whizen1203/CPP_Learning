#include "framework.h"

ObLine* GameObject::axis = nullptr;

GameObject::GameObject()
{
	position.x = 0.0f;
	position.y = 0.0f;
	scale.x = 1.0f;
	scale.y = 1.0f;
	rotation = 0.0f;
	revolution = 0.0f;

	isAxis = false;
	P = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	S = Matrix::CreateScale(scale.x, scale.y, 1.0f);
	R = Matrix::CreateRotationZ(rotation);
	R2 = Matrix::CreateRotationZ(revolution);
	T = Matrix::CreateTranslation(position.x, position.y, 0.0f);

	RT = R * T * R2;

	if (P)
	{
		RT *= *P;
	}

	W = S * RT;
}

void GameObject::Render()
{
	if (isAxis)
	{
		//xÃà
		axis->position = GetWorldPos();
		axis->rotation = DirToRadian(GetRight());
		axis->scale.x = scale.x;
		axis->Update();
		axis->Render();

		//yÃà
		axis->position = GetWorldPos();
		axis->rotation = DirToRadian(GetDown());
		axis->scale.x = scale.y;
		axis->Update();
		axis->Render();
	}
}

void GameObject::CreateStatic()
{
	axis = new ObLine();
}

void GameObject::DeleteStatic()
{
	delete axis;
}
