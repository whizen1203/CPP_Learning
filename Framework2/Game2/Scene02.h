#pragma once
class Scene02 : public Scene
{
private:
	ObImage* coin;

public:	
	
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

