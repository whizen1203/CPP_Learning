#pragma once
class Main : public Scene
{
private:
	ObTileMap* map;
	ObImage* img;

	//��ã��� ����
	vector<Tile*> PlWay;
	//�̵���ų ��ġ
	Vector2 plDest;
	Vector2 plSour;
	//����
	float   g;

public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};