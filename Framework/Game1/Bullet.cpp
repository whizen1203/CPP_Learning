#include "stdafx.h"

Bullet::Bullet()
{
	arrow.SetWorldPos(Vector2(2000.0f, 2000.0f));
	arrow.scale = Vector2(50.0f, 0.0f);
	isFired = false;
	
}

Bullet::~Bullet()
{
}

void Bullet::Update(ObRect player)
{
	if (!isFired) return;

	Vector2 velocity = fireDir * scalar + DOWN * gravity;
	//Vector2 velocity = fireDir * scalar;
	//발사 중

	//Vector2 velocity = arrow.GetRight() * scalar + DOWN * gravity;
	arrow.MoveWorldPos(velocity * DELTA);

	// Normalize 정규화
	arrow.rotation = Utility::DirToRadian(velocity);
	//cout << scalar << endl;

	//scalar += 300.0f * DELTA;
	gravity += 300.0f * DELTA;

	arrow.Update();

	////재장전 거리비교
	//Vector2 dir = arrow.GetWorldPos() - player.GetWorldPos();
	//float length = dir.Length();

	//if (length > 1000.0f)
	//{
	//	isFired = false;
	//}
}

//화살 움직이고 난 후
void Bullet::LateUpdate()
{
	if (!isFired) return;

	//실수 등호 XXXX -> 근사값. 부동소수점 때문에
	//위
	if (arrow.GetWorldPos().y > app.GetHalfHeight() + CAM->position.y)
	{
		cout << "adsfwef" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		//충돌 위치에서 빼기!!!!
		arrow.SetWorldPosY(app.GetHalfHeight() + CAM->position.y);
	}
	//아래
	else if (arrow.GetWorldPos().y < -app.GetHalfHeight() + CAM->position.y)
	{
		//cout << "adsfwef" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		arrow.SetWorldPosY(-app.GetHalfHeight() + CAM->position.y);
	}
	//왼쪽
	else if (arrow.GetWorldPos().x <= -app.GetHalfWidth() + CAM->position.x)
	{
		//cout << "adsfwef" << endl;
		fireDir.x *= -1.0f;
		scalar *= 0.7f;

		arrow.SetWorldPosX(-app.GetHalfWidth() + CAM->position.x);
	}
	//오른쪽
	else if (arrow.GetWorldPos().x >= app.GetHalfWidth() + CAM->position.x)
	{
		//cout << "adsfwef" << endl;
		fireDir.x *= -1.0f;
		scalar *= 0.7f;

		arrow.SetWorldPosX(app.GetHalfWidth() + CAM->position.x);
	}
}

void Bullet::Render()
{
	if (!isFired) return;

	arrow.Render();
}

bool Bullet::Shoot(ObRect player, float gaugeScale, Vector2 pos)
{
	if (!isFired)
	{
		arrow.SetWorldPos(pos);
		arrow.rotation = Utility::DirToRadian(player.GetRight());
		fireDir = player.GetRight();
		gravity = 0.0f;
		isFired = true;

		// rand() 
		// 0 ~ 100 * 3 0 ~ 200 + 300 -> 200 ~ 500
		scalar = gaugeScale * 3.0f + 300.0f;
		//scalar = -gaugeScale * 5.0f;

		return true;
	}
	
	return false;
}
