#include "stdafx.h"

MPMon::MPMon()
{
	col = new ObRect();
	move = new ObImage(L"MPmon.png");
	die = new ObImage(L"MPmonDie.png");

	col->scale = Vector2(move->imgSize.x / 5.0f, move->imgSize.y) * 0.3f;
	col->isFilled = false;
	col->pivot = OFFSET_B;

	move->scale = Vector2(move->imgSize.x / 5.0f, move->imgSize.y) * 0.5f;
	move->SetParentRT(*col);
	move->pivot = OFFSET_B;
	move->maxFrame.x = 5;
	move->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	die->scale = Vector2(die->imgSize.x / 4.0f, die->imgSize.y) * 0.5f;
	die->SetParentRT(*col);
	die->pivot = OFFSET_B;
	die->maxFrame.x = 4;
	die->isVisible = false;

	range = new ObCircle();
	range->scale = Vector2(500.0f, 500.0f);
	range->isFilled = false;

	moveDir.x = (float)RandomDir();

	damage = 1;
	hp = 10;
	timer = 0.0f;
	state = MState::MOVE;
}

MPMon::~MPMon()
{
	SafeDelete(col);
	SafeDelete(move);
	SafeDelete(die);
	SafeDelete(range);
}

void MPMon::Update()
{
	ReverseFlip();

	switch (state)
	{
	case MState::MOVE:
		Move();
		break;
	case MState::DIE:
		Die();
		break;
	}

	col->MoveWorldPos(moveDir * 200.0f * DELTA);

	col->Update();
	move->Update();
	die->Update();
	range->Update();
}

void MPMon::Render()
{
	col->Render();
	range->Render();
	move->Render();
	die->Render();
}

int MPMon::RandomDir()
{
	int ran;
	ran = RANDOM->Int(-1, 1);
	while (ran == 0)
	{
		ran = RANDOM->Int(-1, 1);
	}

	return ran;
}

void MPMon::ReverseFlip()
{
	if (moveDir.x < 0)
	{
		move->reverseLR = false;
		die->reverseLR = false;
	}
	else
	{
		move->reverseLR = true;
		die->reverseLR = true;
	}
}

void MPMon::Move()
{
	//¿ÞÂÊ
	if ((range->GetWorldPos().x - range->scale.x * 0.5f) > col->GetWorldPos().x)
	{
		moveDir.x *= -1.0f;
	}
	else if ((range->GetWorldPos().x + range->scale.x * 0.5f) < col->GetWorldPos().x)
	{
		moveDir.x *= -1.0f;
	}
}

void MPMon::Die()
{
	die->color.w -= 0.5f * DELTA;

	if (die->color.w < 0.0f)
	{
		die->isVisible = false;
		col->isVisible = false;
		col->SetWorldPos(Vector2(2000.0f, 2000.0f));
	}
}

void MPMon::TakeDamage(int damage)
{
	hp -= damage;

	if (hp <= 0)
	{
		state = MState::DIE;
		move->isVisible = false;
		die->isVisible = true;
		die->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	}
}
