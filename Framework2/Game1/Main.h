#pragma once
#define FMAX 21

class Main : public Scene
{
private:
	ObImage* bg;
	ObImage* floor[FMAX];
	MPplayer* player;
	MPMon* mon[5];

	ObTileMap* map;

public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
