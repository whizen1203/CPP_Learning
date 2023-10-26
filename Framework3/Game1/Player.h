#pragma once
enum class State
{
	IDLE,
	MOVE,
	ROLL
};

class Player : public Character
{
public:
	ObImage*	run;
	ObImage*	roll;
	State		state;

	float		rollTime;
	Vector2		lastPos;

	vector<Vector2>		foot;

public:
	Player();
	~Player();
	void Update();
	void Render();

	void Idle();
	void Move();
	void Roll();

	void Input();

	void StepBack();

	vector<Vector2> GetFoot()
	{
		foot.resize(4);

		foot[0].x = col->GetWorldPos().x - 15.0f;
		foot[0].y = col->GetWorldPos().y - (col->scale.y * 0.5f); 

		foot[1].x = col->GetWorldPos().x + 15.0f;
		foot[1].y = col->GetWorldPos().y - (col->scale.y * 0.5f);

		foot[2].x = col->GetWorldPos().x - 15.0f;
		foot[2].y = col->GetWorldPos().y - (col->scale.y * 0.5f) + 15.0f;

		foot[3].x = col->GetWorldPos().x + 15.0f;
		foot[3].y = col->GetWorldPos().y - (col->scale.y * 0.5f) + 15.0f;

		return foot;
	}
};

