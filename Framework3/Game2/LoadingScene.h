#pragma once
class LoadingScene : public Scene
{
public:
	ObImage*	bg;
	thread*		th;	
	ObRect*		bar;

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

