#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	LIGHT->light.lights[0].radius = 1000.0f;

	map = new ObTileMap();
	map->file = "TileMap01.txt";
	map->Load();

	bg = new ObImage(L"MPmap01.jpg");
	bg->scale = Vector2(bg->imgSize.x * 2.0f, bg->imgSize.y) * 2.0f;

	for (int i = 0; i < FMAX; i++)
	{
		floor[i] = new ObImage(L"MPmap02.jpg");
		floor[i]->scale = Vector2(floor[i]->imgSize.x, floor[i]->imgSize.y) * 0.7f;
		floor[i]->pivot = OFFSET_LB;
		floor[i]->SetWorldPosX(-(bg->scale.x * 0.5f) + floor[i]->scale.x * i);
		floor[i]->SetWorldPosY(-app.GetHalfHeight());
		floor[i]->collider = COLLIDER::RECT;
	}

	player = new MPplayer;
	player->col->SetWorldPosY(-app.GetHalfHeight() + floor[0]->scale.y);
	//player->run->color = Color(0.5f, 0.0f, 0.0f, 0.5f);

	for (int i = 0; i < 5; i++)
	{
		mon[i] = new MPMon();
		mon[i]->range->SetWorldPosX(RANDOM->Float(-(bg->scale.x * 0.5f), (bg->scale.x * 0.5f)));
		mon[i]->range->SetWorldPosY(-app.GetHalfHeight() + floor[0]->scale.y);
		mon[i]->range->Update();
		mon[i]->col->SetWorldPos(mon[i]->range->GetWorldPos());
	}
}

void Main::Release()
{
	SafeDelete(map);
	SafeDelete(bg);
	SafeDelete(player);
	for (int i = 0; i < FMAX; i++)
	{
		SafeDelete(floor[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		SafeDelete(mon[i]);
	}
}

void Main::Update()
{
	ImGui::SliderFloat("Alpha", &player->run->color.w, 0.0f, 1.0f);

	ImGui::SliderFloat("YRotation", &player->run->rotationY, 0.0f, PI);

	if (INPUT->KeyPress(VK_LEFT))
	{
		CAM->position += LEFT * 400.0f * DELTA;
	}
	if (INPUT->KeyPress(VK_RIGHT))
	{
		CAM->position += RIGHT * 400.0f * DELTA;
	}

	

	map->Update();
	bg->Update();
	player->Update();
	for (int i = 0; i < FMAX; i++)
	{
		floor[i]->Update();
	}
	for (int i = 0; i < 5; i++)
	{
		if (!mon[i]->col->colOnOff)
		{
			mon[i]->col->colOnOff = player->targetCol;
		}
		mon[i]->Update();
	}
}

//모든 객체가 움직이고 난 후
void Main::LateUpdate()
{
	Vector2 cam = player->col->GetWorldPos() - CAM->position;
	CAM->position += cam * DELTA;

	CAM->position.x = Utility::Saturate(CAM->position.x,
		-(bg->scale.x * 0.5f) + app.GetHalfWidth(),
		bg->scale.x * 0.5f - app.GetHalfWidth());

	CAM->position.y = Utility::Saturate(CAM->position.y,
		-(bg->scale.y * 0.5f) + app.GetHalfHeight(),
		bg->scale.y * 0.5f - app.GetHalfHeight());

	for (int i = 0; i < 5; i++)
	{
		if (player->col->Intersect(mon[i]->col))
		{
			//player->col->colOnOff = false;

			//player
			player->TakeDamage(mon[i]->damage);

			if (player->state == PState::ATT)
			{
				cout << "d" << endl;
				mon[i]->TakeDamage(player->damage);
				player->targetCol = false;
				mon[i]->col->colOnOff = false;
			}
		}
	}

	//jump -> idle
	for (int i = 0; i < FMAX; i++)
	{
		if (player->col->Intersect(floor[i]))
		{
			player->col->SetWorldPosY(-app.GetHalfHeight() + floor[0]->scale.y);
			player->gravity = 0.0f;
			
			if (player->state == PState::JUMP)
			{
				//idle
				player->JumpToIdle();
			}
			
		}
	}
}

void Main::Render()
{
	map->Render();
	//bg->Render();
	for (int i = 0; i < FMAX; i++)
	{
		floor[i]->Render();
	}
	for (int i = 0; i < 5; i++)
	{
		mon[i]->Render();
	}
	player->Render();
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