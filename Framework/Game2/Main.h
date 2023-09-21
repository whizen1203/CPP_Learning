#pragma once
class Main : public Scene
{
private:
	ObRect* player;
	//ObRect* trail[30];
	deque<ObRect*> trail;

	ObImage* img;

	float timer;
	float interval;
	int trailNum;
	//int idx;
public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
