#include "stdafx.h"

void Scene02::Init()
{
	map = new ObTileMap();
	map->file = "TileMap02.txt";
	map->Load();
	map->CreateTileCost();

	cc = new ObStar;
	cc->scale = Vector2(300.0f, 300.0f);

	cc2 = new ObStar;
	cc2->scale = Vector2(300.0f, 300.0f);
	cc2->SetWorldPosX(400.0f);
	cc2->isFilled = false;

	//img = new ObImage(L"Life.png");
	img->scale = Vector2(70.0f, 70.0f);

	LIGHT->light.lights[0].radius = 2000.0f;
	LIGHT->light.inColor.x = 1.0f;
	LIGHT->light.inColor.y = 1.0f;
	LIGHT->light.inColor.z = 1.0f;

	whiteOut = false;
	whiteIn = 1.0f;
}

void Scene02::Release()
{
	SafeDelete(map);
	SafeDelete(cc);
	SafeDelete(cc2);
	//SafeDelete(img);
}

void Scene02::Update()
{
	if (ImGui::Button("Scene01"))
	{
		SCENE->ChangeScene("SC01", 1.0f);
		whiteOut = true;
		//return;
	}

	if (whiteOut)
	{
		LIGHT->light.inColor.x += 0.5f * DELTA;
		LIGHT->light.inColor.y += 0.5f * DELTA;
		LIGHT->light.inColor.z += 0.5f * DELTA;
	}

	if (whiteIn > 0.0f)
	{
		whiteIn -= DELTA;
		LIGHT->light.inColor.x -= 0.5f * DELTA;
		LIGHT->light.inColor.y -= 0.5f * DELTA;
		LIGHT->light.inColor.z -= 0.5f * DELTA;
	}

	ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	if (INPUT->KeyPress(VK_LEFT))
	{
		img->MoveWorldPos(LEFT * 400.0f * DELTA);
	}
	else if (INPUT->KeyPress(VK_RIGHT))
	{
		img->MoveWorldPos(RIGHT * 400.0f * DELTA);
	}
	if (INPUT->KeyPress(VK_UP))
	{
		img->MoveWorldPos(UP * 400.0f * DELTA);
	}
	else if (INPUT->KeyPress(VK_DOWN))
	{
		img->MoveWorldPos(DOWN * 400.0f * DELTA);
	}

	if (INPUT->KeyDown(VK_RBUTTON))
	{
		//   출발점, 도착점
		Int2 sour, dest;
		//찾았는가?
		bool isFind;
		isFind = map->WorldPosToTileIdx(img->GetWorldPos(), sour);
		isFind &= map->WorldPosToTileIdx(INPUT->GetWorldMousePos(), dest);

		if (isFind)
		{
			if (map->PathFinding(sour, dest, PlWay))
			{
				//길 사이즈만큼 반복
				for (int i = 0; i < PlWay.size(); i++)
				{
					cout << "Way" << i << ":" << PlWay[i]->idx.x <<
						"," << PlWay[i]->idx.y << endl;
				}

				g = 0.0f;
				plSour = img->GetWorldPos();
				PlWay.pop_back(); //출발지 빼기
				plDest = PlWay.back()->Pos;
			}
		}
	}

	//가야될 길이 존재할 때
	if (!PlWay.empty())
	{
		img->SetWorldPos(Utility::Lerp(plSour, plDest, g));
		g += DELTA * 3.0f;

		//도착지를 지났을때
		if (g > 1.0f)
		{
			g = 0.0f;
			plSour = plDest;
			PlWay.pop_back(); //맨뒷길 빼기

			if (!PlWay.empty())
				plDest = PlWay.back()->Pos;
		}
	}

	map->Update();
	img->Update();
	cc->Update();
	cc2->Update();
}

void Scene02::LateUpdate()
{
	
}

void Scene02::Render()
{
	map->Render();
	img->Render();
	cc->Render();
	cc2->Render();
}

void Scene02::ResizeScreen()
{
}