#include "stdafx.h"

Bullet::Bullet()
{
	missile = new ObLine;
	missile->SetWorldPos(Vector2(2000.0f, 2000.0f));
	missile->scale.x = 30.0f;
	missile->rotation = 0.0f;
	missile->isVisible = false;

	missilePet = new ObCircle;
	missilePet->SetParentRT(*missile);
	missilePet->SetLocalPos(Vector2(30.0f, 30.0f));
	missilePet->scale.x = 20.0f;
	missilePet->scale.y = 20.0f;
	missilePet->rotation = 0.0f;
	missilePet->color = Color(0.0f, 0.0f, 1.0f, 1.0f);
	missilePet->isVisible = false;
}

Bullet::~Bullet()
{
}

void Bullet::Update(ObRect player)
{
	if (!missilePet->isVisible) return;

	missilePet->revolution += 360.0f * ToRadian * DELTA;
	//cout << scalar << endl;

	Vector2 velocity = fireDir * scalar + DOWN * gravity;
	//Vector2 velocity = fireDir * scalar;
	missile->MoveWorldPos(velocity * DELTA);
	//scalar += 300.0f * DELTA;
	gravity += 300.0f * DELTA;
	missile->rotation = Utility::DirToRadian(velocity);

	missile->Update();
	missilePet->Update();

	//거리 비교 true -> false
	/*Vector2 dis = missile.GetWorldPos() - player.GetWorldPos();
	if (dis.Length() > 2000.0f)
	{
		missile.isVisible = false;
		missilePet.isVisible = false;
	}*/
}

void Bullet::LateUpdate()
{
	//위
	if (missile->GetWorldPos().y > app.GetHalfHeight() + CAM->position.y)
	{
		//cout << "111" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		//******** 충돌영역에서 빼주기 ********
		missile->SetWorldPosY(app.GetHalfHeight() + CAM->position.y);
	}
	//아래
	else if (missile->GetWorldPos().y < -app.GetHalfHeight() + CAM->position.y)
	{
		//cout << "444" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		missile->SetWorldPosY(-app.GetHalfHeight() + CAM->position.y);
	}
	//왼쪽
	else if (missile->GetWorldPos().x < -app.GetHalfWidth() + CAM->position.x)
	{
		//cout << "222" << endl;
		fireDir.x *= -1.0f;

		scalar *= 0.7f;

		missile->SetWorldPosX(-app.GetHalfWidth() + CAM->position.x);
	}
	//오른쪽
	else if (missile->GetWorldPos().x > app.GetHalfWidth() + CAM->position.x)
	{
		//cout << "333" << endl;
		fireDir.x *= -1.0f;

		scalar *= 0.7f;

		missile->SetWorldPosX(app.GetHalfWidth() + CAM->position.x);
	}
}

void Bullet::Render()
{
	missile->Render();
	missilePet->Render();
}

bool Bullet::Shoot(Vector2 fireDir, Vector2 firePos, float scalar)
{
	if (!missilePet->isVisible)
	{
		missile->isVisible = true;
		missilePet->isVisible = true;
		missile->SetWorldPos(firePos);
		missile->rotation = Utility::DirToRadian(fireDir);
		missilePet->revolution = 0.0f;
		this->fireDir = fireDir;
		gravity = 0.0f;

		//범위 
		this->scalar = scalar * 4.0f + 50.0f;
		//this->scalar = -500.0f;

		return true;
	}

	return false;
}
