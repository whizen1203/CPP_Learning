#pragma once
class ObLine; //전방선언

class GameObject
{
private:
	static ObLine* axis;

	Matrix S, R, T;
    Matrix* P;
    Matrix RT, R2;

    Vector2 position; //중점
    
    //자식한테만 공개
protected:
    Matrix W;

public:
    Vector2 scale; //크기
	float rotation;
	float revolution;
	bool isAxis;
	
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update();
	virtual void Render();

	static void CreateStatic();
	static void DeleteStatic();

    //getter setter
    Vector2 GetRight()
    {
        return Vector2(RT._11, RT._12);
    }
    Vector2 GetDown()
    {
        return Vector2(RT._21, RT._22);
    }

    Vector2 GetLocalPos()
    {
        return position;
    }
    Vector2 GetWorldPos()
    {
        if (!P)
        {
            return position;
        }

        return Vector2(RT._41, RT._42);
    }

    //이동시킬때 += Velocity 벡터
    void MoveLocalPos(Vector2 Velocity)
    {
        position += Velocity;
    }
    void MoveWorldPos(Vector2 Velocity)
    {
        if (!P)
        {
            position += Velocity;
        }
        else
        {
            Vector2 locVelocity = Vector2::TransformNormal(Velocity, (*P).Invert());
            position += locVelocity;
        }
    }
    //위치를 고정할때 = localpos 좌표
    void SetLocalPos(Vector2 localpos)
    {
        position = localpos;
    }
    void SetWorldPos(Vector2 worldPos)
    {
        if (!P)
        {
            position = worldPos;
        }
        else
        {
            Vector2 localpos = Vector2::Transform(worldPos, (*P).Invert());
            position = localpos;
        }
    }
    void SetParentRT(GameObject& src)
    {
        P = &src.RT;
    }
};

