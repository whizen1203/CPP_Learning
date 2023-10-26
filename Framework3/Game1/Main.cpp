#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	player = new Player;
	boss = new Boss;

	map = new ObIso();
	map->file = "map1.txt";
	map->Load();
	map->CreateTileCost();
}

void Main::Release()
{
	SafeDelete(player);
	SafeDelete(boss);
	SafeDelete(map);
}

void Main::Update()
{
	//screenPos
	ImGui::SliderFloat2("0_LightPos", (float*)&LIGHT->light.lights[0].screenPos, 0.0f, 2000.0f);
	ImGui::SliderFloat2("1_LightPos", (float*)&LIGHT->light.lights[1].screenPos, 0.0f, 2000.0f);

	//radius
	ImGui::SliderFloat("0_Radius", &LIGHT->light.lights[0].radius, 0.0f, 2000.0f);
	ImGui::SliderFloat("1_adius", &LIGHT->light.lights[1].radius, 0.0f, 2000.0f);

	ImGui::ColorEdit3("LightColor", (float*)&LIGHT->light.inColor);
	ImGui::ColorEdit3("OutColor", (float*)&LIGHT->light.outColor);
	ImGui::SliderFloat("Select", &LIGHT->light.select.x, 0.0f, 1.0f);

	//우클릭햇을때
	if (INPUT->KeyDown(VK_RBUTTON))
	{
		//   출발점, 도착점
		Int2 sour, dest;
		//찾았는가?
		bool isFind;
		isFind = map->WorldPosToTileIdx(player->col->GetWorldPos(), sour);
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
				plSour = player->col->GetWorldPos();
				PlWay.pop_back(); //출발지 빼기
				plDest = PlWay.back()->Pos;
			}
		}
	}

	//가야될 길이 존재할 때
	if (!PlWay.empty())
	{
		player->col->SetWorldPos(Utility::Lerp(plSour, plDest, g));
		g += DELTA * 10.0f;

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

	boss->target = player->col->GetWorldPos();
	LIGHT->SetLightPos(player->col->GetWorldPos(), 1);

	player->Update();
	boss->Update();
	map->Update();
}

void Main::LateUpdate()
{
	Int2 plIdx;
	vector<Vector2> foot = player->GetFoot();

	for (int i = 0; i < 4; i++)
	{
		if (map->WorldPosToTileIdx(foot[i], plIdx))
		{
			if (map->GetTileState(plIdx) == TILE_WALL)
			{
				player->StepBack();
			}
		}
	}

	//CAM->position = player->col->GetWorldPos();
}

void Main::Render()
{
	map->Render();
	player->Render();
	boss->Render();
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1400.0f,800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}