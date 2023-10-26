#pragma once
class Scene01 : public Scene
{
public:
	ObTileMap* map;
	ObRect* rc;

	bool fadeOut;
	float fadeIn;


	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

