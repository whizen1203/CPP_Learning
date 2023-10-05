#include "stdafx.h"

void Scene01::Init()
{
	map = new ObTileMap();
	map->file = "TileMap03.txt";
	map->Load();
	map->CreateTileCost();

	img = new ObImage(L"Life.png");
	img->scale = Vector2(70.0f, 70.0f);

	LIGHT->light.lights[0].radius = 0.0f;

	fadeOut = false;
	fadeIn = 1.0f;

	LIGHT->light.inColor.x = 0.5f;
	LIGHT->light.inColor.y = 0.5f;
	LIGHT->light.inColor.z = 0.5f;

	ui = new ObRect;
	ui->space = SPACE::SCREEN;
	ui->scale = Vector2(100.0f, 100.0f);
	ui->pivot = OFFSET_LT;

}

void Scene01::Release()
{
	SafeDelete(map);
	SafeDelete(ui);
	SafeDelete(img);

}

void Scene01::Update()
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


	if (ImGui::Button("Scene02"))
	{
		SCENE->ChangeScene("SC02", 1.0f);
		fadeOut = true;
		//return;
	}

	if (fadeOut)
	{
		LIGHT->light.lights[0].radius -= 1000.0f * DELTA;
	}

	if (fadeIn > 0.0f)
	{
		fadeIn -= DELTA;
		LIGHT->light.lights[0].radius += 1000.0f * DELTA;
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
	ui->Update();
}

void Scene01::LateUpdate()
{
	CAM->position = img->GetWorldPos();

	Int2 idx;
	vector<Vector2> edge;
	edge.resize(4);
	
	edge[0] = img->GetWorldPos() + Vector2(-15.0f, img->scale.y * 0.5f);
	edge[1] = img->GetWorldPos() + Vector2(-15.0f, img->scale.y * 0.5f - 15.0f);
	edge[2] = img->GetWorldPos() + Vector2(15.0f, img->scale.y * 0.5f - 15.0f);
	edge[3] = img->GetWorldPos() + Vector2(15.0f, img->scale.y * 0.5f);

	for (int i = 0; i < 4; i++)
	{
		if (map->WorldPosToTileIdx(edge[i], idx))
		{
			if (map->GetTileState(idx) == TileState::TILE_WALL)
			{
				img->SetWorldPos(lastPos);
				break;
			}
		}
	}

	if (ui->IntersectScreenMouse(INPUT->GetSceenMousePos()))
	{
		ui->color = Color(1.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		ui->color = Color(0.0f, 0.0f, 0.0f, 1.0f);
	}
	
	img->Update();

	lastPos = img->GetWorldPos();
}

void Scene01::Render()
{
	map->Render();

	//DWRITE->GetDC()->BeginDraw();
	DWRITE->RenderText(L"문원기 바보 \n", { 100, 100, 1000, 1000 }, 100.0f,
		L"배달의민족 주아", Color(0.0f, 0.0f, 1.0f, 1.0f),
		DWRITE_FONT_WEIGHT_ULTRA_BOLD, DWRITE_FONT_STYLE_ITALIC,
		DWRITE_FONT_STRETCH_ULTRA_CONDENSED);
	//DWRITE->GetDC()->EndDraw();

	img->Render();
	ui->Render();
}

void Scene01::ResizeScreen()
{
}