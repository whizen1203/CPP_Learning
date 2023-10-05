#pragma once
class LoadingScene : public Scene
{
public:
	ObImage* img;
	ObImage* img2;

	ObRect* bar;

	thread* th;

public:
	LoadingScene();
	~LoadingScene();

	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

