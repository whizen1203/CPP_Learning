#pragma once
class Scene02 : public Scene
{
public:
	ObTileMap* map;
	//ObRect* rc;

	bool WhiteOut;
	float WhiteIn;

	Scene02();
	~Scene02();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

