#pragma once
enum class CState
{
	RUN,
	JUMP,
	SLIDE
};

class Cookie
{
public:
	ObRect*		col;	
	ObImage*	run;
	ObImage*	jump;
	ObImage*	slide;
	ObImage*	landing;

	CState		state;
	float		gravity;

	bool		doubleJump;

public:
	Cookie();
	~Cookie();
	void Update();
	void Render();
};

