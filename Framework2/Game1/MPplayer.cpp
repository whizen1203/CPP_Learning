#include "stdafx.h"

MPplayer::MPplayer()
{
	col = new ObRect();
	run = new ObImage(L"MPrun.png");
	jump = new ObImage(L"MPjump.png");
	att = new ObImage(L"MPattack.png");

	col->scale = Vector2(run->imgSize.x / 6.0f, run->imgSize.y) * 0.3f;
	col->isFilled = false;
	col->pivot = OFFSET_B;

	run->scale = Vector2(run->imgSize.x / 6.0f, run->imgSize.y) * 0.5f;
	run->SetParentRT(*col);
	run->pivot = OFFSET_B;
	run->maxFrame.x = 6;

	jump->scale = Vector2(jump->imgSize.x / 2.0f, jump->imgSize.y) * 0.6f;
	jump->SetParentRT(*col);
	jump->pivot = OFFSET_B;
	jump->maxFrame.x = 2; 
	jump->isVisible = false;

	att->scale = Vector2(att->imgSize.x / 12.0f, att->imgSize.y) * 0.7f;
	att->SetParentRT(*col);
	att->pivot = OFFSET_B;
	att->maxFrame.x = 12;
	att->isVisible = false;

	state = PState::IDLE;
	gravity = 0.0f;
	isDoubleJump = false;
	timer = 0.0f;

	damage = 5;
	isDamaging = false;
}

MPplayer::~MPplayer()
{
	SafeDelete(col);
	SafeDelete(run);
	SafeDelete(jump);
	SafeDelete(att);
}

void MPplayer::Update()
{
	switch (state)
	{
	case PState::IDLE:
		Idle();
		break;
	case PState::MOVE:
		Move();
		break;
	case PState::JUMP:
		Jump();
		break;
	case PState::ATT:
		Attack();
		break;
	}

	Vector2 velocity = moveDir * 300.0f + DOWN * gravity;
	col->MoveWorldPos(velocity * DELTA);
	gravity += 300.0f * DELTA;

	if (isDamaging)
	{
		run->color.w = RANDOM->Float(0.0f, 0.5f);
		jump->color.w = RANDOM->Float(0.0f, 0.5f);
		att->color.w = RANDOM->Float(0.0f, 0.5f);

		if (TIMER->GetTick(timer2, 0.5f))
		{
			run->color.w = 0.5f;
			jump->color.w = 0.5f;
			att->color.w = 0.5f;
			isDamaging = false;
		}
	}

	col->Update();
	run->Update();
	jump->Update();
	att->Update();
}

void MPplayer::Render()
{
	col->Render();
	run->Render();
	jump->Render();
	att->Render();
}

void MPplayer::Idle()
{
	//gravity = 0.0f;
	Input();

	//move
	if (moveDir.x != 0.0f)
	{
		state = PState::MOVE;
		run->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	//jump
	if (INPUT->KeyDown(VK_SPACE))
	{
		state = PState::JUMP;
		gravity = -300.0f;
		jump->isVisible = true;
		run->isVisible = false;
		jump->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	//att
	if (INPUT->KeyDown('K'))
	{
		state = PState::ATT;
		att->isVisible = true;
		run->isVisible = false;
		att->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	}
}

void MPplayer::Move()
{
	//gravity = 0.0f;
	Input();

	//idle
	if (moveDir.x == 0.0f)
	{
		state = PState::IDLE;
		run->frame.x = 0;
		run->ChangeAnim(ANIMSTATE::STOP, 0.1f);
	}

	//jump
	if (INPUT->KeyDown(VK_SPACE))
	{
		state = PState::JUMP;
		gravity = -300.0f;
		jump->isVisible = true;
		run->isVisible = false;
		jump->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}

	//att
	if (INPUT->KeyDown('K'))
	{
		state = PState::ATT;
		att->isVisible = true;
		run->isVisible = false;
		att->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	}
}

void MPplayer::Jump()
{
	Input();
	
	if (!isDoubleJump && INPUT->KeyDown(VK_SPACE))
	{
		gravity = -300.0f;
		jump->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		isDoubleJump = true;
	}

	//att
	if (INPUT->KeyDown('K'))
	{
		state = PState::ATT;
		att->isVisible = true;
		jump->isVisible = false;
		att->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	}
}

void MPplayer::Attack()
{
	Input();

	//idle
	if (TIMER->GetTick(timer, 1.2f))
	{
		state = PState::IDLE;
		run->isVisible = true;
		att->isVisible = false;
		run->ChangeAnim(ANIMSTATE::STOP, 0.1f);
		run->frame.x = 0;
		//col->colOnOff = true;
		targetCol = true;
	}
}

void MPplayer::JumpToIdle()
{
	state = PState::IDLE;
	jump->isVisible = false;
	run->isVisible = true;
	run->frame.x = 0;
	run->ChangeAnim(ANIMSTATE::STOP, 0.1f);
	isDoubleJump = false;
}

void MPplayer::Input()
{
	moveDir = Vector2(0.0f, 0.0f);

	if (INPUT->KeyPress('A'))
	{
		run->reverseLR = false;
		jump->reverseLR = false;
		att->reverseLR = false;
		moveDir.x = -1.0f;
	}
	if (INPUT->KeyPress('D'))
	{
		run->reverseLR = true;
		jump->reverseLR = true;
		att->reverseLR = true;
		moveDir.x = 1.0f;
	}
}

void MPplayer::TakeDamage(int damage)
{
	isDamaging = true;

	//hp -= damage;

	/*if (hp < 0)
	{

	}*/
}
