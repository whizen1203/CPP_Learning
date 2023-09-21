#pragma once
#define BMAX 5

class Main : public Scene
{
private:
	ObImage* bg;

	ObRect player;
	Bullet bullet[BMAX];
	ObCircle pet;
	ObRect gaugeBar;

	GameObject stick;

	Vector2 lastPos;

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
