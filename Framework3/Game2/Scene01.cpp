#include "stdafx.h"

void Scene01::Init()
{
	map = new ObTileMap;
	map->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));
	map->SetTile(Int2(0, 0), Int2(6, 3));
	map->SetTile(Int2(1, 0), Int2(5, 5));
	map->SetTile(Int2(2, 0), Int2(1, 2), 1);

	LIGHT->light.lights[0].radius = 0.0f;
	LIGHT->light.inColor.x = 0.5f;
	LIGHT->light.inColor.y = 0.5f;
	LIGHT->light.inColor.z = 0.5f;

	fadeOut = false;
	fadeIn = 2.0f;
}

void Scene01::Release()
{
	SafeDelete(map);
	//SafeDelete(rc);
}

void Scene01::Update()
{
	if (ImGui::Button("Scene02"))
	{
		fadeOut = true;
		SCENE->ChangeScene("Scene02", 1.0f);
	}

	if (fadeOut)
	{
		LIGHT->light.lights[0].radius -= 2000.0f * DELTA;
	}

	if (fadeIn > 0.0f)
	{
		fadeIn -= DELTA;
		LIGHT->light.lights[0].radius += 1000.0f * DELTA;
	}

	if (INPUT->KeyPress(VK_RIGHT))
	{
		rc->MoveWorldPos(RIGHT * 200.0f * DELTA);
	}
	if (INPUT->KeyPress(VK_LEFT))
	{
		rc->MoveWorldPos(LEFT * 200.0f * DELTA);
	}
	if (INPUT->KeyPress(VK_UP))
	{
		rc->MoveWorldPos(UP * 200.0f * DELTA);
	}


	map->Update();
	rc->Update();
}

void Scene01::LateUpdate()
{

}

void Scene01::Render()
{
	map->Render();

	DWRITE->GetDC()->BeginDraw();
	DWRITE->RenderText(L"�ȳ��ϼ���", RECT{ 20, 20, 300, 300 }, 100.0f,
		L"����ǹ��� �־�", Color(1.0f, 0.0f, 0.0f, 1.0f), DWRITE_FONT_WEIGHT_BOLD,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_SEMI_EXPANDED);
	DWRITE->GetDC()->EndDraw();

	
	rc->Render();
}

void Scene01::ResizeScreen()
{
}
