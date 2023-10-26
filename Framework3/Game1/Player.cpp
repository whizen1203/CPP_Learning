#include "stdafx.h"

Player::Player()
{
	col = new ObRect;
	run = new ObImage(L"Walk.png");
	roll = new ObImage(L"Roll.png");

	col->scale = Vector2(run->imageSize.x / 6.0f, run->imageSize.y / 8.0f) * 6.0f;
	col->isFilled = false;
	col->SetWorldPosX(500.0f);

	run->scale = Vector2(run->imageSize.x / 6.0f, run->imageSize.y / 8.0f) * 6.0f;
	run->maxFrame = Int2(6, 8);
	run->SetParentRT(*col);

	roll->scale = Vector2(roll->imageSize.x / 6.0f, roll->imageSize.y / 8.0f) * 6.0f;
	roll->maxFrame = Int2(6, 8);
	roll->SetParentRT(*col);
	roll->isVisible = false;

	frameY[L] = 2;
	frameY[R] = 0;
	frameY[T] = 1;
	frameY[B] = 3;
	frameY[RB] = 4;
	frameY[LB] = 5;
	frameY[LT] = 6;
	frameY[RT] = 7;

	state = State::IDLE;
}

Player::~Player()
{
	SafeDelete(col);
	SafeDelete(run);
	SafeDelete(roll);
}

void Player::Update()
{
	lastPos = col->GetWorldPos();

	switch (state)
	{
	case State::IDLE:
		Idle();
		break;
	case State::MOVE:
		Move();
		break;
	case State::ROLL:
		Roll();
		break;
	}

	col->Update();
	run->Update();
	roll->Update();
}

void Player::Render()
{
	col->Render();
	run->Render();
	roll->Render();
}

void Player::Idle()
{
	LookAtTarget(INPUT->GetWorldMousePos(), run);
	Input();

	//move
	if (moveDir != Vector2(0.0f, 0.0f))
	{
		state = State::MOVE;
		run->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	}
}

void Player::Move()
{
	LookAtTarget(INPUT->GetWorldMousePos(), run);
	col->MoveWorldPos(moveDir * 200.0f * DELTA);
	Input();

	//idle
	if (moveDir == Vector2(0.0f, 0.0f))
	{
		state = State::IDLE;
		run->ChangeAnim(ANIMSTATE::STOP, 0.1f);
		run->frame.x = 0;
	}

	//roll
	if (INPUT->KeyDown(VK_SPACE))
	{
		state = State::ROLL;
		run->isVisible = false;
		roll->isVisible = true;
		roll->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		rollTime = 0.6f;
	}
}

void Player::Roll()
{
	Input();
	LookAtTarget(col->GetWorldPos() + moveDir, roll);
	col->MoveWorldPos(moveDir * 700.0f 
		* cosf(1.0f - rollTime / 0.6f * DIV2PI) *  DELTA);
	//					1 ~ 0
	//			0 ~ 1							-> 0 ~ 90

	//move
	rollTime -= DELTA;
	if (rollTime < 0.0f)
	{
		state = State::IDLE;
		run->isVisible = true;
		roll->isVisible = false;
	}
}

void Player::Input()
{
	moveDir = Vector2(0.0f, 0.0f);

	if (INPUT->KeyPress('W'))
	{
		moveDir.y = 1.0f;
	}
	else if (INPUT->KeyPress('S'))
	{
		moveDir.y = -1.0f;
	}

	if (INPUT->KeyPress('D'))
	{
		moveDir.x = 1.0f;
	}
	else if (INPUT->KeyPress('A'))
	{
		moveDir.x = -1.0f;
	}

	moveDir.Normalize();
}

void Player::StepBack()
{
	col->SetWorldPos(lastPos);
	col->Update();
}
