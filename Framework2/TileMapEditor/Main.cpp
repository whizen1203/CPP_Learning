#include "stdafx.h"
#include "Main.h"

bool IsMouseHoveringWindow()
{
	RECT window;
	GetWindowRect(app.GetHandle(), &window);
	POINT mouse;
	GetCursorPos(&mouse);

	return PtInRect(&window, mouse);
}

void Main::Init()
{
	map = new ObTileMap;
	map->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));

	imgIdx = 0;
	tileColor = Color(0.5f, 0.5f, 0.5f, 0.5f);
	tileState = 0;
	tileSize = Int2(20, 20);
}

void Main::Release()
{
	SafeDelete(map);
}

void Main::Update()
{
	MoveCam();

	ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());
	ImGui::SliderFloat2("Scale", (float*)&map->scale, 10.0f, 500.0f);
	//타일 개수 변경 1 부터 100까지
	if (ImGui::SliderInt2("TileSize", (int*)&tileSize, 1, 100))
	{
		map->ResizeTile(tileSize);
	}
	//타일맵 위치 변경
	Vector2 pos = map->GetWorldPos();
	if (ImGui::SliderFloat2("TilePos", (float*)&pos, -1000.0f, 1000.0f))
	{
		map->SetWorldPos(pos);
	}
	ImGui::SliderInt("TileState", &tileState, TILE_NONE, TILE_SIZE);
	ImGui::ColorEdit4("TileColor", (float*)&tileColor, ImGuiColorEditFlags_PickerHueWheel);

	//Texture
	for (int i = 0; i < IMAGESLOT; i++)
	{
		string str = "Texture" + to_string(i);
		if (GUI->FileImGui(str.c_str(), str.c_str(),
			".jpg,.png,.bmp,.dds,.tga", "../Contents/Images"))
		{
			string path = ImGuiFileDialog::Instance()->GetCurrentFileName();
			SafeDelete(map->tileImages[i]);
			wstring wImgFile = L"";
			wImgFile.assign(path.begin(), path.end());
			map->tileImages[i] = new ObImage(wImgFile);
		}
		if (i < IMAGESLOT - 1)
		{
			ImGui::SameLine();
		}
	}

	//maxFrame
	ImGui::InputInt2("maxFrame", (int*)&map->tileImages[imgIdx]->maxFrame);

	map->RenderGui(guiPickingIdx, imgIdx);
	ImGui::Text("GuiPickingIdx : %d, %d", guiPickingIdx.x, guiPickingIdx.y);

	ImVec2 min = ImGui::GetWindowPos();
	ImVec2 max;
	max.x = min.x + ImGui::GetWindowSize().x;
	max.y = min.y + ImGui::GetWindowSize().y;

	if (IsMouseHoveringWindow() && !ImGui::IsMouseHoveringRect(min, max))
	{
		if (INPUT->KeyPress(VK_LBUTTON))
		{
			if (map->WorldPosToTileIdx(INPUT->GetWorldMousePos(), tileIdx))
			{
				map->SetTile(tileIdx, guiPickingIdx, imgIdx, tileState, tileColor);
			}
		}
	}
	ImGui::Text("TileIdx : %d, %d", tileIdx.x, tileIdx.y);

	//SaveLoad
	if (GUI->FileImGui("Save", "Save Map",
		".txt", "../Contents/TileMap"))
	{
		string path = ImGuiFileDialog::Instance()->GetCurrentFileName();
		map->file = path;
		map->Save();
	}
	ImGui::SameLine();
	if (GUI->FileImGui("Load", "Load Map",
		".txt", "../Contents/TileMap"))
	{
		string path = ImGuiFileDialog::Instance()->GetCurrentFileName();
		map->file = path;
		map->Load();
		tileSize = map->GetTileSize();
	}

	map->Update();
}

void Main::LateUpdate()
{

}

void Main::Render()
{
	map->Render();
}

void Main::ResizeScreen()
{
}

void Main::MoveCam()
{
	if (INPUT->KeyPress(VK_UP))
	{
		CAM->position += UP * 300.0f * DELTA;
	}
	else if (INPUT->KeyPress(VK_DOWN))
	{
		CAM->position += DOWN * 300.0f * DELTA;
	}

	if (INPUT->KeyPress(VK_LEFT))
	{
		CAM->position += LEFT * 300.0f * DELTA;
	}
	else if (INPUT->KeyPress(VK_RIGHT))
	{
		CAM->position += RIGHT * 300.0f * DELTA;
	}
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"TileMapEditor");
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