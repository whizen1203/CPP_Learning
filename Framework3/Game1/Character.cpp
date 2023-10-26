#include "stdafx.h"

void Character::LookAtTarget(Vector2 target, ObImage* img)
{
	Vector2 velocity = target - col->GetWorldPos();
	float radian = Utility::DirToRadian(velocity);

	if (radian <= DIV8PI && radian > -DIV8PI)
	{
		dir = R;
	}
	else if (radian <= DIV8PI * 3.0f && radian > DIV8PI)
	{
		dir = RT;
	}
	else if (radian <= DIV8PI * 5.0f && radian > DIV8PI * 3.0f)
	{
		dir = T;
	}
	else if (radian <= DIV8PI * 7.0f && radian > DIV8PI * 5.0f)
	{
		dir = LT;
	}
	else if (radian > -DIV8PI * 7.0f && radian <= -DIV8PI * 5.0f)
	{
		dir = LB;
	}
	else if (radian > -DIV8PI * 5.0f && radian <= -DIV8PI * 3.0f)
	{
		dir = B;
	}
	else if (radian > -DIV8PI * 3.0f && radian <= -DIV8PI)
	{
		dir = RB;
	}
	else
	{
		dir = L;
	}

	img->frame.y = frameY[dir];
}