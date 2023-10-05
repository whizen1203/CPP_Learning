#pragma once
class Scene01 : public Scene
{
private:
	ObTileMap* map;

	ObRect* ui;

	Vector2 lastPos;

	//��ã��� ����
	vector<Tile*> PlWay;
	//�̵���ų ��ġ
	Vector2 plDest;
	Vector2 plSour;
	//����
	float   g;

	bool fadeOut;
	float fadeIn;

public:
	ObImage* img;

	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

