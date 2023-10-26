#include "stdafx.h"

Cookie::Cookie()
{
	col = new ObRect;
	col->scale = Vector2(150.0f, 200.0f);
	col->SetWorldPosX(-260.0f);
	col->SetWorldPosY(-app.GetHalfHeight() + 140.0f);
	col->pivot = OFFSET_B;
	col->isFilled = false;

	run = new ObImage(L"C_run.png");
	run->scale = Vector2(run->imageSize.x / 4.0f, run->imageSize.y);
	run->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	run->maxFrame.x = 4;
	run->SetParentRT(*col);
	run->pivot = OFFSET_B;

	slide = new ObImage(L"C_slide.png");
	slide->scale = Vector2(slide->imageSize.x / 5.0f, slide->imageSize.y);
	//slide->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	slide->maxFrame.x = 5;
	slide->SetParentRT(*col);
	slide->pivot = OFFSET_B;
	slide->isVisible = false;

	jump = new ObImage(L"C_jump2.png");
	jump->scale = Vector2(jump->imageSize.x / 8.0f, jump->imageSize.y);
	jump->maxFrame.x = 8;
	jump->SetParentRT(*col);
	jump->pivot = OFFSET_B;
	jump->isVisible = false;
	jump->color = Color(0.5f, 0.0f, 0.0f, 0.5f);

	landing = new ObImage(L"C_landing.png");
	landing->scale = Vector2(landing->imageSize.x / 2.0f, landing->imageSize.y);
	landing->maxFrame.x = 2;
	landing->SetParentRT(*col);
	landing->pivot = OFFSET_B;
	landing->isVisible = false;

	state = CState::RUN;
	doubleJump = false;
}

Cookie::~Cookie()
{
	SafeDelete(run);
	SafeDelete(col);
	SafeDelete(slide);
	SafeDelete(jump);
	SafeDelete(landing);
}

void Cookie::Update()
{
	if (state == CState::RUN)
	{
		col->scale.y = 200.0f;
		gravity = 0.0f;

		//run -> slide
		if (INPUT->KeyPress(VK_DOWN))
		{
			state = CState::SLIDE;
			slide->isVisible = true;
			run->isVisible = false;
			slide->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		}

		//run -> jump
		if (INPUT->KeyDown(VK_SPACE))
		{
			state = CState::JUMP;
			jump->isVisible = true;
			run->isVisible = false;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			landing->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

			gravity = -200.0f;
		}
	}
	else if (state == CState::SLIDE)
	{
		col->scale.y = 100.0f;
		gravity = 0.0f;

		//slide -> run
		if (INPUT->KeyUp(VK_DOWN))
		{
			state = CState::RUN;
			slide->isVisible = false;
			run->isVisible = true;
		}
	}
	else //jump
	{


		if (INPUT->KeyDown(VK_SPACE) && !doubleJump)
		{
			doubleJump = true;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			gravity = -200.0f;
		}

		//jump -> run

	}

	col->MoveWorldPos((RIGHT * 200.0f + DOWN * gravity) * DELTA );
	gravity += 200.0f * DELTA;

	run->Update();
	col->Update();
	slide->Update();
	jump->Update();
	landing->Update();
}

void Cookie::Render()
{
	col->Render();
	run->Render();
	slide->Render();
	jump->Render();
	landing->Render();
}
