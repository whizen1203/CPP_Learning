#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	rc = new ObRect;
	rc->scale = Vector2(200.0f, 200.0f);

	{ //익명스코프
		Scene01* temp = new Scene01;
		temp->rc = rc;
		SCENE->AddScene("Scene01", temp);
	}
	
	/*{
		Scene02* temp = new Scene02;
		temp->rc = rc;
		SCENE->AddScene("Scene02", temp);
	}*/

	{
		LoadingScene* temp = new LoadingScene;
		SCENE->AddScene("Loading", temp);
	}

	SCENE->ChangeScene("Loading");
}

void Main::Release()
{
	SafeDelete(rc);
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