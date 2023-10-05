#include "stdafx.h"

int initCount = 0;
mutex m;

void CreateScene()
{
	{ //익명스코프
		Scene01* temp = new Scene01;
		SCENE->AddScene("SC01", temp);
	}

	m.lock();
	Sleep(1000); // 1000밀리세컨드 = 1초
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000); // 1000밀리세컨드 = 1초
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000); // 1000밀리세컨드 = 1초
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000); // 1000밀리세컨드 = 1초
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000); // 1000밀리세컨드 = 1초
	initCount++;
	m.unlock();
}

LoadingScene::LoadingScene()
{
	img = new ObImage(L"Oven1.png");
	img->scale = Vector2(app.GetWidth(), app.GetHeight());

	img2 = new ObImage(L"Oven2.png");
	img2->scale = Vector2(app.GetWidth(), app.GetHeight());

	bar = new ObRect();
	bar->pivot = OFFSET_L;
	bar->scale = Vector2(200.0f, 100.0f); 
	bar->color = Color(1.0f, 1.0f, 1.0f, 1.0f);
	bar->SetWorldPosX(-app.GetHalfWidth());

	th = new thread(CreateScene);
}

LoadingScene::~LoadingScene()
{
	SafeDelete(img);
	SafeDelete(img2);
	SafeDelete(bar);
}

void LoadingScene::Init()
{
}

void LoadingScene::Release()
{
}

void LoadingScene::Update()
{
	img->uv.x += DELTA / img->scale.x * 50.0f;
	img->uv.z += DELTA / img->scale.x * 50.0f;

	img2->uv.x += DELTA / img->scale.x * 100.0f;
	img2->uv.z += DELTA / img->scale.x * 100.0f;

	bar->scale.x = app.GetWidth() / 5 * initCount;

	/*if (initCount == 5)
	{
		SCENE->ChangeScene("SC01");
		return;
	}*/

	img->Update();
	img2->Update();
	bar->Update();
}

void LoadingScene::LateUpdate()
{
}

void LoadingScene::Render()
{
	img->Render();
	img2->Render();
	bar->Render();
}

void LoadingScene::ResizeScreen()
{
}
