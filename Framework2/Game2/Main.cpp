#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	map = new ObTileMap();
	map->file = "TileMap01.txt";
	map->Load();
	map->CreateTileCost();

	img = new ObImage(L"Life.png");
	img->scale = Vector2(70.0f, 70.0f);
}

void Main::Release()
{
	SafeDelete(map);
	SafeDelete(img);

}

void Main::Update()
{
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
		//   �����, ������
		Int2 sour, dest;
		//ã�Ҵ°�?
		bool isFind;
		isFind = map->WorldPosToTileIdx(img->GetWorldPos(), sour);
		isFind &= map->WorldPosToTileIdx(INPUT->GetWorldMousePos(), dest);

		if (isFind)
		{
			if (map->PathFinding(sour, dest, PlWay))
			{
				//�� �����ŭ �ݺ�
				for (int i = 0; i < PlWay.size(); i++)
				{
					cout << "Way" << i << ":" << PlWay[i]->idx.x <<
						"," << PlWay[i]->idx.y << endl;
				}

				g = 0.0f;
				plSour = img->GetWorldPos();
				PlWay.pop_back(); //����� ����
				plDest = PlWay.back()->Pos;
			}
		}
	}

	//���ߵ� ���� ������ ��
	if (!PlWay.empty())
	{
		img->SetWorldPos(Utility::Lerp(plSour, plDest, g));
		g += DELTA * 3.0f;

		//�������� ��������
		if (g > 1.0f)
		{
			g = 0.0f;
			plSour = plDest;
			PlWay.pop_back(); //�ǵޱ� ����

			if (!PlWay.empty())
				plDest = PlWay.back()->Pos;
		}
	}

	map->Update();
	img->Update();
}

void Main::LateUpdate()
{
	CAM->position = img->GetWorldPos();
}

void Main::Render()
{
	map->Render();
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