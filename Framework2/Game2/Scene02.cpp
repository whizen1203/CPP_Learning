#include "stdafx.h"

void Scene02::Init()
{
	coin = new ObImage(L"coin.bmp");
	coin->scale = Vector2(500.0f, 500.0f);
}

void Scene02::Release()
{
	SafeDelete(coin);
}

void Scene02::Update()
{
	if (ImGui::Button("Point"))
	{
		coin->ChangeSampler(D3D11_FILTER_MIN_MAG_MIP_POINT);
	}
	if (ImGui::Button("Linear"))
	{
		coin->ChangeSampler(D3D11_FILTER_MIN_MAG_MIP_LINEAR);
	}

	ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	
	if (ImGui::Button("vSync"))
	{
		app.vSync = !app.vSync;
	}
	cout << app.vSync << endl;

	coin->Update();
}

void Scene02::LateUpdate()
{
	
}

void Scene02::Render()
{
	coin->Render();
}

void Scene02::ResizeScreen()
{
}