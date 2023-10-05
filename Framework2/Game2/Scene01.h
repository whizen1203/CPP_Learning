#pragma once
class Scene01 : public Scene
{
private:
	ObTileMap* map;

	ObRect* ui;

	Vector2 lastPos;

	//길찾기용 변수
	vector<Tile*> PlWay;
	//이동시킬 위치
	Vector2 plDest;
	Vector2 plSour;
	//비율
	float   g;

	bool fadeOut;
	float fadeIn;

public:
	ObImage* img;

	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

