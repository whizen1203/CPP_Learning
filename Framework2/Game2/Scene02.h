#pragma once
class Scene02 : public Scene
{
private:
	ObTileMap* map;

	ObStar* cc;
	ObStar* cc2;

	//길찾기용 변수
	vector<Tile*> PlWay;
	//이동시킬 위치
	Vector2 plDest;
	Vector2 plSour;
	//비율
	float   g;

	bool whiteOut;
	float whiteIn;
public:	
	ObImage* img;
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

