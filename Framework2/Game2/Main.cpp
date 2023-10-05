#include "stdafx.h"
#include "Main.h"

namespace A
{
	int a;
}

void Main::Init()
{
	//A::a;

	img = new ObImage(L"Life.png");

	{ //익명스코프
		Scene01* temp = new Scene01;
		temp->img = img;
		SCENE->AddScene("SC01", temp);
	}
	
	{
		Scene02* temp = new Scene02;
		temp->img = img;
		SCENE->AddScene("SC02", temp);
	}

	{
		LoadingScene* temp = new LoadingScene;
		SCENE->AddScene("Loading", temp);
	}

	SCENE->ChangeScene("SC02");

	LIGHT->light.lights[0].radius = 2000.0f;
}

void Main::Release()
{
	SafeDelete(img);

	SCENE->Release();
}

void Main::Update()
{
	SCENE->Update();
}

void Main::LateUpdate()
{
	SCENE->LateUpdate();
}

void Main::Render()
{
	SCENE->Render();
}

void Main::ResizeScreen()
{
	SCENE->ResizeScreen();
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