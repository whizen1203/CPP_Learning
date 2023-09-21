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
	//�߻� ��

	//Vector2 velocity = arrow.GetRight() * scalar + DOWN * gravity;
	arrow.MoveWorldPos(velocity * DELTA);

	// Normalize ����ȭ
	arrow.rotation = Utility::DirToRadian(velocity);
	//cout << scalar << endl;

	//scalar += 300.0f * DELTA;
	gravity += 300.0f * DELTA;

	arrow.Update();

	////������ �Ÿ���
	//Vector2 dir = arrow.GetWorldPos() - player.GetWorldPos();
	//float length = dir.Length();

	//if (length > 1000.0f)
	//{
	//	isFired = false;
	//}
}

//ȭ�� �����̰� �� ��
void Bullet::LateUpdate()
{
	if (!isFired) return;

	//�Ǽ� ��ȣ XXXX -> �ٻ簪. �ε��Ҽ��� ������
	//��
	if (arrow.GetWorldPos().y > app.GetHalfHeight() + CAM->position.y)
	{
		cout << "adsfwef" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		//�浹 ��ġ���� ����!!!!
		arrow.SetWorldPosY(app.GetHalfHeight() + CAM->position.y);
	}
	//�Ʒ�
	else if (arrow.GetWorldPos().y < -app.GetHalfHeight() + CAM->position.y)
	{
		//cout << "adsfwef" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		arrow.SetWorldPosY(-app.GetHalfHeight() + CAM->position.y);
	}
	//����
	else if (arrow.GetWorldPos().x <= -app.GetHalfWidth() + CAM->position.x)
	{
		//cout << "adsfwef" << endl;
		fireDir.x *= -1.0f;
		scalar *= 0.7f;

		arrow.SetWorldPosX(-app.GetHalfWidth() + CAM->position.x);
	}
	//������
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
