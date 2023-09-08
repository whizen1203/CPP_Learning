#include "framework.h"

GameObject::GameObject()
{
	position.x = 0.0f;
	position.y = 0.0f;
	scale.x = 1.0f;
	scale.y = 1.0f;
	ratation = 0.0f;
}

GameObject::~GameObject()
{
}

void GameObject::Render()
{
}
