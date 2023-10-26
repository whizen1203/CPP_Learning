#include "stdafx.h"

Scene02::Scene02()
{
	map = new ObTileMap;

	map->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));
	map->SetTile(Int2(0, 0), Int2(6, 3));
	map->SetTile(Int2(1, 0), Int2(5, 5));
	map->SetTile(Int2(2, 0), Int2(1, 2), 1);

	LIGHT->light.lights[0].radius = 2000.0f;

	/*LIGHT->light.inColor.x = 1.0f;
	LIGHT->light.inColor.y = 1.0f;
	LIGHT->light.inColor.z = 1.0f;*/


	WhiteOut = false;
	WhiteIn = 1.0f;
}

Scene02::~Scene02()
{
	SafeDelete(map);
}

void Scene02::Init()
{
	LIGHT->light.inColor.x = 1.0f;
	LIGHT->light.inColor.y = 1.0f;
	LIGHT->light.inColor.z = 1.0f;
}

void Scene02::Release()
{
	
	
}

void Scene02::Update()
{
	if (ImGui::Button("Scene01"))
	{
		WhiteOut = true;
		SCENE->ChangeScene("Scene01", 1.0f);
		//return;
	}

	if (WhiteOut)
	{
		LIGHT->light.inColor.x += 0.5f * DELTA;
		LIGHT->light.inColor.y += 0.5f * DELTA;
		LIGHT->light.inColor.z += 0.5f * DELTA;
	}

	if (WhiteIn > 0.0f)
	{
		WhiteIn -= DELTA;
		LIGHT->light.inColor.x -= 0.5f * DELTA;
		LIGHT->light.inColor.y -= 0.5f * DELTA;
		LIGHT->light.inColor.z -= 0.5f * DELTA;
	}

	map->Update();
	//rc->Update();
}

void Scene02::LateUpdate()
{

}

void Scene02::Render()
{
	map->Render();
	//rc->Render();
}

void Scene02::ResizeScreen()
{
}
