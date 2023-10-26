#include "stdafx.h"

Boss::Boss()
{
	col = new ObRect;
	img = new ObImage(L"boss.bmp");

	col->scale = Vector2(img->imageSize.x, img->imageSize.y / 8.0f);
	col->isFilled = false;

	img->scale = Vector2(img->imageSize.x, img->imageSize.y / 8.0f);
	img->SetParentRT(*col);
	img->maxFrame.y = 8;

	for (int i = 0; i < 3; i++)
	{
		range[i] = new ObCircle;
		range[i]->isFilled = false;
		range[i]->SetParentRT(*col);
	}

	float scale = (int)B_State::LOOK * 2.0f;
	range[0]->scale = Vector2(scale, scale);

	scale = (int)B_State::MOVE * 2.0f;
	range[1]->scale = Vector2(scale, scale);

	scale = (int)B_State::ATTACK * 2.0f;
	range[2]->scale = Vector2(scale, scale);

	frameY[L] = 1;
	frameY[R] = 0;
	frameY[T] = 4;
	frameY[B] = 5;
	frameY[RB] = 2;
	frameY[LB] = 6;
	frameY[LT] = 3;
	frameY[RT] = 7;

	state = B_State::IDLE;

	switching = false;
}

Boss::~Boss()
{
	SafeDelete(col);
	SafeDelete(img);
	for (int i = 0; i < 3; i++)
	{
		SafeDelete(range[i]);
	}

}

void Boss::Update()
{
	moveDir = target - col->GetWorldPos();
	distance = moveDir.Length();

	switch (state)
	{
	case B_State::IDLE:
		Idle();
		break;
	case B_State::LOOK:
		Look();
		break;
	case B_State::MOVE:
		Move();
		break;
	case B_State::ATTACK:
		Attack();
		break;
	}

	col->Update();
	img->Update();
	for (int i = 0; i < 3; i++)
	{
		range[i]->Update();
	}
}

void Boss::Render()
{
	col->Render();	
	for (int i = 0; i < 3; i++)
	{
		range[i]->Render();
	}
	img->Render();
}

void Boss::Idle()
{
	//Look
	if (distance < (int)B_State::LOOK)
	{
		state = B_State::LOOK;
	}
}

void Boss::Look()
{
	LookAtTarget(target, img);

	//move
	if (distance < (int)B_State::MOVE)
	{
		state = B_State::MOVE;
	}

	//idle
	if (distance > (int)B_State::LOOK)
	{
		state = B_State::IDLE;
	}
}

void Boss::Move()
{
	LookAtTarget(target, img);
	moveDir.Normalize();
	col->MoveWorldPos(moveDir * 100.0f * DELTA);

	//attack
	if (distance < (int)B_State::ATTACK)
	{
		state = B_State::ATTACK;
	}

	//look
	if (distance > (int)B_State::MOVE)
	{
		state = B_State::LOOK;
	}
}

void Boss::Attack()
{
	LookAtTarget(target, img);

	float temp = 1.0f;

	if (switching) temp = 1.0f;
	else temp = -1.0f;

	img->scale.x += temp * 200.0f * DELTA;
	img->scale.y -= temp * 200.0f * DELTA;

	if (img->scale.x < 50.0f || img->scale.y < 50.0f)
	{
		switching = !switching;
	}

	//move
	if (distance > (int)B_State::ATTACK)
	{
		state = B_State::MOVE;
		img->scale = Vector2(img->imageSize.x, img->imageSize.y / 8.0f);
	}
}
