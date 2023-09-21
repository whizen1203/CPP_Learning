#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	bg = new ObImage(L"back.jpg");
	bg->scale = Vector2(4000.0f, 2000.0f);
	//bg->space = SPACE::SCREEN;

	player.SetWorldPos(Vector2(0.0f, 0.0f));
	player.scale = Vector2(70.0f, 70.0f);
	//r g b a 1.0f
	player.color = Color(0.5f, 0.5f, 0.0f, 1.0f);
	player.isAxis = true;
	//player.pivot = OFFSET_T;
	//rc.isFilled = false;
	//player.isVisible = false;

	pet.SetParentRT(player);
	pet.SetLocalPos(Vector2(100.0f, 0.0f));
	pet.scale = Vector2(30.0f, 30.0f);
	pet.isAxis = true;
	pet.color = Color(0.0f, 0.0f, 0.5f, 1.0f);
	
	gaugeBar.SetParentT(player);
	gaugeBar.scale = Vector2(100.0f, 20.0f);
	gaugeBar.SetLocalPosX(-50.0f);
	gaugeBar.SetLocalPosY(60.0f);
	gaugeBar.color = Color(0.5f, 0.0f, 0.0f, 1.0f);

	//GetWorldPos -> 중점  pivot점
	//GetWorldPivot -> 중심점
	gaugeBar.pivot = OFFSET_L;

	stick.SetParentRT(player);
	stick.scale = Vector2(50.0f, 50.0f);
	stick.SetLocalPosX(player.scale.x * 2.0f);
	stick.isAxis = true;
}

void Main::Release()
{
	SafeDelete(bg);
}

void Main::Update()
{
	//player.SetWorldPos(lastPos);

	//player.color = Color(RANDOM->Float(), RANDOM->Float(), RANDOM->Float(), 1.0f);

	//cout << INPUT->GetWorldMousePos().x << "\t" << INPUT->GetWorldMousePos().y << endl;

	if (INPUT->KeyPress('W'))
	{
		player.MoveWorldPos(UP * 400.0f * DELTA);
	}
	else if (INPUT->KeyPress('S'))
	{
		player.MoveWorldPos(DOWN * 400.0f * DELTA);
	}

	if (INPUT->KeyPress('A'))
	{
		player.MoveWorldPos(LEFT * 400.0f * DELTA);
	}
	else if (INPUT->KeyPress('D'))
	{
		player.MoveWorldPos(RIGHT * 400.0f * DELTA);
	}

	if (INPUT->KeyPress(VK_UP))
	{
		CAM->position += UP * 200.0f * DELTA;
	}
	else if (INPUT->KeyPress(VK_DOWN))
	{
		CAM->position += DOWN * 200.0f * DELTA;
	}

	if (INPUT->KeyPress(VK_LEFT))
	{
		CAM->position += LEFT * 200.0f * DELTA;
	}
	else if (INPUT->KeyPress(VK_RIGHT))
	{
		CAM->position += RIGHT * 200.0f * DELTA;
	}

	//마우스 바라보기
	Vector2 velocity = INPUT->GetWorldMousePos() - player.GetWorldPos();
	player.rotation = Utility::DirToRadian(velocity);

	//player.rotation = Utility::Saturate(player.rotation, 0.0f, DIV2PI);

	if (INPUT->KeyDown(VK_LBUTTON))
	{
		gaugeBar.scale.x = 0.0f;
	}

	if (INPUT->KeyPress(VK_LBUTTON))
	{
		gaugeBar.scale.x += 100.0f * DELTA;

		if (gaugeBar.scale.x > 100.0f)
		{
			gaugeBar.scale.x = 0.0f;
		}
	}

	//발사 해라
	if (INPUT->KeyUp(VK_LBUTTON))
	{
		for (int i = 0; i < BMAX; i++)
		{
			if (bullet[i].Shoot(player, gaugeBar.scale.x, 
				stick.GetWorldPos()))
			{
				break;
			}
		}
	}

	pet.revolution += 60.0f * ToRadian * DELTA;

	player.Update();
	for (int i = 0; i < BMAX; i++)
	{
		bullet[i].Update(player);
	}
	pet.Update();
	gaugeBar.Update();
	stick.Update();
	bg->Update();
}

//모든 객체가 움직이고 난 후
void Main::LateUpdate()
{
	//카메라 따라가기
	//Vector2 velocity = player.GetWorldPos() - CAM->position;
	//CAM->position += velocity / 100.0f;
	//CAM->position += velocity * DELTA;

	//플레이어 가두기
	player.SetWorldPosX(Utility::Saturate(player.GetWorldPos().x,
		-2000.0f + player.scale.x * 0.5f,
		2000.0f - player.scale.x * 0.5f));
	player.SetWorldPosY(Utility::Saturate(player.GetWorldPos().y,
		-1000.0f + player.scale.y * 0.5f,
		1000.0f - player.scale.y * 0.5f));

	//카메라 가두기
	/*CAM->position.x = (4000.0f - app.GetWidth()) * player.GetWorldPos().x
		/ (4000.0f - player.scale.x);
	CAM->position.y = (2000.0f - app.GetHeight()) * player.GetWorldPos().y
		/ (2000.0f - player.scale.y);*/

	/*CAM->position.x = Utility::Saturate(CAM->position.x,
		-2000.0f + app.GetHalfWidth(),
		2000.0f - app.GetHalfWidth());
	CAM->position.y = Utility::Saturate(CAM->position.y,
		-1000.0f + app.GetHalfHeight(),
		1000.0f - app.GetHalfHeight());*/

	for (int i = 0; i < BMAX; i++)
	{
		bullet[i].LateUpdate();
	}
}

void Main::Render()
{
	bg->Render();
	player.Render();
	for (int i = 0; i < BMAX; i++)
	{
		bullet[i].Render();
	}
	pet.Render();
	gaugeBar.Render();
	//stick.Render();
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1400.0f , 800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}