#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	img = new ObImage(L"back.jpg");
	img->scale = Vector2(300.0f, 300.0f);
	img->uv = Vector4(380.0f / 600.0f, 127.0f / 337.0f, 
		396.0f / 600.0f, 139.0f / 337.0f);

	player = new ObRect;
	player->scale = Vector2(100.0f, 100.0f);
	player->color = Color(RANDOM->Float(), RANDOM->Float(), RANDOM->Float(), 1.0f);

	trailNum = 10;

	/*for (int i = 0; i < 30; i++)
	{
		trail[i] = new ObRect;
		trail[i]->isVisible = false;
		trail[i]->scale = Vector2(100.0f, 100.0f);
		trail[i]->color = player->color;
	}
	idx = 0;*/

	trail.resize(trailNum);
	for (auto it = trail.begin(); it != trail.end(); it++)
	{
		(*it) = new ObRect;
		(*it)->isVisible = false;
		(*it)->scale = Vector2(100.0f, 100.0f);
		(*it)->color = player->color;
	}

	interval = 0.3f;
	timer = 0.0f; 
	
}

void Main::Release()
{
	SafeDelete(player);
	for (auto it = trail.begin(); it != trail.end(); it++)
	{
		SafeDelete(*it);
	}
}

void Main::Update()
{
	ImGui::SliderFloat4("UV", (float*)&img->uv, 0.0f, 1.0f);

	ImGui::SliderFloat("Interval", &interval, 0.0f, 2.0f);
	float duration = interval * trailNum;
	//ImGui::Text("Duration : %.3f", duration);
	ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "Duration : %.3f", duration);

	if (ImGui::SliderInt("TrailNum", &trailNum, 1, 30))
	{
		for (auto it = trail.begin(); it != trail.end(); it++)
		{
			SafeDelete(*it);
		}

		trail.resize(trailNum);

		for (auto it = trail.begin(); it != trail.end(); it++)
		{
			(*it) = new ObRect;
			(*it)->isVisible = false;
			(*it)->scale = Vector2(100.0f, 100.0f);
			(*it)->color = player->color;
		}
	}

	if (INPUT->KeyPress('W'))
	{
		player->rotation += 120.0f * DELTA * ToRadian;
	}
	else if (INPUT->KeyPress('S'))
	{
		player->rotation -= 120.0f * DELTA * ToRadian;
	}

	if (INPUT->KeyPress('A'))
	{
		player->MoveWorldPos(-player->GetRight() * 400.0f * DELTA);
		
	}
	else if (INPUT->KeyPress('D'))
	{
		player->MoveWorldPos(player->GetRight() * 400.0f * DELTA);
		
	}

	if (TIMER->GetTick(timer, interval))
	{
		trail.front()->SetWorldPos(player->GetWorldPos());
		trail.front()->rotation = player->rotation;
		trail.front()->isVisible = true;
		trail.push_back(trail.front());
		trail.pop_front();
	}

	/*timer += DELTA;
	if (timer > 0.1f)
	{
		trail[idx]->isVisible = true;
		trail[idx]->SetWorldPos(player->GetWorldPos());
		trail[idx]->rotation = player->rotation;
		idx++;

		if (idx >= 10)
		{
			idx = 0;
		}

		timer = 0.0f;
	}*/



	img->Update();
	player->Update();
	/*for (int i = 0; i < 30; i++)
	{
		trail[i]->Update();
	}*/
	for (auto it = trail.begin(); it != trail.end(); it++)
	{
		(*it)->Update();
	}
}

void Main::LateUpdate()
{

}

void Main::Render()
{
	/*for (int i = 0; i < 30; i++)
	{
		trail[i]->Render();
	}*/
	for (auto it = trail.begin(); it != trail.end(); it++)
	{
		(*it)->Render();
	}
	player->Render();
	img->Render();
}

void Main::ResizeScreen()
{
}



int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game2");
	app.SetInstance(instance);
	app.InitWidthHeight(1000.0f, 800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}