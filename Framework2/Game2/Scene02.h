#pragma once
class Scene02 : public Scene
{
private:
	ObTileMap* map;

	ObStar* cc;
	ObStar* cc2;

	//��ã��� ����
	vector<Tile*> PlWay;
	//�̵���ų ��ġ
	Vector2 plDest;
	Vector2 plSour;
	//����
	float   g;

	bool whiteOut;
	float whiteIn;
public:	
	ObImage* img;
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

